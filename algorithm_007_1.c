#include <stdio.h>
#include <stdlib.h>
#define N 1000 // スタックに入るデータの上限を1000にする

// スタック構造体
typedef struct {
  int *Data;
  int Size;  // 最大格納数
  int Count; // 現在の格納数
} Stack;

// スタックの作成
Stack *CreateStack(int size) {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  s->Data = (int *)malloc(sizeof(int) * size);
  s->Size = size;
  s->Count = 0;
  return s;
}

// エラーチェック付malloc
void *mallocx(int size) {
  void *p = malloc(size);
  if (p == NULL) {
    printf("cannot allocate memory\n");
    exit(1);
  }
  return p;
}

// スタックの廃棄
void DisposeStack(Stack *s) {
  free(s->Data);
  free(s);
}

// スタックにデータを追加する関数
void push(Stack *s, int x) {
  if (s->Count == s->Size) {
    printf("stack overflow\n");
    exit(1);
  }
  s->Data[s->Count] = x;
  s->Count++;
}

// スタックからデータを取り出す関数
int pop(Stack *s) {
  if (s->Count == 0) {
    printf("stack underflow\n");
    exit(1);
  }
  s->Count--;
  return s->Data[s->Count];
}

int main(void) {
  char array[N];
  printf("Input ()strings.");
  for (int i = 0; i < N; i++) {
    scanf("%d", &array[i]);
  }
  for (int j = 0; j < N; j++) {
    if (array[j] == "(") {
      j++;
    } else if (array[j] == ")") {
      j--;
      printf('[' + j+1 + ',' +  
    }
  }
}