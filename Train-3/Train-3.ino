/* 今度は関数を作ってみる */

void setup() {
  /* 計算結果を見れるようにシリアル通信を使いたいので，これを実行してシリアル通信を有効にする */
  /* Ctrl + Shift + M でシリアルモニタを開いておこう */
  Serial.begin(9600);
  delay(250);

  /* 適当な定数 x を代入する．実行するごとに変えてみよう */
  float x = 2.5;

  /* 関数に値を渡して呼び出し，計算を実行する */
  float y = f(x);

  /* ここでの x と f() の関数の中での x, y は結果として同じ値になるが，CPU から見れば全くの別物 */
  /* つまり， float a = 1.5; float n = f(a); などとしても問題ない */

  /* 計算結果をシリアルモニタに表示する */
  Serial.print("f(");
  Serial.print(x);
  Serial.print(") = ");
  Serial.print(y);
  Serial.print("\n");
}  

void loop() {
}

/* 何かしらの x の式を実装してみる */
/* ここでは f(x) = 4x^2 + 6x - 10 を実装する */
float f(float x) {
  /* 計算結果を代入する変数を用意 */
  float y;

  /* 計算する */
  y = 4 * x * x + 6 * x - 10;

  /* 計算結果を戻す */
  return y;
}
