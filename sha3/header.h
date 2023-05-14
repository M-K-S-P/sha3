#include<stdint.h>
#ifndef SPONGE_H
#define SPONGE_H
uint8_t* padding(uint8_t* msg, int32_t ps, int32_t r);
uint8_t* sponge(uint8_t* msg, int32_t ps);
#endif
