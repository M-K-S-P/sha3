int count(int l, int x, int y, int z) {

  return fast_pow(2, l) * (5 * y + x) + z;
}

void padding(uchar* msg, int r, int o) { 

  int j = (-o - 2) % r;
  uchar* pad = (uchar*)malloc(sizeof(uchar) * (j + 2 + o));
  //(uchar)1, [1...(j+1)] = (uchar)0, (uchar)1
  for(int i = 0; i < j + 2 + o; i++){
    
    if(!i || !(j + 1 - i)){ *(pad + i) = (uchar)1; }
    else if (i > 0 && j + 1 > i){ *(pad + i) = 0; }
    else{ *(pad + i) = *(msg + i - o); }
    
  }
  
}


void padding(unsigned char* msg, int r, int o) { 

  int j = (-o - 2) % r;
  uchar* pad = (uchar*)malloc(sizeof(uchar) * (j + 2));
  //(uchar)1, [1...(j+1)] = (uchar)0, (uchar)1
  for(int i = 0; i < j + 2 - o; i++){
                             /* here (\/) C doesn't give a shit about int != unsigned char nor I do tbh
    if(!i || !(j + 1 - i)){ *(pad + i) = 1; } */
    if(!i || !(j + 1 - i)){ *(pad + i) = (uchar)1; }
    else{ *(pad + i) = 0; }
  }
  for(int i = j + 2 - o; i < j + 2; i++){

    if(!i || !(j + 1 - i)){ *(pad + i) = (uchar)1 || *(msg + i - j - 2 + o); }
    else{ *(pad + i) = 0 || *(msg + i - j - 2 + o); }
    
  }
  int n = 
  
}

int rc(int t) {

  if (t % 255) {

    unsigned int oR[8] = {1, [1 ... 7] = 0};
    unsigned int R[9];
    for (int i = 0; i < t % 255; i++) {
      R[0] = 0;
      memcpy(R + sizeof(unsigned int), oR, 8);
      R[0] ^= R[8];
      R[4] ^= R[8];
      R[5] ^= R[8];
      R[6] ^= R[8];
      memcpy(oR, R, 8);
    }
 
  } else {
    return 1;
  }
}

main(){

  int size = fast_pow(2, l) * 5 * 5;
  unsigned char* padded_message = (unsigned char*)malloc(sizeof(char)*(co + r - co % r));
  memcpy(padded_message, argv[1], co);
  padding(argv[1], r, co);
  
}