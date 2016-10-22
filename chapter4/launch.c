#include <stdio.h>
#include "launch.h"
#include "thruster.h"


int main()
{
  char name[20];
  thruster(name);

  printf("%s\n", name);


  return 0;
}
