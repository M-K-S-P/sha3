#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat(const char *s1, const char *s2)
{
    const size_t len1 = strlen(s1);
    const size_t len2 = strlen(s2);
    char *result = malloc(len1 + len2 + 1); 
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;
}

int main(int argc, char *argv[]){
  char com[50] = "sha3sum -a 512 ";
  FILE *fp = popen(concat(com, argv[1]), "r");
  char ou[600];
  fscanf(fp, "%s", ou);
  printf("%s\n", ou);
  pclose(fp);
}