#include <c_story/listener.h>

void listener_add_listener(struct listener_ctx *ctx, struct listener_listener *listener,
			   listener_callback callback)
{
	listener->callback = callback;

	K_SPINLOCK(&ctx->lock) {
		sys_slist_append(&ctx->list, &listener->node);
	}
}

void listener_publish(struct listener_ctx *ctx)
{
	sys_snode_t *node;

	K_SPINLOCK(&ctx->lock) {
		SYS_SLIST_FOR_EACH_NODE(&ctx->list, node) {
			struct listener_listener *listener =
				CONTAINER_OF(node, struct listener_listener, node);

			listener->callback();
		}
	}
}
