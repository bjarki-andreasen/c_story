#ifndef C_STORY_LISTENER_ARG_H
#define C_STORY_LISTENER_ARG_H

#include <zephyr/types.h>

typedef void (*listener_arg_listener)(const void *arg);

struct listener_arg_ctx {
	listener_arg_listener *listeners;
	size_t listeners_size;
};

#define LISTENER_ARG_LISTENERS_DEFINE(_name, _n)		\
	static listener_arg_listener _name##listeners[_n];	\
	static struct listener_arg_ctx _name = {		\
		.listeners = _name##listeners,			\
		.listeners_size = _n,				\
	}

void listener_arg_add_listener(struct listener_arg_ctx *ctx, listener_arg_listener listener);
void listener_arg_publish(struct listener_arg_ctx *ctx, const void *arg);

#endif /* C_STORY_LISTENER_ARG_H */
