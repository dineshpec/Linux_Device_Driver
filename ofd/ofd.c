// SPDX-License-Identifier: GPL-2.0
/*
 * ofd.c - Our First Driver (simple example kernel module)
 *
 * Minimal module used for learning kernel module build/load/unload.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

/* Module metadata */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dinesh");
MODULE_DESCRIPTION("Our First Driver");
MODULE_VERSION("0.1");

static const char *driver_name = "ofd";

/**
 * ofd_init - module initialization
 *
 * Return: 0 on success, negative errno on failure
 */
static int __init ofd_init(void)
{
    pr_info("%s: init start\n", driver_name);
    /* perform any setup here (none for this minimal example) */
    pr_info("%s: init success\n", driver_name);
    return 0;
}

/**
 * ofd_exit - module cleanup
 */
static void __exit ofd_exit(void)
{
    pr_info("%s: exit called\n", driver_name);
}

module_init(ofd_init);
module_exit(ofd_exit);

