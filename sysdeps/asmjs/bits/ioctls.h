#ifndef _SYS_IOCTL_H
# error "Never use <bits/ioctls.h> directly; include <sys/ioctl.h> instead."
#endif

#define FIONREAD 0x541b
#define FIONBIO  0x5421

#define FIOSETOWN	0x8901
#define SIOCSPGRP	0x8902
#define FIOGETOWN	0x8903
#define SIOCGPGRP	0x8904
#define SIOCATMARK	0x8905
#define SIOCGSTAMP	0x8906		/* Get stamp (timeval) */
#define SIOCGSTAMPNS	0x8907		/* Get stamp (timespec) */

#define SIOCGIFCONF	0x8912		/* get iface list		*/
#define SIOCGIFFLAGS	0x8913		/* get flags			*/
#define SIOCGIFNETMASK	0x891b		/* get network PA mask		*/
#define SIOCGIFBRDADDR	0x8919		/* get broadcast PA address	*/
#define SIOCGIFDSTADDR	0x8917		/* get remote PA address	*/
