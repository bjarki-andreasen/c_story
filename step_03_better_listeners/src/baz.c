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
static struct k_sem bar_set_sem;

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

static void on_bar_set(void)
{
	k_sem_give(&bar_set_sem);
}

static void baz_routine(void)
{
	static struct bar bar_get_last;
	static struct bar bar_get;
	static struct baz baz_set;
	static struct listener_listener bar_listener;

	bar_get_bar(&bar_get_last);
	k_sem_init(&bar_set_sem, 0, 1);
	bar_add_callback(&bar_listener, on_bar_set);

	while (true) {
		k_sem_take(&bar_set_sem, K_FOREVER);
		bar_get_bar(&bar_get);
		if (bar_get.b != bar_get_last.b) {
			printk("baz detected bar.b change from %u to %u\n", bar_get_last.b, bar_get.b);
			printk("baz set baz.b to %u\n", bar_get.b);
			baz_set.b = bar_get.b;
			baz_set_baz(&baz_set);
		}
	}
}

K_THREAD_DEFINE(baz_thread, 512, baz_routine, NULL, NULL, NULL, 3, 0, 0);
