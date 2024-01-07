#ifndef C_STORY_BAR_H
#define C_STORY_BAR_H

#include <zephyr/types.h>
#include <zephyr/toolchain.h>

struct bar {
	uint32_t b;
	uint32_t a;
	uint32_t r;
};

struct bar bar_get_bar(void);
void bar_set_bar(struct bar b);

typedef void (*bar_on_set_listener)(const struct bar *b);
void bar_add_on_set_listener(bar_on_set_listener listener) __attribute_nonnull(1);

typedef void (*bar_on_get_listener)(void);
void bar_add_on_get_listener(bar_on_get_listener listener) __attribute_nonnull(1);

#endif /* C_STORY_BAR_H */
