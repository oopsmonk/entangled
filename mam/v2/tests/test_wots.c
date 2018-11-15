
/*
 * Copyright (c) 2018 IOTA Stiftung
 * https://github.com/iotaledger/entangled
 *
 * MAM is based on an original implementation & specification by apmi.bsu.by
 * [ITSec Lab]
 *
 * Refer to the LICENSE file for licensing information
 */

#include "mam/v2/buffers.h"
#include "mam/v2/curl.h"
#include "mam/v2/mam.h"
#include "mam/v2/mss.h"
#include "mam/v2/ntru.h"
#include "mam/v2/pb3.h"
#include "mam/v2/prng.h"
#include "mam/v2/sponge.h"
#include "mam/v2/tests/common.h"
#include "mam/v2/trits.h"
#include "mam/v2/wots.h"
#include "utils/macros.h"

#include <string.h>
#include <unity/unity.h>

#include <memory.h>
#include <stdio.h>

MAM2_SAPI bool_t wots_test_do(iwots *w, iprng *p) {
  bool_t r = 1;
  MAM2_TRITS_DEF(N, 18);
  MAM2_TRITS_DEF(pk, MAM2_WOTS_PK_SIZE);
  MAM2_TRITS_DEF(H, MAM2_WOTS_HASH_SIZE);
  MAM2_TRITS_DEF(sig, MAM2_WOTS_SIG_SIZE);
  // MAM2_TRITS_DEF(pkr, MAM2_WOTS_PK_SIZE);

  trits_set_zero(N);
  trits_set_zero(H);
  trits_set_zero(wots_sk_trits(w));

  prng_gen(p, 7, N, H);
  wots_gen_sk(w, p, N);
  wots_calc_pk(w, pk);
  wots_sign(w, H, sig);
  TEST_ASSERT(wots_verify(w->s, H, sig, pk));

  trits_put1(H, trit_add(trits_get1(H), 1));
  r = r && !wots_verify(w->s, H, sig, pk);
  trits_put1(H, trit_sub(trits_get1(H), 1));

  trits_put1(sig, trit_add(trits_get1(sig), 1));
  TEST_ASSERT(!wots_verify(w->s, H, sig, pk));
  trits_put1(sig, trit_sub(trits_get1(sig), 1));

  trits_put1(pk, trit_add(trits_get1(pk), 1));
  r = r && !wots_verify(w->s, H, sig, pk);
  trits_put1(pk, trit_sub(trits_get1(pk), 1));

  TEST_ASSERT(r);
}

MAM2_SAPI void wots_test() {
  test_sponge_t _s[1];
  test_prng_t _p[1];
  test_wots_t _w[1];

  isponge *s = test_sponge_init(_s);
  iprng *p = test_prng_init(_p, s);
  iwots *w = test_wots_init(_w, s);

  MAM2_TRITS_DEF(K, MAM2_PRNG_KEY_SIZE);
  // init K
  trits_set_zero(K);
  const char *k_str =
      "NOPQRSTUVWXYZ9ABCDEFGHIJKLM"
      "NOPQRSTUVWXYZ9ABCDEFGHIJKLM"
      "NOPQRSTUVWXYZ9ABCDEFGHIJKLM";
  trytes_to_trits(k_str, K.p, MIN(strlen(k_str), K.n / RADIX));
  prng_init(p, p->s, K);

  wots_test_do(w, p);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(wots_test);

  return UNITY_END();
}
