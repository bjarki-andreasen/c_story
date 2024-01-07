#include <c_story/listener_arg.h>

void listener_arg_add_listener(struct listener_arg_ctx *ctx, listener_arg_listener listener)
{
	for (size_t i = 0; i < ctx->listeners_size; i++) {
		if (ctx->listeners[i] == NULL) {
			ctx->listeners[i] = listener;
			break;
		}
	}
}

void listener_arg_publish(struct listener_arg_ctx *ctx, const void *arg)
{
	for (size_t i = 0; i < ctx->listeners_size; i++) {
		if (ctx->listeners[i] == NULL) {
			break;
		}

		ctx->listeners[i](arg);
	}
}
