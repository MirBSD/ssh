/*
 * Copyright (c) 2005 Darren Tucker <dtucker@zip.com.au>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _LIBRESSL_API_COMPAT_H
#define _LIBRESSL_API_COMPAT_H

__RCSID("$MirOS$");

#include <openssl/opensslv.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/dsa.h>
#include <openssl/dh.h>

/* LibreSSL/OpenSSL 1.1x API compat */
#ifndef HAVE_DSA_GET0_PQG
void DSA_get0_pqg(const DSA *d, const BIGNUM **p, const BIGNUM **q,
    const BIGNUM **g);
#endif /* HAVE_DSA_GET0_PQG */

#ifndef HAVE_DSA_SET0_PQG
int DSA_set0_pqg(DSA *d, BIGNUM *p, BIGNUM *q, BIGNUM *g);
#endif /* HAVE_DSA_SET0_PQG */

#ifndef HAVE_DSA_GET0_KEY
void DSA_get0_key(const DSA *d, const BIGNUM **pub_key,
    const BIGNUM **priv_key);
#endif /* HAVE_DSA_GET0_KEY */

#ifndef HAVE_DSA_SET0_KEY
int DSA_set0_key(DSA *d, BIGNUM *pub_key, BIGNUM *priv_key);
#endif /* HAVE_DSA_SET0_KEY */

#ifndef HAVE_EVP_CIPHER_CTX_GET_IV
int EVP_CIPHER_CTX_get_iv(const EVP_CIPHER_CTX *ctx,
    unsigned char *iv, size_t len);
#endif /* HAVE_EVP_CIPHER_CTX_GET_IV */

#ifndef HAVE_EVP_CIPHER_CTX_SET_IV
int EVP_CIPHER_CTX_set_iv(EVP_CIPHER_CTX *ctx,
    const unsigned char *iv, size_t len);
#endif /* HAVE_EVP_CIPHER_CTX_SET_IV */

#ifndef HAVE_RSA_GET0_KEY
void RSA_get0_key(const RSA *r, const BIGNUM **n, const BIGNUM **e,
    const BIGNUM **d);
#endif /* HAVE_RSA_GET0_KEY */

#ifndef HAVE_RSA_SET0_KEY
int RSA_set0_key(RSA *r, BIGNUM *n, BIGNUM *e, BIGNUM *d);
#endif /* HAVE_RSA_SET0_KEY */

#ifndef HAVE_RSA_GET0_CRT_PARAMS
void RSA_get0_crt_params(const RSA *r, const BIGNUM **dmp1, const BIGNUM **dmq1,
    const BIGNUM **iqmp);
#endif /* HAVE_RSA_GET0_CRT_PARAMS */

#ifndef HAVE_RSA_SET0_CRT_PARAMS
int RSA_set0_crt_params(RSA *r, BIGNUM *dmp1, BIGNUM *dmq1, BIGNUM *iqmp);
#endif /* HAVE_RSA_SET0_CRT_PARAMS */

#ifndef HAVE_RSA_GET0_FACTORS
void RSA_get0_factors(const RSA *r, const BIGNUM **p, const BIGNUM **q);
#endif /* HAVE_RSA_GET0_FACTORS */

#ifndef HAVE_RSA_SET0_FACTORS
int RSA_set0_factors(RSA *r, BIGNUM *p, BIGNUM *q);
#endif /* HAVE_RSA_SET0_FACTORS */

#ifndef DSA_SIG_GET0
void DSA_SIG_get0(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);
#endif /* DSA_SIG_GET0 */

#ifndef DSA_SIG_SET0
int DSA_SIG_set0(DSA_SIG *sig, BIGNUM *r, BIGNUM *s);
#endif /* DSA_SIG_SET0 */

#ifndef HAVE_DH_GET0_PQG
void DH_get0_pqg(const DH *dh, const BIGNUM **p, const BIGNUM **q,
    const BIGNUM **g);
#endif /* HAVE_DH_GET0_PQG */

#ifndef HAVE_DH_SET0_PQG
int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g);
#endif /* HAVE_DH_SET0_PQG */

#ifndef HAVE_DH_GET0_KEY
void DH_get0_key(const DH *dh, const BIGNUM **pub_key, const BIGNUM **priv_key);
#endif /* HAVE_DH_GET0_KEY */

#ifndef HAVE_DH_SET0_KEY
int DH_set0_key(DH *dh, BIGNUM *pub_key, BIGNUM *priv_key);
#endif /* HAVE_DH_SET0_KEY */

#ifndef HAVE_DH_SET_LENGTH
int DH_set_length(DH *dh, long length);
#endif /* HAVE_DH_SET_LENGTH */

#ifndef HAVE_RSA_METH_FREE
void RSA_meth_free(RSA_METHOD *meth);
#endif /* HAVE_RSA_METH_FREE */

#ifndef HAVE_RSA_METH_DUP
RSA_METHOD *RSA_meth_dup(const RSA_METHOD *meth);
#endif /* HAVE_RSA_METH_DUP */

#ifndef HAVE_RSA_METH_SET1_NAME
int RSA_meth_set1_name(RSA_METHOD *meth, const char *name);
#endif /* HAVE_RSA_METH_SET1_NAME */

#ifndef HAVE_RSA_METH_GET_FINISH
int (*RSA_meth_get_finish(const RSA_METHOD *meth))(RSA *rsa);
#endif /* HAVE_RSA_METH_GET_FINISH */

#ifndef HAVE_RSA_METH_SET_PRIV_ENC
int RSA_meth_set_priv_enc(RSA_METHOD *meth, int (*priv_enc)(int flen,
    const unsigned char *from, unsigned char *to, RSA *rsa, int padding));
#endif /* HAVE_RSA_METH_SET_PRIV_ENC */

#ifndef HAVE_RSA_METH_SET_PRIV_DEC
int RSA_meth_set_priv_dec(RSA_METHOD *meth, int (*priv_dec)(int flen,
    const unsigned char *from, unsigned char *to, RSA *rsa, int padding));
#endif /* HAVE_RSA_METH_SET_PRIV_DEC */

#ifndef HAVE_RSA_METH_SET_FINISH
int RSA_meth_set_finish(RSA_METHOD *meth, int (*finish)(RSA *rsa));
#endif /* HAVE_RSA_METH_SET_FINISH */

#ifndef HAVE_EVP_PKEY_GET0_RSA
RSA *EVP_PKEY_get0_RSA(EVP_PKEY *pkey);
#endif /* HAVE_EVP_PKEY_GET0_RSA */

#ifndef HAVE_EVP_MD_CTX_new
EVP_MD_CTX *EVP_MD_CTX_new(void);
#endif /* HAVE_EVP_MD_CTX_new */

#ifndef HAVE_EVP_MD_CTX_free
void EVP_MD_CTX_free(EVP_MD_CTX *ctx);
#endif /* HAVE_EVP_MD_CTX_free */

#ifndef OPENSSL_API_COMPAT
/* 0.9.7-MirBSD, we presume */
#define EVP_PKEY_base_id(pkey) EVP_PKEY_type((pkey)->type)
#define EVP_CIPHER_CTX_new() ((EVP_CIPHER_CTX *)calloc(1, sizeof(EVP_CIPHER_CTX)))
#define EVP_CIPHER_CTX_free(ctx) do {		\
	if (ctx) {				\
		EVP_CIPHER_CTX_cleanup(ctx);	\
		free(ctx);			\
	}					\
} while (/* CONSTCOND */ 0);
#endif

#endif /* _LIBRESSL_API_COMPAT_H */
