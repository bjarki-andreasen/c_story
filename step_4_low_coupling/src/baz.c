#include <c_story/baz.h>
#include <c_story/foo.h>
#include <c_story/bar.h>

#define BAZ_N_LISTENERS (3)

static struct baz baz = {
	.b = 20,
	.a = 30,
	.z = 40,
};

static baz_on_set_listener set_listeners[BAZ_N_LISTENERS];
static baz_on_get_listener get_listeners[BAZ_N_LISTENERS];

static void baz_publish_on_set(void)
{
	for (size_t i = 0; i < BAZ_N_LISTENERS; i++) {
		if (set_listeners[i] == NULL) {
			break;
		}

		set_listeners[i](baz);
	}
}

static void baz_publish_on_get(void)
{
	for (size_t i = 0; i < BAZ_N_LISTENERS; i++) {
		if (get_listeners[i] == NULL) {
			break;
		}

		get_listeners[i]();
	}
}

struct baz baz_get_baz(void)
{
	baz_publish_on_get();

	return baz;
}

void baz_set_baz(struct baz b)
{
	baz = b;

	baz_publish_on_set();
}

void baz_add_on_set_listener(baz_on_set_listener listener)
{
	for (size_t i = 0; i < BAZ_N_LISTENERS; i++) {
		if (set_listeners[i] == NULL) {
			set_listeners[i] = listener;
			break;
		}
	}
}

void baz_add_on_get_listener(baz_on_get_listener listener)
{
	for (size_t i = 0; i < BAZ_N_LISTENERS; i++) {
		if (get_listeners[i] == NULL) {
			get_listeners[i] = listener;
			break;
		}
	}
}
