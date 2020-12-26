#include <iostream>
#include <stack>
using namespace std;

int main() {
  stack<char> st;   //スタック
  char open = '(';  //開き括弧
  char close = ')'; //閉じ括弧
  char in;          //入力
  char R;           //ポップした閉じかっこ入れ
  cout << "カッコの文字列を入力してください。\n";

  //最初の一文字をとる
  in = cin.get();

  while (in != '\n') {
    // 開きカッコの時
    if (in == open) {
      st.push(in);
    }
    // 閉じカッコの時
    else if (in == close) {
      //閉じカッコかつスタックが空の時、開きかっこ不足
      if (st.empty()) {
        cout << "開き括弧が不足です。\n";
        return 0;
      }
      //閉じカッコかつスタックが空じゃないとき
      else {
        // Rにポップした閉じカッコを入れる
        R = st.top();
        st.pop();
      }
    }
    // inが開きカッコでも閉じカッコでもないとき
    //次の一文字を読む
    in = cin.get();
    //ここまで終わってスタックが空ではないとき、閉じかっこ不足
    if (!st.empty()) {
      cout << "閉じ括弧が不足です。\n";
      return 0;
    }
    //上記すべてに当てはまらないとき、カッコの対応が取れている
    cout << "括弧の対応が取れています。\n";
  }
}
