#ifndef C_STORY_QIC_H
#define C_STORY_QIC_H

#include <zephyr/types.h>
#include <zephyr/zbus/zbus.h>

struct qic {
	uint32_t q;
	uint32_t i;
	uint32_t c;
};

ZBUS_CHAN_DECLARE(qic_chan);

static inline int qic_chan_pub(const struct qic *b, k_timeout_t timeout)
{
	return zbus_chan_pub(&qic_chan, b, timeout);
}

static inline int qic_chan_read(struct qic *b, k_timeout_t timeout)
{
	return zbus_chan_read(&qic_chan, b, timeout);
}

static inline int qic_is_qic_chan(const struct zbus_channel *chan)
{
	return chan == &qic_chan;
}

#endif /* C_STORY_QIC_H */
