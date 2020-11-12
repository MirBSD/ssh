/* $OpenBSD: crypto_api.h,v 1.5 2019/01/21 10:20:12 djm Exp $ */

/*
 * Assembled from generated headers and source files by Markus Friedl.
 * Placed in the public domain.
 */

#ifndef crypto_api_h
#define crypto_api_h

#include <stdint.h>
#include <stdlib.h>

#define randombytes(buf, buf_len) arc4random_buf((buf), (buf_len))

#endif /* crypto_api_h */
