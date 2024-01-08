#ifndef C_STORY_QIC_H
#define C_STORY_QIC_H

#include <zephyr/types.h>
#include <zephyr/toolchain.h>
#include <zephyr/kernel.h>

struct qic {
	uint32_t q;
	uint32_t i;
	uint32_t c;
};

typedef void (*qic_callback)(void);

struct qic_listener {
	sys_snode_t node;
	qic_callback cb;
};

void qic_get_qic(struct qic *b) __attribute_nonnull(1);
void qic_add_callback(struct qic_listener *listener, qic_callback cb) __attribute_nonnull(2);

#endif /* C_STORY_QIC_H */
