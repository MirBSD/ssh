#	$OpenBSD: Makefile,v 1.104 2020/01/25 23:02:14 djm Exp $

.PATH:	${.CURDIR}/..

SRCS=	sshd.c auth-rhosts.c auth-passwd.c sshpty.c sshlogin.c servconf.c \
	serverloop.c auth.c auth2.c auth-options.c session.c auth2-chall.c \
	groupaccess.c auth-bsdauth.c auth2-hostbased.c auth2-kbdint.c \
	auth2-none.c auth2-passwd.c auth2-pubkey.c monitor.c monitor_wrap.c \
	sftp-server.c sftp-common.c sftp-realpath.c sandbox-rlimit.c
SRCS+=	authfd.c compat.c dns.c fatal.c hostfile.c readpass.c utf8.c uidswap.c
SRCS+=	${SRCS_BASE} ${SRCS_KEX} ${SRCS_KEXS} ${SRCS_KEY} ${SRCS_KEYP} \
	${SRCS_KRL} ${SRCS_PROT} ${SRCS_PKT} ${SRCS_UTL} ${SRCS_PKCS11}
SRCS+=	msg.c
SRCS+=	libressl-api-compat.c

PROG=	sshd
MAN=	sshd.8 sshd_config.5

BINDIR=	/usr/sbin

.include <bsd.prog.mk>

LDADD+=	-lcrypto
DPADD+=	${LIBCRYPTO}

LDADD+=	-lutil
DPADD+=	${LIBUTIL}

.if (${ZLIB:L} == "yes")
LDADD+=	-lz
DPADD+=	${LIBZ}
.endif
