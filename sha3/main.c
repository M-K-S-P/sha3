#include "header.h"
#include "keccak.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {

  int32_t co = strlen(argv[1]);
  uint8_t *mesg = sponge((uint8_t *)argv[1], co);
  for (int32_t i = 0; i < 64; i++){
    printf("%x", *(mesg + i));
  }
  printf("\n");
  return 0;
}