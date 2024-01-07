#include <c_story/bar.h>

static struct bar bar = {
	.b = 10,
	.a = 20,
	.r = 30,
};

void bar_get_bar(struct bar *b)
{
	*b = bar;
}

void bar_set_bar(const struct bar *b)
{
	bar = *b;
}
