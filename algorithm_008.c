#include <stdbool.h>
#include <stdio.h>

#define N 14 // 地点の数

int main() {

  /*
  　　地点間の距離が格納されている二次元配列Distance[i][j]
  　　※1 地点iと地点jが同一の地点の場合は0が格納されている
  　　※2 地点iと地点jが隣接地点でない場合は-1が格納されている
　*/
  int Distance[N][N] = {
      {0, 1, -1, -1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1}, // v0
      {1, 0, 2, -1, -1, -1, -1, -1, -1, -1, -1, 1, -1, -1},  // v1
      {-1, 2, 0, 5, -1, -1, -1, -1, -1, -1, -1, -1, 4, -1},  // v2
      {-1, -1, 5, 0, 8, -1, -1, -1, -1, -1, -1, -1, 8, 1},   // v3
      {-1, -1, -1, 8, 0, 2, -1, -1, -1, -1, -1, -1, -1, -1}, // v4
      {-1, -1, -1, -1, 2, 0, 1, -1, 6, -1, -1, -1, 2, -1},   // v5
      {-1, -1, -1, -1, -1, 1, 0, 2, -1, -1, -1, -1, -1, -1}, // v6
      {-1, -1, -1, -1, -1, -1, 2, 0, 1, -1, -1, -1, -1, -1}, // v7
      {-1, -1, -1, -1, -1, 6, -1, 1, 0, 5, -1, -1, -1, 3},   // v8
      {-1, -1, -1, -1, -1, -1, -1, -1, 5, 0, 2, 3, 7, 1},    // v9
      {3, -1, -1, -1, -1, -1, -1, -1, -1, 2, 0, 6, -1, -1},  // v10
      {-1, 1, -1, -1, -1, -1, -1, -1, -1, 3, 6, 0, 5, -1},   // v11
      {-1, -1, 4, 8, -1, 2, -1, -1, -1, 7, -1, 5, 0, 1},     // v12
      {-1, -1, -1, 1, -1, -1, -1, -1, 3, 1, -1, -1, 1, 0}    // v13
  };

  int nPoint = N; // 地点の数
  int startPoint; // 出発地の地点番号
  int goalPoint;  // 目的地の地点番号

  printf("出発地の地点番号を入力してください: ");
  scanf("%d", &startPoint);

  printf("目的地の地点番号を入力してください: ");
  scanf("%d", &goalPoint);

  // 出力変数sRouteとsDistを定義
  int shortestRoute
      [nPoint]; // 出発地から目的地までの最短経路上の地点の地点番号を目的地から出発地の順に設定する1次元配列
  int shortestDist; // 出発地から目的地までの最短距離

  /* その他使う変数 */
  int pDist[nPoint]; // 出発地から各地点までの最短距離を設定する配列
  int pRoute[nPoint];
  bool pFixed
      [nPoint]; // 出発地から各地点までの最短距離が確定しているかどうかを識別するための配列
  int sPoint, i, j, newDist;

  shortestDist =
      99999; // 出発地から目的地までの最短距離に初期値を格納する（変更しなくてよい）

  for (i = 0; i < nPoint; i++) {
    shortestRoute[i] = -1; // 最短経路上の地点の地点番号に初期値を格納する
    pDist[i] = 99999; // 出発地から各地点までの最短距離に初期値を格納する
    pFixed[i] = false; // 各地点の最短距離の確定状態に初期値を格納する
  }

  pDist[startPoint] = 0; // 出発地から出発地自体への最短距離に0を設定する

  while (true) { // 最短経路探索処理
    i = 0;
    while (i < nPoint) { // 未確定の地点を1つ探す
      if (pFixed[i] == 0) {
        break;
      }
      i = i + 1;
    }

    if (i ==
        nPoint) { // 出発地から全ての地点までの最短経路が確定していれば最短経路探索処理を抜ける
      break;
    }

    for (j = i + 1; j < nPoint; j++) { // 最短距離がより短い地点を探す
      if ((pFixed[j] == 0) && (pDist[j] < pDist[i])) {
        i = j;
      }
    }

    sPoint = i;
    pFixed[sPoint] = true; // 出発地からの最短距離を確定する

    for (j = 0; j < nPoint; j++) {
      if ((Distance[sPoint][j] > 0) && (pFixed[j] == 0)) {
        newDist = pDist[sPoint] + Distance[sPoint][j];
        if (newDist < pDist[j]) {
          pDist[j] = newDist;
          pRoute[j] = sPoint;
        }
      }
    }
  }

  shortestDist = pDist[goalPoint];
  j = 0;
  i = goalPoint;
  while (i != startPoint) {
    shortestRoute[j] = i;
    i = pRoute[i];
    j = j + 1;
  }
  shortestRoute[j] = startPoint;

  printf("出発地から目的地までの最短経路: ");
  for (i = j; i >= 0; i--) {
    printf("v%d,", shortestRoute[i]);
  }

  printf("\n出発地から目的地までの最短距離: %d\n", shortestDist);

  return 0;
}