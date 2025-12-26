#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int diff(
  const char *a_str, int N,
  const char *b_str, int M
) {
  int MAX = N + M;

  int x;
  int y;

  int* V_ptr = calloc((2 * MAX + 1), sizeof(int));

  for (int D = 0; D <= MAX; D++) {
    // lemma 1
    // TODO: optimize away k not on grid
    for (int k = -D; k <= D; k += 2) {
      if (k == -D || (k != D && V_ptr[k + MAX - 1] < V_ptr[k + MAX + 1])) {
        x = V_ptr[k + MAX + 1];
      } else {
        x = V_ptr[k + MAX - 1] + 1;
      }

      y = x - k;

      while (x < N && y < M && a_str[x] == b_str[y]) {
        x++;
        y++;
      }

      V_ptr[k + MAX] = x;
      printf("%i, %i\n", D, x);

      if (x == N && y == M) {
        free(V_ptr);
        return D;
      }

    }
  }

  free(V_ptr);
  return -1;
}