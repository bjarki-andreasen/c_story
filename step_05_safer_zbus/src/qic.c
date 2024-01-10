#include <c_story/qic.h>
#include <zephyr/kernel.h>

static bool qic_chan_validator(const void *msg, size_t msg_size)
{
	const struct qic *q = msg;
	static struct qic last_q;

	if (msg_size != sizeof(struct qic)) {
		return false;
	}

	if (memcmp(q, &last_q, sizeof(struct qic)) == 0) {
		return false;
	}

	last_q = *q;
	return true;
}

ZBUS_CHAN_DEFINE(
	qic_chan,
	struct qic,
	qic_chan_validator,
	NULL,
	ZBUS_OBSERVERS_EMPTY,
	ZBUS_MSG_INIT()
);

static void qic_routine(void)
{
	static struct qic msg;

	while (true) {
		qic_chan_read(&msg, K_FOREVER);
		msg.q++;
		printk("qic set qic.q to %u\n", msg.q);
		qic_chan_pub(&msg, K_FOREVER);
		k_msleep(1000);
	}
}

K_THREAD_DEFINE(qic_thread, 512, qic_routine, NULL, NULL, NULL, 3, 0, 0);
