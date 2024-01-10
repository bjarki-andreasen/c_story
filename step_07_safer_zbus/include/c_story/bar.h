#ifndef C_STORY_BAR_H
#define C_STORY_BAR_H

#include <zephyr/types.h>
#include <zephyr/zbus/zbus.h>

struct bar {
	uint32_t b;
	uint32_t a;
	uint32_t r;
};

ZBUS_CHAN_DECLARE(bar_chan);

static inline int bar_chan_pub(const struct bar *b, k_timeout_t timeout)
{
	return zbus_chan_pub(&bar_chan, b, timeout);
}

static inline int bar_chan_read(struct bar *b, k_timeout_t timeout)
{
	return zbus_chan_read(&bar_chan, b, timeout);
}

static inline int bar_is_bar_chan(const struct zbus_channel *chan)
{
	return chan == &bar_chan;
}

#endif /* C_STORY_BAR_H */
