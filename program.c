#include <stdio.h>
#include <openssl/crypto.h>

int main()
{
  printf("%d.%d.%d%s%s\n",
         OPENSSL_version_major(),
         OPENSSL_version_minor(),
         OPENSSL_version_patch(),
         OPENSSL_version_pre_release(),
         OPENSSL_version_build_metadata());
}
