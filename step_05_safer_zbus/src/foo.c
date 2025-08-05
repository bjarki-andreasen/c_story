#include <c_story/foo.h>
#include <c_story/qic.h>
#include <c_story/bar.h>
#include <c_story/baz.h>
#include <zephyr/kernel.h>

ZBUS_CHAN_DEFINE(
	foo_chan,
	struct foo,
	NULL,
	NULL,
	ZBUS_OBSERVERS_EMPTY,
	ZBUS_MSG_INIT(
		.f = 10,
		.oo = 20,
	)
);

ZBUS_SUBSCRIBER_DEFINE(foo_sub, 4);
ZBUS_CHAN_ADD_OBS(bar_chan, foo_sub, 4);
ZBUS_CHAN_ADD_OBS(qic_chan, foo_sub, 4);

static void foo_routine(void)
{
	static const struct zbus_channel *chan;
	static struct bar bar_get;
	static struct qic qic_get;
	static struct foo foo_set;

	while (zbus_sub_wait(&foo_sub, &chan, K_FOREVER) == 0) {
		if (bar_is_bar_chan(chan)) {
			bar_chan_read(&bar_get, K_FOREVER);
			printk("foo set foo.f to %u\n", bar_get.b);
			foo_set.f = bar_get.b;
			foo_chan_pub(&foo_set, K_FOREVER);
		}
		if (qic_is_qic_chan(chan)) {
			qic_chan_read(&qic_get, K_FOREVER);
			printk("foo set foo.f to %u\n", qic_get.q);
			foo_set.f = qic_get.q;
			foo_chan_pub(&foo_set, K_FOREVER);
		}
	}
}

K_THREAD_DEFINE(foo_thread, 512, foo_routine, NULL, NULL, NULL, 3, 0, 0);
