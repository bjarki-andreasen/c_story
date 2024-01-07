#include <c_story/foo.h>

static struct foo foo = {
	.f = 10,
	.oo = 20,
};

void foo_get_foo(struct foo *f)
{
	*f = foo;
}

void foo_set_foo(const struct foo *f)
{
	foo = *f;
}
