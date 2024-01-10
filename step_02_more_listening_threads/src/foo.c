#include <c_story/foo.h>
#include <c_story/qic.h>
#include <c_story/bar.h>
#include <c_story/baz.h>
#include <zephyr/kernel.h>

#define FOO_EVENT_BAR_SET_BIT BIT(0)
#define FOO_EVENT_QIC_SET_BIT BIT(1)

static struct foo foo = {
	.f = 10,
	.oo = 20,
};

static struct k_spinlock lock;
static struct k_event event;

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
	k_event_post(&event, FOO_EVENT_BAR_SET_BIT);
}

static void on_qic_set(void)
{
	k_event_post(&event, FOO_EVENT_QIC_SET_BIT);
}

static void foo_routine(void)
{
	static struct bar bar_get_last;
	static struct bar bar_get;
	static struct qic qic_get_last;
	static struct qic qic_get;
	static struct foo foo_set;
	static struct bar_listener bar_listener;
	static struct qic_listener qic_listener;
	uint32_t events;

	k_event_init(&event);
	bar_get_bar(&bar_get_last);
	qic_get_qic(&qic_get_last);
	bar_add_callback(&bar_listener, on_bar_set);
	qic_add_callback(&qic_listener, on_qic_set);

	while (true) {
		events = k_event_wait(&event, UINT32_MAX, true, K_FOREVER);
		if (events & FOO_EVENT_BAR_SET_BIT) {
			bar_get_bar(&bar_get);
			if (bar_get.b != bar_get_last.b) {
				printk("foo detected bar.b change from %u to %u\n", bar_get_last.b, bar_get.b);
				printk("foo set foo.f to %u\n", bar_get.b);
				foo_set.f = bar_get.b;
				foo_set_foo(&foo_set);
			}
		}
		if (events & FOO_EVENT_QIC_SET_BIT) {
			qic_get_qic(&qic_get);
			if (qic_get.q != qic_get_last.q) {
				printk("foo detected qic.q change from %u to %u\n", qic_get_last.q, qic_get.q);
				printk("foo set foo.oo to %u\n", qic_get.q);
				foo_set.oo = qic_get.q;
				foo_set_foo(&foo_set);
			}
		}
	}
}

K_THREAD_DEFINE(foo_thread, 512, foo_routine, NULL, NULL, NULL, 3, 0, 0);
