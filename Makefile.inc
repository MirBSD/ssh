#	$OpenBSD: Makefile.inc,v 1.85 2020/10/16 13:24:45 djm Exp $

.include <bsd.own.mk>

CPPFLAGS+=	-I${.CURDIR:Q}/..
#CPPFLAGS+=	-DDEBUG_MATCHING

COPTS+=		-Wall
COPTS+=		-Wextra
COPTS+=		-Wformat-security
COPTS+=		-Wmissing-declarations
COPTS+=		-Wmissing-prototypes
COPTS+=		-Wpointer-arith
COPTS+=		-Wshadow
COPTS+=		-Wstrict-prototypes
COPTS+=		-Wunused
COPTS+=		-Wno-unused-parameter # Lots of these in protocol handlers.

ZLIB?=		yes

.if (${ZLIB:L} == "yes")
CPPFLAGS+=	-DWITH_ZLIB
.endif

CPPFLAGS+=	-DENABLE_PKCS11
.ifndef NOPIC
CPPFLAGS+=	-DHAVE_DLOPEN
.endif

SRCS_BASE+=	sshbuf.c
SRCS_BASE+=	sshbuf-getput-basic.c
SRCS_BASE+=	sshbuf-misc.c
SRCS_BASE+=	ssherr.c
SRCS_BASE+=	log.c
SRCS_BASE+=	xmalloc.c
SRCS_BASE+=	misc.c
SRCS_BASE+=	addrmatch.c
SRCS_BASE+=	match.c

SRCS_KEX+=	dh.c
SRCS_KEX+=	kexdh.c
SRCS_KEX+=	kexgex.c
SRCS_KEXC+=	kexgexc.c
SRCS_KEXS+=	kexgexs.c
SRCS_KEX+=	kexgen.c

SRCS_KEY+=	sshkey.c
SRCS_KEY+=	cipher.c
SRCS_KEY+=	cipher-ctr.c
SRCS_KEY+=	ssh-dss.c
SRCS_KEY+=	ssh-rsa.c
SRCS_KEY+=	sshbuf-getput-crypto.c
SRCS_KEY+=	digest-openssl.c

SRCS_KEYP+=	authfile.c
SRCS_KEYP+=	sshbuf-io.c
SRCS_KEYP+=	atomicio.c

SRCS_KRL+=	bitmap.c
SRCS_KRL+=	krl.c

SRCS_PKT+=	canohost.c
SRCS_PKT+=	dispatch.c
SRCS_PKT+=	hmac.c
SRCS_PKT+=	kex.c
SRCS_PKT+=	mac.c
SRCS_PKT+=	packet.c
SRCS_PKT+=	umac.c
SRCS_PKT+=	umac128.c

SRCS_PROT+=	channels.c
SRCS_PROT+=	monitor_fdpass.c
SRCS_PROT+=	nchan.c
SRCS_PROT+=	ttymodes.c

SRCS_PKCS11+=		ssh-pkcs11.c
SRCS_PKCS11_CLIENT+=	ssh-pkcs11-client.c
SRCS_MODULI+=		moduli.c

WITH_XMSS?=	no
.if (${WITH_XMSS:L} == "yes")
CPPFLAGS+=	-DWITH_XMSS
SRCS_KEY+=	ssh-xmss.c
SRCS_KEY+=	sshkey-xmss.c
SRCS_KEY+=	xmss_commons.c
SRCS_KEY+=	xmss_fast.c
SRCS_KEY+=	xmss_hash.c
SRCS_KEY+=	xmss_hash_address.c
SRCS_KEY+=	xmss_wots.c
.endif

.include <bsd.obj.mk>
