#include <c_story/baz.h>
#include <c_story/foo.h>
#include <c_story/baz.h>
#include <c_story/listener.h>

#define BAZ_N_LISTENERS (3)

static struct baz baz = {
	.b = 20,
	.a = 30,
	.z = 40,
};

LISTENER_LISTENERS_DEFINE(baz_get_listeners, BAZ_N_LISTENERS);
LISTENER_LISTENERS_DEFINE(baz_set_listeners, BAZ_N_LISTENERS);

struct baz baz_get_baz(void)
{
	listener_publish(&baz_get_listeners);

	return baz;
}

void baz_set_baz(struct baz b)
{
	baz = b;

	listener_arg_publish(&baz_set_listeners, &baz);
}

void baz_add_on_set_listener(baz_on_set_listener listener)
{
	listener_add_listener(&baz_set_listeners, (listener_listener)listener);
}

void baz_add_on_get_listener(baz_on_get_listener listener)
{
	listener_add_listener(&baz_get_listeners, (listener_listener)listener);
}
