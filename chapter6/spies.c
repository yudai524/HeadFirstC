#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node {
  char *question;
  struct node *no;
  struct node *yes;
} node;

int yes_no(char *question)
{
  char answer[3];

  printf("%s? (y/n): ", question);
  fgets(answer, 3, stdin);

  return answer[0] == 'y';
}


node* create(char *question)
{
  node *n = malloc(sizeof(node));

  n->question = strdup(question);
  n->no = NULL;
  n->yes = NULL;

  return n;
}

void release(node *n)
{
  if (n) {
    if (n->no)
      release(n->no);
    if (n->yes)
      release(n->yes);
    if (n->question)
      free(n->question);
    free(n);
  }
}

int main()
{
  char question[80];
  char suspect[20];
  node *start_node = create("容疑者はひげを生やしているか");
  start_node->no = create("ロレッタ・バーンすワース");
  start_node->yes = create("ペニー・ザ・スプーン");

  node *current;
  do {
    current = start_node;
    while (1) {
      if (yes_no(current->question))
      {
        if (current->yes) {
          current = current->yes;
        } else {
          printf("容疑者判明\n");
          break;
        }
      } else if (current->no) {
        current = current->no;
      } else {
        printf("容疑者は誰？");
        fgets(suspect, 20, stdin);
        node *yes_node = create(suspect);
        current->yes = yes_node;

        node *no_node = create(current->question);
        current->no = no_node;

        printf("%sに当てはまり、%sに当てはまらない質問は？", suspect, current->question);
        fgets(question, 80, stdin);

        free(current->question);
        current->question = strdup(question);

        break;
      }
    }
  } while(yes_no("再実行しますか？"));

  release(start_node);
  return 0;
}
