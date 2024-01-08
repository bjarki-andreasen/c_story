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

#endif /* C_STORY_BAR_H */
