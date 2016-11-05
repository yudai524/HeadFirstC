#include <stdio.h>

typedef struct island {
  char *name;
  char *opens;
  char *closes;
  struct island *next;
} island;

void display(island *start)
{
  island *i = start;
  
  for (;i != NULL; i = i->next) {

    printf("名前：%s 営業時間：%s-%s\n", i->name, i->opens, i->closes);
  }
}

int main() {
  island amity = {"アミティ", "09:00", "17:00", NULL};
  island craggy = {"クラっギー", "09:00", "17:00", NULL};
  island isla_nublar = {"イスラぬブラる", "09:00", "17:00", NULL};
  island shutter = {"シャッター", "09:00", "17:00", NULL};

  amity.next = &craggy;
  craggy.next = &isla_nublar;
  isla_nublar.next = &shutter;

  island skull = {"スカル", "09:00", "17:00", NULL};

  isla_nublar.next = &skull;
  skull.next = &shutter;

  display(&amity);
}
