#include <c_story/baz.h>

static struct baz baz = {
	.b = 20,
	.a = 30,
	.z = 40,
};

void baz_get_baz(struct baz *b)
{
	*b = baz;
}

void baz_set_baz(const struct baz *b)
{
	baz = *b;
}
