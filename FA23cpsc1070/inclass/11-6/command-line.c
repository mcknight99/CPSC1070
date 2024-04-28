#include <stdio.h>

int main(int argc, char * argv[]) {
  printf("starting a command line demo!\n");

  
  if(argc==2) {
    printf("the argument supplied to program %s is %s\n", argv[0], argv[1]);
  } else if (argc>2) {
    printf("too many args supplied to %s\n", argv[0]);
  } else {
    printf("too few arguments supplied to %s\n", argv[0]);
  }

  printf("goodbye world!\n");
}
