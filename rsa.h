/*
 * Author: Tatu Ylonen <ylo@cs.hut.fi>
 * Copyright (c) 1995 Tatu Ylonen <ylo@cs.hut.fi>, Espoo, Finland
 *                    All rights reserved
 * RSA key generation, encryption and decryption.
 *
 * As far as I am concerned, the code I have written for this software
 * can be used freely for any purpose.  Any derived versions of this
 * software must be clearly marked as such, and if the derived work is
 * incompatible with the protocol description in the RFC file, it must be
 * called by a name other than "ssh" or "Secure Shell".
 */

/* RCSID("$OpenBSD: rsa.h,v 1.9 2000/11/12 19:50:38 markus Exp $"); */

#ifndef RSA_H
#define RSA_H

#include <openssl/bn.h>
#include <openssl/rsa.h>

void rsa_public_encrypt __P((BIGNUM * out, BIGNUM * in, RSA * prv));
void rsa_private_decrypt __P((BIGNUM * out, BIGNUM * in, RSA * prv));

#endif				/* RSA_H */
