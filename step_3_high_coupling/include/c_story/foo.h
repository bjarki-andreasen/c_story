#ifndef C_STORY_FOO_H
#define C_STORY_FOO_H

#include <c_story/types.h>
#include <c_story/bar.h>
#include <c_story/baz.h>

struct foo foo_get_foo(void);
void foo_set_foo(const struct foo b);

void foo_on_baz_set(struct baz b);
void foo_on_bar_set(struct bar b);

#endif /* C_STORY_FOO_H */
