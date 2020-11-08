#	$OpenBSD: Makefile,v 1.5 2019/12/13 19:09:10 djm Exp $

.PATH:	${.CURDIR}/..

SRCS=	ssh-sk-helper.c
SRCS+=	atomicio.c fatal.c cleanup.c msg.c
SRCS+=	${SRCS_KEY} ${SRCS_UTL} ${SRCS_BASE} ${SRCS_SK}
SRCS+=	libressl-api-compat.c

PROG=	ssh-sk-helper
MAN=	ssh-sk-helper.8

BINDIR=	/usr/libexec

.include <bsd.prog.mk>

LDADD+=	-lcrypto -lutil
DPADD+=	${LIBCRYPTO} ${LIBUTIL}
