#ifndef C_STORY_BAZ_H
#define C_STORY_BAZ_H

#include <zephyr/types.h>
#include <zephyr/zbus/zbus.h>

struct baz {
	uint8_t b;
	uint8_t a;
	uint8_t z;
};

ZBUS_CHAN_DECLARE(baz_chan);

static inline int baz_chan_pub(const struct baz *b, k_timeout_t timeout)
{
	return zbus_chan_pub(&baz_chan, b, timeout);
}

static inline int baz_chan_read(struct baz *b, k_timeout_t timeout)
{
	return zbus_chan_read(&baz_chan, b, timeout);
}

static inline int baz_is_baz_chan(const struct zbus_channel *chan)
{
	return chan == &baz_chan;
}

#endif /* C_STORY_BAZ_H */
