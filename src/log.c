#include "diff.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *read_file(const char *filename, int *length) {
  FILE *f = fopen(filename, "r");
  if (!f) {
    fprintf(stderr, "Error: Could not open file %s\n", filename);
    exit(1);
  }
  
  fseek(f, 0, SEEK_END);
  long fsize = ftell(f);
  fseek(f, 0, SEEK_SET);

  char *content = malloc(fsize + 1);
  fread(content, 1, fsize, f);
  content[fsize] = '\0';
  fclose(f);

  *length = fsize;
  return content;
}

int main(int argc, char *argv[]) {
  int len_a, len_b;
  char *A, *B;
  int should_free = 1;

  if (argc == 3) {
    A = read_file(argv[1], &len_a);
    B = read_file(argv[2], &len_b);
  } else {
    A = "fred";
    B = "frad";
    len_a = strlen(A);
    len_b = strlen(B);
    should_free = 0;
  }

  int *result = diff(A, B, len_a, len_b);

  int result_len = result[0];

  printf("diff_count: %i\n", result_len / 2);
  for (int i = 1; i < result_len; i += 2) {
    printf("diff_type: %i\n", result[i]);
    printf("len: %i\n", result[i + 1]);
  }

  if (should_free) {
    free(A);
    free(B);
  }
  free(result);
  return 0;
}
