#	$OpenBSD: Makefile,v 1.81 2020/01/25 23:02:14 djm Exp $

.PATH:	${.CURDIR}/..

SRCS=	ssh.c readconf.c clientloop.c sshtty.c sshconnect.c sshconnect2.c mux.c
SRCS+=	authfd.c compat.c dns.c fatal.c hostfile.c readpass.c utf8.c
SRCS+=	${SRCS_BASE} ${SRCS_KEX} ${SRCS_KEXC} ${SRCS_KEY} ${SRCS_KEYP} \
	${SRCS_KRL} ${SRCS_PROT} ${SRCS_PKT} ${SRCS_UTL} ${SRCS_PKCS11}
SRCS+=	msg.c
SRCS+=	libressl-api-compat.c

PROG=	ssh
MAN=	ssh.1 ssh_config.5

BINDIR=	/usr/bin

.include <bsd.prog.mk>

LDADD+=	-lcrypto
DPADD+=	${LIBCRYPTO}

LDADD+=	-lutil
DPADD+=	${LIBUTIL}

.if (${ZLIB:L} == "yes")
LDADD+=	-lz
DPADD+=	${LIBZ}
.endif
