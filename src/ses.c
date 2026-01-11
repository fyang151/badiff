#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cJSON.h"
#include "find_middle.h"

void print_slice(const char *s, int start, int end) {
  if (!s || start < 0 || end <= start)
    return;
  printf("%.*s\n", end - start, s + start);
}

void add_diff_item(cJSON *output, int type, const char *S, int from, int to) {
  int len = to - from;

  if (len <= 0) {
    // sanity check
    return;
  }

  char *buf = malloc(len + 1);
  memcpy(buf, S + from, len);
  buf[len] = '\0';

  cJSON *diff_item = cJSON_CreateObject();
  cJSON_AddNumberToObject(diff_item, "diff_type", type);
  cJSON_AddStringToObject(diff_item, "script", buf);
  cJSON_AddItemToArray(output, diff_item);

  free(buf);
}

void ses(const char *A, const char *B, int N_start, int M_start, int N, int M,
         cJSON *output) {
  if (M_start == M) {
    add_diff_item(output, -1, A, N_start, N);
    return;
  }

  if (N_start == N) {
    add_diff_item(output, 1, B, M_start, M);
    return;
  }

  snake middle = find_middle(A, B, N_start, M_start, N, M);

  if (middle.x == -1) {
    add_diff_item(output, -1, A, N_start, N);
    add_diff_item(output, 1, B, M_start, M);
    return;
  }

  ses(A, B, N_start, M_start, middle.x, middle.y, output);

  add_diff_item(output, 0, A, middle.x, middle.u);

  ses(A, B, middle.u, middle.v, N, M, output);
}
