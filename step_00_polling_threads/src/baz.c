#include <c_story/baz.h>
#include <c_story/bar.h>
#include <c_story/foo.h>
#include <zephyr/kernel.h>

static struct baz baz = {
	.b = 20,
	.a = 30,
	.z = 40,
};

static struct k_spinlock lock;

void baz_get_baz(struct baz *b)
{
	K_SPINLOCK(&lock) {
		*b = baz;
	}
}

static void baz_set_baz(const struct baz *b)
{
	K_SPINLOCK(&lock) {
		baz = *b;
	}
}

static void baz_routine(void)
{
	static struct bar bar_get_last;
	static struct bar bar_get;
	static struct baz baz_set;

	bar_get_bar(&bar_get_last);

	while (true) {
		bar_get_bar(&bar_get);

		if (bar_get.b != bar_get_last.b) {
			printk("baz detected bar.b change from %u to %u\n", bar_get_last.b, bar_get.b);
			printk("baz set baz.b to %u\n", bar_get.b);
			baz_set.b = bar_get.b;
			baz_set_baz(&baz_set);
		}

		bar_get_last = bar_get;
		k_msleep(10);
	}
}

K_THREAD_DEFINE(baz_thread, 512, baz_routine, NULL, NULL, NULL, 3, 0, 0);
