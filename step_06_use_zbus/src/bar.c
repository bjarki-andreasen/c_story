#include <c_story/bar.h>
#include <zephyr/kernel.h>

ZBUS_CHAN_DEFINE(
	bar_chan,
	struct bar,
	NULL,
	NULL,
	ZBUS_OBSERVERS_EMPTY,
	ZBUS_MSG_INIT()
);

static void bar_routine(void)
{
	static struct bar msg;

	while (true) {
		zbus_chan_read(&bar_chan, &msg, K_FOREVER);
		msg.b++;
		printk("bar set bar.b to %u\n", msg.b);
		zbus_chan_pub(&bar_chan, &msg, K_FOREVER);
		k_msleep(1000);
	}
}

K_THREAD_DEFINE(bar_thread, 512, bar_routine, NULL, NULL, NULL, 3, 0, 0);
