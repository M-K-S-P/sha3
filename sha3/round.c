#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

const uint64_t r[5][5]={ 
      {0,36,3,41,18},
			{1,44,10,45,2},
			{62,6,43,15,61},
			{28,55,25,21,56},
			{27,20,39,8,14}
};



int fast_pow(long a, long b) {

  if (b == 1)
    return a;
  if (b % 2 == 1)
    return a * fast_pow(a, b - 1);
  int tmp_exp = fast_pow(a, b / 2);
  return tmp_exp * tmp_exp;
}

void sha3_round(uint64_t **S, int l, int rc) { //pi + rho + chi + const

  uint64_t Q[5];
  uint64_t D[5];
  
  for(int i = 0; i < 5; i ++){
    Q[i] = S[i][0] ^ S[i][1] ^ S[i][2] ^ S[i][3] ^ S[i][4];
  }
  for(int i = 0; i < 5; i ++){
    D[i] = Q[(i + 4) % 5] ^ ((Q[(i + 1) % 5] << 1) | (Q[(i + 1) % 5] >> 63));
  }
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 5; y++){
      S[x][y] ^= D[x]; 
    }
  }
  uint64_t C[5][5];
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 5; y++){
      C[y][(2*x+3*y) % 5]=((S[x][y] << r[x][y]) | (S[x][y] >> (64-r[x][y])));
    }
  }
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 5; y++){
      S[x][y] = C[x][y] ^ ((~C[(x+1) % 5][y]) & C[(x+2) % 5][y]);
    }
  }
  S[0][0] = S[0][0] ^ rc;
  
}


void theta(uint64_t **S, int l) {

  //S[count(l, x, y, z)] += sum(S, x - 1, y, z, l) + sum(S, x + 1, y, z, l);
  uint64_t C[5];
  uint64_t D[5];
  
  for(int i = 0; i < 5; i ++){
    C[i] = S[i][0] ^ S[i][1] ^ S[i][2] ^ S[i][3] ^ S[i][4];
  }
  for(int i = 0; i < 5; i ++){
    D[i] = C[(i + 4) % 5] ^ ((C[(i + 1) % 5] << 1) | (C[(i + 1) % 5] >> 63));
  }
  for(int x = 0; x < 5; x++){
    for(int y = 0; y < 5; y++){
      S[x][y] ^= D[x]; 
    }
  }
    
}

/*
void keccakp(uint64_t** msg, int nr, int l){

  for(int i = 12 + 2 * l - nr; i < 12 + 2l - 1; i++){

    theta(msg, l);
    prxc(msg, l, i);  //надо все declaration из funcs отдельно в header записать
    
  }
  
}*/