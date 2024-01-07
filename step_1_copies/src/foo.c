#include <c_story/foo.h>

static struct foo foo = {
	.f = 10,
	.oo = 20,
};

struct foo foo_get_foo(void)
{
	return foo;
}

void foo_set_foo(struct foo f)
{
	foo = f;
}
