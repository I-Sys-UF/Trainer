/* まずは配列の書き方を知ろう */
uint8_t array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

/* 配列を構成する数字を変えて実行してみよう */

void setup() {
  /* シリアル通信を開始 */
  Serial.begin(115200);
  delay(250);

  /* INDEX の値を 0 ~ 9 で変えて実行してみよう */
  uint8_t INDEX = 4;
  char buffer[32];  // 実はこれ（文字列）も配列でできている
  sprintf(buffer, "INDEX = %d\narray[INDEX] = %d\n", INDEX, array[INDEX]);
  Serial.print(buffer);
}

void loop() {
}
