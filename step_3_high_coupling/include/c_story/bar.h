#ifndef C_STORY_BAR_H
#define C_STORY_BAR_H

#include <c_story/types.h>
#include <c_story/foo.h>
#include <c_story/baz.h>

struct bar bar_get_bar(void);
void bar_set_bar(struct bar b);

void bar_on_foo_set(struct foo f);
void bar_on_baz_set(struct baz b);

#endif /* C_STORY_BAR_H */
