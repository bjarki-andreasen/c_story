#include <c_story/bar.h>

static struct bar bar = {
	.b = 10,
	.a = 20,
	.r = 30,
};

static struct foo foo;
static struct baz baz;

struct bar bar_get_bar(void)
{
	return bar;
}

void bar_set_bar(struct bar b)
{
	bar = b;

	foo_on_bar_set(bar);
	baz_on_bar_set(bar);
}

void bar_on_foo_set(struct foo f)
{
	foo = f;
}

void bar_on_baz_set(struct baz b)
{
	baz = b;
}
