#ifndef C_STORY_FOO_H
#define C_STORY_FOO_H

#include <zephyr/types.h>
#include <zephyr/toolchain.h>

struct foo {
	uint32_t f;
	uint32_t oo;
};

struct foo foo_get_foo(void);
void foo_set_foo(const struct foo b);

typedef void (*foo_on_set_listener)(const struct foo *b);
void foo_add_on_set_listener(foo_on_set_listener listener) __attribute_nonnull(1);

typedef void (*foo_on_get_listener)(void);
void foo_add_on_get_listener(foo_on_get_listener listener) __attribute_nonnull(1);

#endif /* C_STORY_FOO_H */
