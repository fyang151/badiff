#include "cJSON.h"
#include "ses.h"

char *diff(const char *A, const char *B, int N, int M) {
  cJSON *output = cJSON_CreateArray();
  ses(A, B, 0, 0, N, M, output);
  char *s = cJSON_Print(output);

  char *json = cJSON_PrintUnformatted(output);

  cJSON_Delete(output);
  return json; // return heap-allocated string
}
