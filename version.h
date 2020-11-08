/* $MirOS: src/usr.bin/ssh/version.h,v 1.49 2018/05/03 01:32:47 tg Exp $ */
/* $NetBSD: version.h,v 1.28 2003/04/03 06:21:37 itojun Exp $	*/
/* $OpenBSD: version.h,v 1.88 2020/09/27 07:22:05 djm Exp $ */

#define __OPENSSH_VERSION	"OpenSSH_8.4"

#define __MIRBSDSSH_VERSION	"MirBSD_Secure_Shell-0AuB9"

/*XXX for now */
#undef __MIRBSDSSH_VERSION
#define __MIRBSDSSH_VERSION	"MirBSD_Secure_Shell-WIP"

/*
 * it is important to retain OpenSSH version identification part, it is
 * used for bug compatibility operation.
 * present MirOS SSH version as comment.
 */
#define SSH_VERSION	(__OPENSSH_VERSION " " __MIRBSDSSH_VERSION)
