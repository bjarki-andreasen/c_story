#ifndef C_STORY_BAZ_H
#define C_STORY_BAZ_H

#include <zephyr/types.h>
#include <zephyr/toolchain.h>

struct baz {
	uint8_t b;
	uint8_t a;
	uint8_t z;
};

struct baz baz_get_baz(void);
void baz_set_baz(const struct baz b);

typedef void (*baz_on_set_listener)(struct baz b);
void baz_add_on_set_listener(baz_on_set_listener listener) __attribute_nonnull(1);

typedef void (*baz_on_get_listener)(void);
void baz_add_on_get_listener(baz_on_get_listener listener) __attribute_nonnull(1);

#endif /* C_STORY_BAZ_H */
