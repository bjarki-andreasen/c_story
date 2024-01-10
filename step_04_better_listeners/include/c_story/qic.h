#ifndef C_STORY_QIC_H
#define C_STORY_QIC_H

#include <zephyr/types.h>
#include <zephyr/toolchain.h>
#include <zephyr/kernel.h>
#include <c_story/listener.h>

struct qic {
	uint32_t q;
	uint32_t i;
	uint32_t c;
};

void qic_get_qic(struct qic *b) __attribute_nonnull(1);
void qic_add_callback(struct listener_listener *listener, listener_callback cb) __attribute_nonnull(2);

#endif /* C_STORY_QIC_H */
