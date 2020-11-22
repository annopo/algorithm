#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define PRINT 1 // Nが大きな値の時は0にする
#define CHECK 1 // ソートのチェックを行う

int sort[N];

void swap(int *x, int *y) {
  int tmp; // 値を一時保存する変数

  tmp = *x;
  *x = *y;
  *y = tmp;
}

// バブルソートをする関数
void bubbleSort(int array[], int array_size) {
  int i, j;

  for (i = 0; i < array_size - 1; i++) {
    for (j = array_size - 1; j >= i + 1; j--) {
      if (array[j] < array[j - 1]) {
        swap(&array[j], &array[j - 1]);
      }
    }
  }
}

int main(void) {
  int i, j, t;
  srand((unsigned int)time(NULL));
  // Fisher-Yatesアルゴリズムで1~Nのランダムな数列を構築する
  for (i = 0; i < N; i++) {
    sort[i] = i + 1;
  }
  for (i = N - 1; i > 0; i--) {
    j = rand() % (i + 1);
    t = sort[i];
    sort[i] = sort[j];
    sort[j] = t;
  }
  if (PRINT) {
    for (i = 0; i < N; i++) {
      printf("%d ", sort[i]);
    }
    printf("\n");
  }

  clock_t start, end;
  start = clock();
  printf("Sort start...");
  // ソートを行う関数の呼び出し
  bubbleSort(sort, N);
  printf("Sort end.\n");
  end = clock();

  if (PRINT) {
    for (i = 0; i < N; i++) {
      printf("%d ", sort[i]);
    }
    printf("\n");
  }
  printf("Elapsed time: %.2f milisec.\n",
         (end - start) * 1000 / (double)CLOCKS_PER_SEC);

  if (CHECK) {
    for (i = 0; i < N - 1; i++) {
      if (sort[i] > sort[i + 1]) {
        printf("*** Not sorted ***\n");
        break;
      }
    }
  }
  return EXIT_SUCCESS;
}
