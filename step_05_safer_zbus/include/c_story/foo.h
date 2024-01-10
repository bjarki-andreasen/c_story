#ifndef C_STORY_FOO_H
#define C_STORY_FOO_H

#include <zephyr/types.h>
#include <zephyr/zbus/zbus.h>

struct foo {
	uint32_t f;
	uint32_t oo;
};

ZBUS_CHAN_DECLARE(foo_chan);

static inline int foo_chan_pub(const struct foo *b, k_timeout_t timeout)
{
	return zbus_chan_pub(&foo_chan, b, timeout);
}

static inline int foo_chan_read(struct foo *b, k_timeout_t timeout)
{
	return zbus_chan_read(&foo_chan, b, timeout);
}

static inline int foo_is_foo_chan(const struct zbus_channel *chan)
{
	return chan == &foo_chan;
}

#endif /* C_STORY_FOO_H */
