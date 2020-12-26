#include <stdio.h>
#include <time.h>

/*
 nが大きくなるとフィボナッチ数は
 非常に大きくなるので
 戻り値をunsignedlong型にする
*/

unsigned long fibo1(int n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return fibo1(n - 1) + fibo1(n - 2);
  }
}

unsigned long fibo2(int n) {
  unsigned long x, y, z;
  x = y = 1;
  z = 0;
  if (n == 0 || n == 1) {
    return 1;
  } else {
    for (int i = 2; i <= n; i++) {
      z = x + y;
      x = y;
      y = z;
    }
    return z;
  }
}

int main() {
  int n;
  clock_t start, end;

  // 引数が50より大きな数だと実行時間がかかりすぎるため50以下にする
  printf("50以下の自然数を入力してください。: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("正しい数を入力してください。\n");
  } else if (n > 50) {
    printf("数が大きすぎます。\n");
  } else {
    start = clock();
    printf("Fibo1 sequence is %lu.\n", fibo1(n));
    end = clock();
    printf("Fibo1's elapsed time: %.4f milisec.\n",
           (end - start) * 1000 / (double)CLOCKS_PER_SEC);

    start = clock();
    printf("Fibo2 sequence is %lu.\n", fibo2(n));
    end = clock();
    printf("Fibo2's elapsed time: %.4f milisec.\n",
           (end - start) * 1000 / (double)CLOCKS_PER_SEC);
  }
  return 0;
}