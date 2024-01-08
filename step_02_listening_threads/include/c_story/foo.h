#ifndef C_STORY_FOO_H
#define C_STORY_FOO_H

#include <zephyr/types.h>
#include <zephyr/toolchain.h>

struct foo {
	uint32_t f;
	uint32_t oo;
};

void foo_get_foo(struct foo *f) __attribute_nonnull(1);

#endif /* C_STORY_FOO_H */
