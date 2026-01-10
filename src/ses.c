#include "find_middle.h"
#include <stdio.h>

void print_slice(const char *s, int start, int end) {
  if (!s || start < 0 || end <= start)
    return;
  printf("%.*s\n", end - start, s + start);
}

void ses(const char *A, const char *B, int N_start, int M_start, int N, int M) {
  printf("traversing %i, %i, %i, %i\n", N_start, M_start, N, M);

  snake middle = find_middle(A, B, N_start, M_start, N, M);

  if (middle.x == -1) {
    // print_slice(A, N_start, N);
    // print_slice(B, M_start, M);
    return;
  }

  // printf("=");
  // print_slice(A, middle.x, middle.u);

  printf("middle found: %i, %i, %i, %i\n", middle.x, middle.y, middle.u,
         middle.v);
  // printf("%i, %i, %i, %i\n", N_start, M_start, N, M);

  if (N_start == middle.x) {
    printf("+");
    print_slice(B, M_start, middle.y);
  } else if (M_start == middle.y) {
    printf("-");
    print_slice(A, N_start, middle.x);
  } else {
    ses(A, B, N_start, M_start, middle.x, middle.y);
  }

  if (middle.u == N) {
    printf("+");
    print_slice(B, middle.v, M);
  } else if (middle.v == M) {
    printf("-");
    print_slice(A, middle.u, N);
  } else {
    ses(A, B, middle.u, middle.v, N, M);
  }
}
