#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define PRINT 1 // Nが大きな値の時は0にする
#define CHECK 1 // ソートのチェックを行う

int sort[N];

// 値を入れ替える関数
void swap(int *x, int *y) {
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int partition(int array[], int left, int right) {
  int pivot = array[right]; // 配列の最後の要素をpivotとする
  int i = left - 1;

  for (int j = 1; j <= right - 1; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[right]);
  return (i + 1);
}

// クイックソートをする関数
void quickSort(int array[], int left, int right) {
  if (left < right) {
    int pivot = partition(array, left, right);
    quickSort(array, left, pivot - 1);
    quickSort(array, pivot + 1, right);
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
  quickSort(sort, 1, N);
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
