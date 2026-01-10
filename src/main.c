#include <stdio.h>

#include "find_middle.h"
#include "ses.h"

void print_slice1(const char *s, int start, int end) {
  if (!s || start < 0 || end <= start)
    return;
  printf("%.*s\n", end - start, s + start);
}

int str_length(const char *str) {

  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

char *a_str_example = "frad";
char *b_str_example = "frud";

int main() {
  int N_example = str_length(a_str_example);
  int M_example = str_length(b_str_example);

  int N = N_example;
  int M = M_example;

  printf("%s, %s\n", a_str_example, b_str_example);

  ses(a_str_example, b_str_example, 0, 0, N, M);

  // snake middle = find_middle(a_str_example, b_str_example, 1, 2, 2, 3);
  // printf("middle, %i, %i, %i, %i\n", middle.x, middle.y, middle.u, middle.v);
  // print_slice1(a_str_example, middle.x, middle.u);
}
