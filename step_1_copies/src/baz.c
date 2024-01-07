#include <c_story/baz.h>

static struct baz baz = {
	.b = 20,
	.a = 30,
	.z = 40,
};

struct baz baz_get_baz(void)
{
	return baz;
}

void baz_set_baz(struct baz b)
{
	baz = b;
}
