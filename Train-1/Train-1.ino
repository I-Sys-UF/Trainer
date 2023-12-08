/* こうやって書くとコンパイル前に LED_D1 という文字列を 10 という定数に置き換えてくれる */
#define LED_D1 10
#define LED_D2 11

/* HIGH や LOW を書き換えて実行してみよう */
#define LED_D1_STATUS HIGH
#define LED_D2_STATUS  LOW

void setup() {
  /* ここに書いたコードは起動時に一度だけ実行される */

  /* LED が繋がっている GPIO を出力に設定する */
  pinMode(LED_D1, OUTPUT);
  pinMode(LED_D2, OUTPUT);

  digitalWrite(LED_D1, LED_D1_STATUS);
  digitalWrite(LED_D2, LED_D2_STATUS);
}

void loop() {
  /* ここにコードを書くと無限に実行し続けてくれるが，今回は何も実行しない */
}