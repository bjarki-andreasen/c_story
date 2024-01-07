#ifndef C_STORY_BAZ_H
#define C_STORY_BAZ_H

#include <zephyr/types.h>

struct baz {
	uint8_t b;
	uint8_t a;
	uint8_t z;
};

struct baz baz_get_baz(void);
void baz_set_baz(struct baz b);

#endif /* C_STORY_BAZ_H */
