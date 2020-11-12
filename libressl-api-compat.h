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

void DSA_get0_pqg(const DSA *d, const BIGNUM **p, const BIGNUM **q,
    const BIGNUM **g);

int DSA_set0_pqg(DSA *d, BIGNUM *p, BIGNUM *q, BIGNUM *g);

void DSA_get0_key(const DSA *d, const BIGNUM **pub_key,
    const BIGNUM **priv_key);

int DSA_set0_key(DSA *d, BIGNUM *pub_key, BIGNUM *priv_key);

void RSA_get0_key(const RSA *r, const BIGNUM **n, const BIGNUM **e,
    const BIGNUM **d);

int RSA_set0_key(RSA *r, BIGNUM *n, BIGNUM *e, BIGNUM *d);

void RSA_get0_crt_params(const RSA *r, const BIGNUM **dmp1, const BIGNUM **dmq1,
    const BIGNUM **iqmp);

int RSA_set0_crt_params(RSA *r, BIGNUM *dmp1, BIGNUM *dmq1, BIGNUM *iqmp);

void RSA_get0_factors(const RSA *r, const BIGNUM **p, const BIGNUM **q);

int RSA_set0_factors(RSA *r, BIGNUM *p, BIGNUM *q);

int EVP_CIPHER_CTX_get_iv(const EVP_CIPHER_CTX *ctx,
    unsigned char *iv, size_t len);

int EVP_CIPHER_CTX_set_iv(EVP_CIPHER_CTX *ctx,
    const unsigned char *iv, size_t len);

void DSA_SIG_get0(const DSA_SIG *sig, const BIGNUM **pr, const BIGNUM **ps);

int DSA_SIG_set0(DSA_SIG *sig, BIGNUM *r, BIGNUM *s);

void DH_get0_pqg(const DH *dh, const BIGNUM **p, const BIGNUM **q,
    const BIGNUM **g);

int DH_set0_pqg(DH *dh, BIGNUM *p, BIGNUM *q, BIGNUM *g);

void DH_get0_key(const DH *dh, const BIGNUM **pub_key, const BIGNUM **priv_key);

int DH_set_length(DH *dh, long length);

RSA_METHOD *RSA_meth_dup(const RSA_METHOD *meth);

int RSA_meth_set1_name(RSA_METHOD *meth, const char *name);

int RSA_meth_set_priv_enc(RSA_METHOD *meth, int (*priv_enc)(int flen,
    const unsigned char *from, unsigned char *to, RSA *rsa, int padding));

#define EVP_PKEY_base_id(pkey) EVP_PKEY_type((pkey)->type)

#define EVP_CIPHER_CTX_new() ((EVP_CIPHER_CTX *)calloc(1, sizeof(EVP_CIPHER_CTX)))
#define EVP_CIPHER_CTX_free(ctx) do {		\
	if (ctx) {				\
		EVP_CIPHER_CTX_cleanup(ctx);	\
		free(ctx);			\
	}					\
} while (/* CONSTCOND */ 0);

#define EVP_MD_CTX_new() ((EVP_MD_CTX *)calloc(1, sizeof(EVP_MD_CTX)))
#define EVP_MD_CTX_free(ctx) do {		\
	if (ctx) {				\
		EVP_MD_CTX_cleanup(ctx);	\
		free(ctx);			\
	}					\
} while (/* CONSTCOND */ 0);

#endif /* _LIBRESSL_API_COMPAT_H */
