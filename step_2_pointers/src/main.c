#include <zephyr/kernel.h>
#include <c_story/foo.h>
#include <c_story/bar.h>
#include <c_story/baz.h>

static struct foo foo;
static struct bar bar;
static struct baz baz;

int main(void)
{
	foo_get_foo(&foo);
	foo_set_foo(&foo);

	bar_get_bar(&bar);
	bar_get_bar(&bar);

	baz_get_baz(&baz);
	baz_get_baz(&baz);
}

/*
 * This code is "efficient" (if the structures where larger), but can be broken
 * - get/set can be confused
 * - types can be incorrect (produces warning)
 * - pointers can be NULL (no warning unless nonnull attribute is used)
 */

/*
 * Will detect missing modules
 */
