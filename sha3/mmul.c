/*for (int i = 0; i < 2; i++) {
  for (int j = 0; j < 2; j++) {
    new_mat[i][j] = new_mat[i][0] * mat[0][j] + new_mat[i][1] * mat[1][j];
  }
}*/
/*
void rho(char* S, int x, int y, int z, int l){

  pair prev;
  prev->f = 0;
  prev->s = 0;
  if(x == 0 && y == 0){

  int t = -1;
    
  } else{
    
    pair nums;
    for(int t = 0; t < 24; t++){

        S[count(l, x, y, z)] = 
      
    } 
  }
}
*/

struct pair{
    int f;
    int s;
}; typedef struct pair* pair;


pair mmul(int n, pair prev){


  int m1[2][2] = {0};
  if(prev->f != 0 && prev->s != 0){

    n = 1;
    m1[2][2] = {0, prev->f, 2, prev->s};
    
  } else{

    m1[2][2] = {{0, 1}, {2, 3}};
    
  }
  int m2[2][2] = {{0, 1}, {2, 3}};
  
  for(int k = 0; k < n; k++) {
    
    for (int i = 0; i < 2; i++) {
  
      for (int j = 0; j < 2; j++) {
  
        m1[i][j] = m1[i][0] * m2[0][j] + m1[i][1] * m2[1][j];
      
      }
    }
  }

  pair nums;
  nums->f = m1[0][1];
  nums->s = m1[1][1];
  return nums;
  
}