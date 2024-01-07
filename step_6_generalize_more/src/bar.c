#include <c_story/bar.h>
#include <c_story/foo.h>
#include <c_story/baz.h>
#include <c_story/listener.h>

#define BAR_N_LISTENERS (3)

static struct bar bar = {
	.b = 10,
	.a = 20,
	.r = 30,
};

LISTENER_LISTENERS_DEFINE(bar_get_listeners, BAR_N_LISTENERS);
LISTENER_LISTENERS_DEFINE(bar_set_listeners, BAR_N_LISTENERS);

struct bar bar_get_bar(void)
{
	listener_publish(&bar_get_listeners);

	return bar;
}

void bar_set_bar(struct bar b)
{
	bar = b;

	listener_arg_publish(&bar_set_listeners, &bar);
}

void bar_add_on_set_listener(bar_on_set_listener listener)
{
	listener_add_listener(&bar_set_listeners, (listener_listener)listener);
}

void bar_add_on_get_listener(bar_on_get_listener listener)
{
	listener_add_listener(&bar_get_listeners, (listener_listener)listener);
}
