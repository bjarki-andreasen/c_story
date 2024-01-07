#include <zephyr/kernel.h>
#include <c_story/foo.h>
#include <c_story/bar.h>
#include <c_story/baz.h>

static struct foo foo;
static struct bar bar;
static struct baz baz;

void on_foo_set(const struct foo *f)
{

}

void on_bar_get()
{

}

int main(void)
{
	foo_add_on_set_listener(on_foo_set);
	bar_add_on_get_listener(on_bar_get);

	foo = foo_get_foo();
	foo_set_foo(foo);

	bar = bar_get_bar();
	bar_set_bar(bar);

	baz = baz_get_baz();
	baz_set_baz(baz);
}

/* Less copy paste, but typecasting is getting dangerous
 * (void (*)(const void *)) allows on_foo_set(struct foo f)
 * protected by foo_add_on_set_listener() one layer up
 */
