#ifndef C_STORY_LISTENER_H
#define C_STORY_LISTENER_H

#include <zephyr/types.h>
#include <zephyr/kernel.h>

typedef void (*listener_callback)(void);

struct listener_listener {
	sys_snode_t node;
	listener_callback callback;
};

struct listener_ctx {
	sys_slist_t list;
	struct k_spinlock lock;
};

void listener_add_listener(struct listener_ctx *ctx, struct listener_listener *listener,
			   listener_callback callback) __attribute_nonnull(3);

void listener_publish(struct listener_ctx *ctx) __attribute_nonnull(1);

#endif /* C_STORY_LISTENER_H */
