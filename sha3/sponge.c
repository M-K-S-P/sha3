#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<string.h>
#include"keccak.h"

uint8_t* padding(uint8_t* msg, int32_t ps, int32_t r){

  
  int32_t news = (ps + r - ps % r);
  uint8_t* newmsg = malloc(news);
  memcpy(newmsg, msg, ps);
  *(newmsg + ps) = 0x01;
  ps++;
  while(ps < (news - 1)){
    *(newmsg + ps) = 0x00;
    ps++;
  }
  *(newmsg + ps) = 0x80;
  ps++;
  *newmsg = ps;
  return newmsg;
  
}



uint8_t* sponge(uint8_t* msg, int32_t co){

  int32_t r = 512;
  int32_t w = 64; // 2 ^ l
  uint64_t* nm;
  /*Padding*/
  if((co % r) != 0){
    msg = padding(msg, co, r);
  }
  nm = (uint64_t *)msg;
  uint64_t **S = (uint64_t **)calloc(5, sizeof(uint64_t*));
  for(uint64_t i = 0; i < 5; i++) S[i] = (uint64_t *)calloc(5,sizeof(uint64_t));
  /*Absorbing Phase*/
  for(int32_t i=0;i<co/r;i++){
    for(int32_t y=0;y<5;y++){
      for(int32_t x=0;x<5;x++){
	      if((x+5*y)<(r/w)){
	        S[x][y]=S[x][y] ^ *(nm + i*9+x+5*y);
	      }
      }
    }
    S=keccak_f(S);
  }    
  /*Squeezing Phase*/
  int32_t b = 0;
  uint64_t* Z = (uint64_t *)calloc(65, sizeof(uint64_t));
  while(b < 64){

    for(int32_t y = 0; y < 5; y++){
      for(int32_t x = 0; x < 5; x++){
        if(x + y * 5 < r / w){
          *(Z + b) ^= S[x][y];
          b++;
        }
      }
    }  
  }
  return (uint8_t *)Z;
 
}