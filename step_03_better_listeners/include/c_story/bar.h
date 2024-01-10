#ifndef C_STORY_BAR_H
#define C_STORY_BAR_H

#include <zephyr/types.h>
#include <zephyr/toolchain.h>
#include <zephyr/kernel.h>
#include <c_story/listener.h>

struct bar {
	uint32_t b;
	uint32_t a;
	uint32_t r;
};

void bar_get_bar(struct bar *b) __attribute_nonnull(1);
void bar_add_callback(struct listener_listener *listener, listener_callback cb) __attribute_nonnull(2);

#endif /* C_STORY_BAR_H */
