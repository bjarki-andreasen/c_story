#include <c_story/bar.h>
#include <zephyr/kernel.h>

static bool bar_chan_validator(const void *msg, size_t msg_size)
{
	const struct bar *b = msg;
	static struct bar last_b;

	if (msg_size != sizeof(struct bar)) {
		return false;
	}

	if (memcmp(b, &last_b, sizeof(struct bar)) == 0) {
		return false;
	}

	last_b = *b;
	return true;
}

ZBUS_CHAN_DEFINE(
	bar_chan,
	struct bar,
	bar_chan_validator,
	NULL,
	ZBUS_OBSERVERS_EMPTY,
	ZBUS_MSG_INIT()
);

static void bar_routine(void)
{
	static struct bar msg;

	while (true) {
		bar_chan_read(&msg, K_FOREVER);
		msg.b++;
		printk("bar set bar.b to %u\n", msg.b);
		bar_chan_pub(&msg, K_FOREVER);
		k_msleep(1000);
	}
}

K_THREAD_DEFINE(bar_thread, 512, bar_routine, NULL, NULL, NULL, 3, 0, 0);
