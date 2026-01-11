#include "cJSON.h"
#include "ses.h"
#include "stdio.h"
#include "stdlib.h"

char *A = "fred is cool";
char *B = "fred is very awesome";

int str_length(const char *str) {
  int len = 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

int main() {
  cJSON *output = cJSON_CreateArray();
  ses(A, B, 0, 0, str_length(A), str_length(B), output);
  char *s = cJSON_Print(output);
  puts(s);
  free(s);
  free(output);

  return 0;
}
