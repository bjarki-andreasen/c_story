#include <c_story/bar.h>
#include <c_story/foo.h>
#include <c_story/baz.h>
#include <zephyr/kernel.h>

static struct bar bar;

static struct k_spinlock b_lock;
static struct k_spinlock l_lock;
static sys_slist_t listener_list;

void bar_get_bar(struct bar *b)
{
	K_SPINLOCK(&b_lock) {
		*b = bar;
	}
}

void bar_add_callback(struct bar_listener *listener, bar_callback cb)
{
	listener->cb = cb;
	sys_slist_append(&listener_list, &listener->node);
}

static void bar_set_bar(const struct bar *b)
{
	sys_snode_t *node;
	struct bar_listener *listener;
	bar_callback cb;

	K_SPINLOCK(&b_lock) {
		bar = *b;
	}

	K_SPINLOCK(&l_lock) {
		SYS_SLIST_FOR_EACH_NODE(&listener_list, node) {
			listener = CONTAINER_OF(node, struct bar_listener, node);
			cb = listener->cb;
			cb();
		}
	}
}

static void bar_routine(void)
{
	static struct bar bar_set;

	while (true) {
		bar_set.b++;
		printk("bar set bar.b to %u\n", bar_set.b);
		bar_set_bar(&bar_set);
		k_msleep(1000);
	}
}

K_THREAD_DEFINE(bar_thread, 512, bar_routine, NULL, NULL, NULL, 3, 0, 0);
