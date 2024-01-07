#include <c_story/baz.h>

static struct baz baz = {
	.b = 20,
	.a = 30,
	.z = 40,
};

static struct foo foo;
static struct bar bar;

struct baz baz_get_baz(void)
{
	return baz;
}

void baz_set_baz(struct baz b)
{
	baz = b;

	bar_on_baz_set(baz);
	foo_on_baz_set(baz);
}

void baz_on_foo_set(struct foo b)
{
	foo = b;
}

void baz_on_bar_set(struct bar b)
{
	bar = b;
}
