#include <stdio.h>
int main(void) {
  int x[2][3][2];
  int i,j,k;
  printf("\n\n");
  for(i = 0; i<2; i++) {
    for(j=0; j<3; j++) {
      for(k=0; k<2; k++) {
	printf("x[%d][%d][%d] = %d\n", i, j, k, x[i][j][k]);
      }
    }
  }
  printf("\n\n");
  for(i = 0; i<3; i++) {
    for(j = 0; j<2; j++) {
      x[0][i][j] = i*3+j;
      printf("x[0][%d][%d] = %d*3+%d = %d\n", i, j, i, j, (i*3+j));
    }
  }
  printf("\n\n");
  for(k = 0; k<2; k++) {
    for(j = 0; j<2; j++) {
      x[1][k][j] = x[0][j][k]-1;
      printf("x[1][%d][%d] = x[0][%d][%d]-1 = %d\n", k, j, j, k, (x[0][j][k]-1));
    }
  }
  printf("\n\n");
  for(i = 0; i<2; i++) {
    for(j=0; j<3; j++) {
      for(k=0; k<2; k++) {
	printf("x[%d][%d][%d] = %d\n", i, j, k, x[i][j][k]);
      }
    }
  }
}