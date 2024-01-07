#include <c_story/listener.h>

void listener_add_listener(struct listener_ctx *ctx, listener_listener listener)
{
	for (size_t i = 0; i < ctx->listeners_size; i++) {
		if (ctx->listeners[i] == NULL) {
			ctx->listeners[i] = listener;
			break;
		}
	}
}

void listener_publish(struct listener_ctx *ctx)
{
	for (size_t i = 0; i < ctx->listeners_size; i++) {
		if (ctx->listeners[i] == NULL) {
			break;
		}

		ctx->listeners[i]();
	}
}

void listener_arg_publish(struct listener_ctx *ctx, const void *arg)
{
	for (size_t i = 0; i < ctx->listeners_size; i++) {
		if (ctx->listeners[i] == NULL) {
			break;
		}

		((void (*)(const void *))ctx->listeners[i])(arg);
	}
}
