#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  srand(time(NULL));
  int a[100], row_terms[101] ={0,}, starting_pos[101], sorted[100];

  printf("배열 a: [");
  for (int i = 0; i < 100; i++) {
    a[i] = rand() % 101;//0~100
    if(i%10==0)printf("\n");
    printf("%d ", a[i]);
    row_terms[a[i]]++;
  }
  printf("]\n");

  printf("배열 rowt_terms : [");
  for (int i = 0; i < 101; i++) {
    printf("%d ", row_terms[i]);
  }
  printf("]\n");

  starting_pos[0] = 0;
  printf("배열 starting_pos : [ %d ", starting_pos[0]);
  for (int i = 1; i < 101; i++) {
    starting_pos[i] = row_terms[i - 1] + starting_pos[i - 1];
    printf("%d ", starting_pos[i]);
  }
  printf("]\n");

  for (int i = 0; i < 100; i++) {
    sorted[starting_pos[a[i]]] = a[i];
    starting_pos[a[i]]++;
  }
  printf("배열 sorted : [");
  for (int i = 0; i < 100; i++) {
    printf("%d ", sorted[i]);
  }
  printf("]\n");
}
