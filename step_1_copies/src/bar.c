#include <c_story/bar.h>

static struct bar bar = {
	.b = 10,
	.a = 20,
	.r = 30,
};

struct bar bar_get_bar(void)
{
	return bar;
}

void bar_set_bar(struct bar b)
{
	bar = b;
}
