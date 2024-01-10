#include <c_story/foo.h>
#include <c_story/bar.h>
#include <c_story/baz.h>
#include <zephyr/kernel.h>

static struct foo foo = {
	.f = 10,
	.oo = 20,
};

static struct k_spinlock lock;

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

static void foo_routine(void)
{
	static struct bar bar_get_last;
	static struct bar bar_get;
	static struct foo foo_set;

	bar_get_bar(&bar_get_last);

	while (true) {
		bar_get_bar(&bar_get);

		if (bar_get.b != bar_get_last.b) {
			printk("foo detected bar.b change from %u to %u\n", bar_get_last.b, bar_get.b);
			printk("foo set foo.f to %u\n", bar_get.b);
			foo_set.f = bar_get.b;
			foo_set_foo(&foo_set);
		}

		bar_get_last = bar_get;
		k_msleep(10);
	}
}

K_THREAD_DEFINE(foo_thread, 512, foo_routine, NULL, NULL, NULL, 3, 0, 0);
