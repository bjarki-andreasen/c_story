#ifndef C_STORY_BAZ_H
#define C_STORY_BAZ_H

#include <zephyr/types.h>
#include <zephyr/toolchain.h>

struct baz {
	uint8_t b;
	uint8_t a;
	uint8_t z;
};

void baz_get_baz(struct baz *b) __attribute_nonnull(1);

#endif /* C_STORY_BAZ_H */
