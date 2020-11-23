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

// クイックソートをする関数
void quickSort(int array[], int left, int right) {
  int Left, Right;
  int pivot;

  // 初期値は引数にする
  Left = left;
  Right = right;

  // 基準は真ん中に設定する
  pivot = array[(left + right) / 2];

  // ソーティング
  while (1) {

    // 基準より小さい値を左から見つけていく
    while (array[Left] < pivot)
      Left++;

    // 基準より大きい値を右から見つけていく
    while (array[Right] > pivot)
      Right--;

    // 見つかった値の順序が逆になったら終了
    if (Left >= Right)
      break;

    // 値を交換する
    swap(&array[Left], &array[Right]);

    // 次の値に移動
    Left++;
    Right--;
  }

  // 左のデータ群を対象にクイックソートを再帰
  if (left < Left - 1)
    quickSort(array, left, Left - 1);

  // 右のデータ群を対象にクイックソートを再帰
  if (Right + 1 < right)
    quickSort(array, Right + 1, right);
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
  quickSort(sort, 0, N - 1);
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