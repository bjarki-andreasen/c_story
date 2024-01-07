#include <c_story/foo.h>

static struct foo foo = {
	.f = 10,
	.oo = 20,
};

static struct baz baz;
static struct bar bar;

struct foo foo_get_foo(void)
{
	return foo;
}

void foo_set_foo(struct foo f)
{
	foo = f;

	bar_on_baz_set(baz);
	foo_on_baz_set(baz);
}

void foo_on_baz_set(struct baz b)
{
	baz = b;
}

void foo_on_bar_set(struct bar b)
{
	bar = b;
}
