#ifndef C_STORY_LISTENER_H
#define C_STORY_LISTENER_H

#include <zephyr/types.h>

typedef void (*listener_listener)(void);

struct listener_ctx {
	listener_listener *listeners;
	size_t listeners_size;
};

#define LISTENER_LISTENERS_DEFINE(_name, _n)			\
	static listener_listener _name##listeners[_n];		\
	static struct listener_ctx _name = {			\
		.listeners = _name##listeners,			\
		.listeners_size = _n,				\
	}

void listener_add_listener(struct listener_ctx *ctx, listener_listener listener);
void listener_publish(struct listener_ctx *ctx);

#endif /* C_STORY_LISTENER_H */
