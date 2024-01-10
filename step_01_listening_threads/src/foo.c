#include <c_story/foo.h>
#include <c_story/bar.h>
#include <c_story/baz.h>
#include <zephyr/kernel.h>

static struct foo foo = {
	.f = 10,
	.oo = 20,
};

static struct k_spinlock lock;
static struct k_sem bar_set_sem;

void foo_get_foo(struct foo *f)
{
	K_SPINLOCK(&lock) {
		*f = foo;
	}
}

static void foo_set_foo(const struct foo *f)
{
	K_SPINLOCK(&lock) {
		foo = *f;
	}
}

static void on_bar_set(void)
{
	k_sem_give(&bar_set_sem);
}

static void foo_routine(void)
{
	static struct bar bar_get_last;
	static struct bar bar_get;
	static struct foo foo_set;
	static struct bar_listener bar_listener;

	bar_get_bar(&bar_get_last);
	k_sem_init(&bar_set_sem, 0, 1);
	bar_add_callback(&bar_listener, on_bar_set);

	while (true) {
		k_sem_take(&bar_set_sem, K_FOREVER);
		bar_get_bar(&bar_get);
		if (bar_get.b != bar_get_last.b) {
			printk("foo detected bar.b change from %u to %u\n", bar_get_last.b, bar_get.b);
			printk("foo set foo.f to %u\n", bar_get.b);
			foo_set.f = bar_get.b;
			foo_set_foo(&foo_set);
		}
	}
}

K_THREAD_DEFINE(foo_thread, 512, foo_routine, NULL, NULL, NULL, 3, 0, 0);
