#ifndef C_STORY_FOO_H
#define C_STORY_FOO_H

#include <zephyr/types.h>

struct foo {
	uint32_t f;
	uint32_t oo;
};

struct foo foo_get_foo(void);
void foo_set_foo(struct foo b);

#endif /* C_STORY_FOO_H */
