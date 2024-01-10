#ifndef C_STORY_BAZ_H
#define C_STORY_BAZ_H

#include <zephyr/types.h>
#include <zephyr/zbus/zbus.h>

struct baz {
	uint8_t b;
	uint8_t a;
	uint8_t z;
};

ZBUS_CHAN_DECLARE(bar_chan);

#endif /* C_STORY_BAZ_H */
