/*
 * Copyright (C) 2024 Zakki
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>

#define NODE_NAME "zakki"
#define SUCCESS 0
#define MESSAGE "Hello! I'm Zakki, a low-level programmer!\nCheck out my links below:\n\tX: https://x.com/zakki0925224\n\tGitHub: https://github.com/zakki0925224\n\tPortfolio: https://zakki0925224.github.io\n"

MODULE_LICENSE("GPL");

static int major_num;

static int zakki_open(struct inode* inode, struct file* file) {
    printk("zakki_open\n");
    return SUCCESS;
}

static int zakki_release(struct inode* inode, struct file* file) {
    printk("zakki_release\n");
    return SUCCESS;
}

static ssize_t zakki_read(struct file* file, char __user* buf, size_t count, loff_t* f_pos) {
    ssize_t len = strlen(MESSAGE) + 1;

    if (*f_pos > 0)
        return 0;

    if (count < len)
        len = count;

    if (copy_to_user(buf, MESSAGE, len) != 0)
        return -EFAULT;

    *f_pos += len;

    printk("zakki_read\n");
    return len;
}

static ssize_t zakki_write(struct file* file, const char __user* buf, size_t count, loff_t* f_pos) {
    printk("zakki_write\n");
    return count;
}

struct file_operations zakki_fops =
    {
        .owner = THIS_MODULE,
        .read = zakki_read,
        .write = zakki_write,
        .open = zakki_open,
        .release = zakki_release};

static int zakki_init(void) {
    major_num = register_chrdev(major_num, NODE_NAME, &zakki_fops);
    printk("zakki_init\n");
    return SUCCESS;
}

static void zakki_exit(void) {
    unregister_chrdev(major_num, NODE_NAME);
    printk("zakki_exit\n");
}

module_init(zakki_init);
module_exit(zakki_exit);
