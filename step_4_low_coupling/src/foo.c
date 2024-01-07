#include <c_story/foo.h>
#include <c_story/baz.h>
#include <c_story/bar.h>

#define FOO_N_LISTENERS (3)

static struct foo foo = {
	.f = 10,
	.oo = 20,
};

static foo_on_set_listener set_listeners[FOO_N_LISTENERS];
static foo_on_get_listener get_listeners[FOO_N_LISTENERS];

static void foo_publish_on_set(void)
{
	for (size_t i = 0; i < FOO_N_LISTENERS; i++) {
		if (set_listeners[i] == NULL) {
			break;
		}

		set_listeners[i](foo);
	}
}

static void foo_publish_on_get(void)
{
	for (size_t i = 0; i < FOO_N_LISTENERS; i++) {
		if (get_listeners[i] == NULL) {
			break;
		}

		get_listeners[i]();
	}
}

struct foo foo_get_foo(void)
{
	foo_publish_on_get();

	return foo;
}

void foo_set_foo(struct foo b)
{
	foo = b;

	foo_publish_on_set();
}

void foo_add_on_set_listener(foo_on_set_listener listener)
{
	for (size_t i = 0; i < FOO_N_LISTENERS; i++) {
		if (set_listeners[i] == NULL) {
			set_listeners[i] = listener;
			break;
		}
	}
}

void foo_add_on_get_listener(foo_on_get_listener listener)
{
	for (size_t i = 0; i < FOO_N_LISTENERS; i++) {
		if (get_listeners[i] == NULL) {
			get_listeners[i] = listener;
			break;
		}
	}
}
