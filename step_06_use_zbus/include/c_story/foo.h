#ifndef C_STORY_FOO_H
#define C_STORY_FOO_H

#include <zephyr/types.h>
#include <zephyr/zbus/zbus.h>

struct foo {
	uint32_t f;
	uint32_t oo;
};

ZBUS_CHAN_DECLARE(foo_chan);

#endif /* C_STORY_FOO_H */
