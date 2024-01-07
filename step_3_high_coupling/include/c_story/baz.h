#ifndef C_STORY_BAZ_H
#define C_STORY_BAZ_H

#include <c_story/types.h>
#include <c_story/foo.h>
#include <c_story/bar.h>

struct baz baz_get_baz(void);
void baz_set_baz(const struct baz b);

void baz_on_foo_set(struct foo f);
void baz_on_bar_set(struct bar b);

#endif /* C_STORY_BAZ_H */
