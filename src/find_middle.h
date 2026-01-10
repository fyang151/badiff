typedef struct snake {
  int x;
  int y;
  int u;
  int v;
} snake;

snake find_middle(const char *a_str, const char *b_str, int N_start,
                  int M_start, int N, int M);
