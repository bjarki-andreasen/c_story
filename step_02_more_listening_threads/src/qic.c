#include <c_story/qic.h>
#include <c_story/foo.h>
#include <c_story/baz.h>
#include <zephyr/kernel.h>

static struct qic qic;

static struct k_spinlock b_lock;
static struct k_spinlock l_lock;
static sys_slist_t listener_list;

void qic_get_qic(struct qic *b)
{
	K_SPINLOCK(&b_lock) {
		*b = qic;
	}
}

void qic_add_callback(struct qic_listener *listener, qic_callback cb)
{
	listener->cb = cb;
	sys_slist_append(&listener_list, &listener->node);
}

static void qic_set_qic(const struct qic *b)
{
	sys_snode_t *node;
	struct qic_listener *listener;
	qic_callback cb;

	K_SPINLOCK(&b_lock) {
		qic = *b;
	}

	K_SPINLOCK(&l_lock) {
		SYS_SLIST_FOR_EACH_NODE(&listener_list, node) {
			listener = CONTAINER_OF(node, struct qic_listener, node);
			cb = listener->cb;
			cb();
		}
	}
}

static void qic_routine(void)
{
	static struct qic qic_set;

	while (true) {
		qic_set.q++;
		printk("qic set qic.b to %u\n", qic_set.q);
		qic_set_qic(&qic_set);
		k_msleep(500);
	}
}

K_THREAD_DEFINE(qic_thread, 512, qic_routine, NULL, NULL, NULL, 3, 0, 0);
