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

#endif /* C_STORY_QIC_H */
