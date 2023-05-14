#include <stdio.h>
//this is shit
int *precalc() {

  int mat[2][2] = {{0, 1}, {2, 3}};
  int new_mat[2][2] = {{0, 1}, {2, 3}};
  int state[25][2];
  int co = 0;
  int check = 1;
  while (check) {

    for (int i = 0; i < 2; i++) {

      for (int j = 0; j < 2; j++) {

        new_mat[i][j] = new_mat[i][0] * mat[0][j] + new_mat[i][1] * mat[1][j];
      
      }
    }
    

