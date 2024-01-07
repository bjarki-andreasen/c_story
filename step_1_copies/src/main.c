#include <zephyr/kernel.h>
#include <c_story/foo.h>
#include <c_story/bar.h>
#include <c_story/baz.h>

static struct foo foo;
static struct bar bar;
static struct baz baz;

int main(void)
{
	foo = foo_get_foo();
	foo_set_foo(foo);

	bar = bar_get_bar();
	bar_set_bar(bar);

	baz = baz_get_baz();
	baz_set_baz(baz);
}

/* This code is inefficient, but unbreakable */
