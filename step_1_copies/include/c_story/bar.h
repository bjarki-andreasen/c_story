#ifndef C_STORY_BAR_H
#define C_STORY_BAR_H

#include <zephyr/types.h>

struct bar {
	uint32_t b;
	uint32_t a;
	uint32_t r;
};

struct bar bar_get_bar(void);
void bar_set_bar(struct bar b);

#endif /* C_STORY_BAR_H */
