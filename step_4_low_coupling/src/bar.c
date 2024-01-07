#include <c_story/bar.h>
#include <c_story/foo.h>
#include <c_story/baz.h>

#define BAR_N_LISTENERS (3)

static struct bar bar = {
	.b = 10,
	.a = 20,
	.r = 30,
};

static bar_on_set_listener set_listeners[BAR_N_LISTENERS];
static bar_on_get_listener get_listeners[BAR_N_LISTENERS];

static void bar_publish_on_set(void)
{
	for (size_t i = 0; i < BAR_N_LISTENERS; i++) {
		if (set_listeners[i] == NULL) {
			break;
		}

		set_listeners[i](bar);
	}
}

static void bar_publish_on_get(void)
{
	for (size_t i = 0; i < BAR_N_LISTENERS; i++) {
		if (get_listeners[i] == NULL) {
			break;
		}

		get_listeners[i]();
	}
}

struct bar bar_get_bar(void)
{
	bar_publish_on_get();

	return bar;
}

void bar_set_bar(struct bar b)
{
	bar = b;

	bar_publish_on_set();
}

void bar_add_on_set_listener(bar_on_set_listener listener)
{
	for (size_t i = 0; i < BAR_N_LISTENERS; i++) {
		if (set_listeners[i] == NULL) {
			set_listeners[i] = listener;
			break;
		}
	}
}

void bar_add_on_get_listener(bar_on_get_listener listener)
{
	for (size_t i = 0; i < BAR_N_LISTENERS; i++) {
		if (get_listeners[i] == NULL) {
			get_listeners[i] = listener;
			break;
		}
	}
}
