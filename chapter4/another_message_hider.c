#include <stdio.h>
#include "encrypt.h"

int main()
{
  char msg[80];
  printf("暗号化する文字列を入力して下さい。：");
  while (fgets(msg, 80, stdin)) {
    encrypt(msg);
    printf("%s", msg);
  }
}

