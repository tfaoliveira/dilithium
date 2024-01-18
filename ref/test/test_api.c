#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include "../params.h"
#include "../api.h"

#if DILITHIUM_MODE == 2

 #define namespace_PUBLICKEYBYTES pqcrystals_dilithium2_PUBLICKEYBYTES
 #define namespace_SECRETKEYBYTES pqcrystals_dilithium2_SECRETKEYBYTES
 #define namespace_BYTES          pqcrystals_dilithium2_BYTES

#elif DILITHIUM_MODE == 3

 #define namespace_PUBLICKEYBYTES pqcrystals_dilithium3_PUBLICKEYBYTES
 #define namespace_SECRETKEYBYTES pqcrystals_dilithium3_SECRETKEYBYTES
 #define namespace_BYTES          pqcrystals_dilithium3_BYTES

#elif DILITHIUM_MODE == 5

 #define namespace_PUBLICKEYBYTES pqcrystals_dilithium5_PUBLICKEYBYTES
 #define namespace_SECRETKEYBYTES pqcrystals_dilithium5_SECRETKEYBYTES
 #define namespace_BYTES          pqcrystals_dilithium5_BYTES

#endif


int main(void)
{
  int ret = 0;

  if(namespace_PUBLICKEYBYTES != CRYPTO_PUBLICKEYBYTES) {
    fprintf(stderr, "params.h PUBLICKEYBYTES (%d) != api.h CRYPTO_PUBLICKEYBYTES (%d)\n",
      namespace_PUBLICKEYBYTES,  CRYPTO_PUBLICKEYBYTES);
    ret = -1;
  }

  if(namespace_SECRETKEYBYTES != CRYPTO_SECRETKEYBYTES) {
    fprintf(stderr, "params.h SECRETKEYBYTES (%d) != api.h CRYPTO_SECRETKEYBYTES (%d)\n",
      namespace_SECRETKEYBYTES,  CRYPTO_SECRETKEYBYTES);
    ret = -1;
  }

  if(namespace_BYTES != CRYPTO_BYTES) {
    fprintf(stderr, "params.h BYTES (%d) != api.h CRYPTO_BYTES (%d)\n",
      namespace_BYTES,  CRYPTO_BYTES);
    ret = -1;
  }

  return ret;
}
