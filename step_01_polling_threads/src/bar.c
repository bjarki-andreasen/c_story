#include <c_story/bar.h>
#include <c_story/foo.h>
#include <c_story/baz.h>
#include <zephyr/kernel.h>

static struct bar bar;

static struct k_spinlock lock;

void bar_get_bar(struct bar *b)
{
	K_SPINLOCK(&lock) {
		*b = bar;
	}
}

static void bar_set_bar(const struct bar *b)
{
	K_SPINLOCK(&lock) {
		bar = *b;
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
