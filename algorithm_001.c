#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double maximum(double *, int);

int main(int argc, char *argv[]) { /*コマンドライン引数を受け取る*/
  int n;
  n = atoi(argv[1]); /*char型をint型に変換する*/
  double *array, max;
  clock_t start, end;

  array = (double *)malloc(n * sizeof(double)); /*配列のメモリ確保*/

  srand((unsigned int)time(NULL)); /*乱数の初期化*/
  for (int i = 0; i < n; i++) {
    array[i] = rand();
  }

  start = clock();         /*実行時間計測開始*/
  max = maximum(array, n); /*最大値を求める関数呼び出し*/
  end = clock();           /*実行時間計測終了*/

  printf("Maximum number is %lf\n", max);
  printf("Elapsed time: %.2f milisec.\n",
         (end - start) * 1000 / (double)CLOCKS_PER_SEC);
  return EXIT_SUCCESS;
}

double maximum(double *array, int n) {
  double max = array[0]; /*配列の最初の要素を最大値と仮定する*/

  for (int i = 1; i < n; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  return max;
}