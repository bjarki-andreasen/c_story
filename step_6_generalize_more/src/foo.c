#include <c_story/foo.h>
#include <c_story/foo.h>
#include <c_story/bar.h>
#include <c_story/listener.h>

#define FOO_N_LISTENERS (3)

static struct foo foo = {
	.f = 10,
	.oo = 20,
};

LISTENER_LISTENERS_DEFINE(foo_get_listeners, FOO_N_LISTENERS);
LISTENER_LISTENERS_DEFINE(foo_set_listeners, FOO_N_LISTENERS);

struct foo foo_get_foo(void)
{
	listener_publish(&foo_get_listeners);

	return foo;
}

void foo_set_foo(struct foo b)
{
	foo = b;

	listener_arg_publish(&foo_set_listeners, &foo);
}

void foo_add_on_set_listener(foo_on_set_listener listener)
{
	listener_add_listener(&foo_set_listeners, (listener_listener)listener);
}

void foo_add_on_get_listener(foo_on_get_listener listener)
{
	listener_add_listener(&foo_get_listeners, (listener_listener)listener);
}
