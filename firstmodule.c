/******************************************************************************
 *
 *   Copyright (C) 2011  Intel Corporation. All rights reserved.
 *
 *   This program is free software;  you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; version 2 of the License.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY;  without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See
 *   the GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program;  if not, write to the Free Software
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 *****************************************************************************/

#include <linux/kernel.h> /* Needed for pr_info() */
#include <linux/module.h> /* Needed by all modules */
#include<linux/init.h>


static int par=5;
module_param(par,int,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(par, "A short integer");
static int helloworld_init(void)
{
            printk(KERN_EMERG "Hello world 1.\n");
            printk("%d",par);
             printk("loading driver\n");
                /* A non 0 return means init_module error; module can't be loaded. */
                return 0;
}



static void helloworld_exit(void)
{
            printk(KERN_EMERG "Goodbye world 1.\n");
}



module_init(helloworld_init);
module_exit(helloworld_exit);




MODULE_LICENSE("GPL");        // The license  under which the module is distributed.
MODULE_AUTHOR("Visteon");// The author of the module.
MODULE_DESCRIPTION("HelloWorld Linux Kernel Module."); // The Description of the module.

