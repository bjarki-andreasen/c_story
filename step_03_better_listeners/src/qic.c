#include <c_story/qic.h>
#include <c_story/foo.h>
#include <c_story/baz.h>
#include <zephyr/kernel.h>

static struct qic qic;

static struct k_spinlock b_lock;
static struct listener_ctx l_ctx;

void qic_get_qic(struct qic *b)
{
	K_SPINLOCK(&b_lock) {
		*b = qic;
	}
}

void qic_add_callback(struct listener_listener *listener, listener_callback cb)
{
	listener_add_listener(&l_ctx, listener, cb);
}

static void qic_set_qic(const struct qic *b)
{
	K_SPINLOCK(&b_lock) {
		qic = *b;
	}

	listener_publish(&l_ctx);
}

static void qic_routine(void)
{
	static struct qic qic_set;

	while (true) {
		qic_set.q++;
		printk("qic set qic.b to %u\n", qic_set.q);
		qic_set_qic(&qic_set);
		k_msleep(500);
	}
}

K_THREAD_DEFINE(qic_thread, 512, qic_routine, NULL, NULL, NULL, 3, 0, 0);
