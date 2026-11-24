#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s = ft_strtrim("abcdba", "bac");
  printf("%s", s);
  free(s);
  return 0;
}