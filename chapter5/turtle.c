#include <stdio.h>

typedef struct {
  const char *name;
  const char *species;
  int age;
} turtle;

void happy_birthday(turtle *t)
{
  t->age = t->age + 1;
  printf("誕生日おめでとう,%s！これで%i歳ですね！\n", t->name, t->age);
}

int main()
{
  turtle myrtle = {"マートル", "オサガメ", 99};
  happy_birthday(&myrtle);
  printf("%sの年齢は%i歳です\n", myrtle.name, myrtle.age);
  return 0;
}
