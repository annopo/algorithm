#include <stdio.h>
#include <time.h>

/*
 nが大きくなるとフィボナッチ数は
 非常に大きくなるので
 戻り値をunsignedlong型にする
*/

unsigned long fibo(int n) {
  if (n == 0 || n == 1)
    return 1;
  return fibo(n - 1) + fibo(n - 2);
}

int main() {
  int n;
  unsigned long f;
  clock_t start, end;

  printf("0から50未満の整数を入力してください。: ");
  scanf("%d", &n);

  if (n >= 50) {
    printf("数が大きすぎます。\n");
  } else if (n < 0) {
    printf("正しい数を入力してください。\n");
  } else {
    start = clock();
    f = fibo(n);
    end = clock();

    printf("Fibonacci sequence is %lu.\n", f);
    printf("Elapsed time: %.4f milisec.\n",
           (end - start) * 1000 / (double)CLOCKS_PER_SEC);
  }
  return 0;
}