#	$OpenBSD: Makefile,v 1.38 2020/04/03 02:26:56 djm Exp $

.PATH:	${.CURDIR}/..

SRCS=	ssh-agent.c ${SRCS_PKCS11_CLIENT}
SRCS+=	compat.c fatal.c readpass.c utf8.c
SRCS+=	${SRCS_BASE} ${SRCS_KEY} ${SRCS_KEYP} ${SRCS_KRL} ${SRCS_UTL}
SRCS+=	libressl-api-compat.c

PROG=	ssh-agent

BINOWN=	root
BINGRP=	_sshagnt
BINMODE=2555
BINDIR=	/usr/bin

.include <bsd.prog.mk>

LDADD+=	-lcrypto -lutil
DPADD+=	${LIBCRYPTO} ${LIBUTIL}
