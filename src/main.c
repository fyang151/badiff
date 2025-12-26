#include <stdio.h>
#include <stdlib.h>
#include "diff.h"

int str_length(const char* str) {
  int len = 0;
  while (str[len] != '\0') {
      len++;
  }
  return len;
}

char *a_str_example = "fred";
char *b_str_example = "rad";

int main() {
  int N_example = str_length(a_str_example);
  int M_example = str_length(b_str_example);

  int N = N_example;
  int M = M_example;

  int D = diff(
    a_str_example, 
    N,
    b_str_example, 
    M
  );
  
  printf("Edit distance: %i\n", D);
}

