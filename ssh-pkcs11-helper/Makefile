#	$OpenBSD: Makefile,v 1.11 2019/12/13 19:09:10 djm Exp $

.PATH:	${.CURDIR}/..

SRCS=	ssh-pkcs11-helper.c ${SRCS_PKCS11}
SRCS+=	atomicio.c compat.c fatal.c readpass.c
SRCS+=	${SRCS_KEY} ${SRCS_UTL} ${SRCS_BASE}
SRCS+=	libressl-api-compat.c

PROG=	ssh-pkcs11-helper
MAN=	ssh-pkcs11-helper.8

BINDIR=	/usr/libexec

.include <bsd.prog.mk>

LDADD+=	-lcrypto -lutil
DPADD+=	${LIBCRYPTO} ${LIBUTIL}
