#include <c_story/baz.h>
#include <c_story/bar.h>
#include <zephyr/kernel.h>

ZBUS_CHAN_DEFINE(
	baz_chan,
	struct baz,
	NULL,
	NULL,
	ZBUS_OBSERVERS_EMPTY,
	ZBUS_MSG_INIT(
		.b = 20,
		.a = 30,
		.z = 40,
	)
);

ZBUS_SUBSCRIBER_DEFINE(baz_sub, 4);
ZBUS_CHAN_ADD_OBS(bar_chan, baz_sub, 3);

static void baz_routine(void)
{
	const struct zbus_channel *chan;
	static struct bar bar_get;
	static struct baz baz_set;

	while (zbus_sub_wait(&baz_sub, &chan, K_FOREVER) == 0) {
		if (bar_is_bar_chan(chan)) {
			bar_chan_read(&bar_get, K_FOREVER);
			printk("baz set baz.b to %u\n", bar_get.b);
			baz_set.b = bar_get.b;
			baz_chan_pub(&baz_set, K_FOREVER);
		}
	}
}

K_THREAD_DEFINE(baz_thread, 512, baz_routine, NULL, NULL, NULL, 3, 0, 0);
