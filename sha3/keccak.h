#include <stdint.h>
#ifndef KECCAK_H
#define KECCAK_H
uint64_t **keccak_f(uint64_t **A);
uint64_t **sha3_round(uint64_t **S, int rc);
#endif
