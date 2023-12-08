/* スイッチと，繋がっている GPIO の対応を定義 */
#define SW1 5
#define SW2 6

/* LED と，繋がっている GPIO の対応を定義*/
#define LED_D1 10
#define LED_D2 11

/* スイッチの状態ごと GPIO の状態を定義しておく */
#define SW_isPressed   LOW
#define SW_isReleased HIGH

/* 数字をバイナリに変換する配列 */
uint8_t num_to_bin[] = {0b11111100, 0b01100000, 0b11011010, 0b11110010,   // 0, 1, 2, 3
                        0b01100110, 0b10110110, 0b10111110, 0b11100100,   // 4, 5, 6, 7
                        0b11111110, 0b11110110, 0b11101110, 0b00111110,   // 8, 9, A, b
                        0b00011010, 0b01111011, 0b10011110, 0b10001110};  // c, d, E, F

void setup() {
  /* LED が繋がっている GPIO を出力に設定する */
  pinMode(LED_D1, OUTPUT);
  pinMode(LED_D2, OUTPUT);

  /* スイッチが繋がっている GPIO を入力に設定し，内部プルアップ抵抗を有効にする */
  pinMode(SW1,  INPUT_PULLUP);
  pinMode(SW2,  INPUT_PULLUP);
}

void loop() {
  /* スイッチの状態を保存する変数を用意する */
  /* 頭の static については正常に動作させるために必要なものと思っておこう */
  static uint8_t SW1_Status_Old, SW1_Status_New, SW2_Status_Old, SW2_Status_New;

  /* カウンター変数を用意する．頭の static については以下同文 */
  static int8_t counter;

  /* スイッチの状態の変数を更新する */
  SW1_Status_Old = SW1_Status_New;
  SW2_Status_Old = SW2_Status_New;
  SW1_Status_New = digitalRead(SW1);
  SW2_Status_New = digitalRead(SW2);

  /* "押された瞬間" はつまり 一つ前は押されてなくて今は押されているということになる */
  if((SW1_Status_Old == isReleased) && (SW1_Status_New == isPressed)) {
    counter++;  // これで 1 加算される（インクリメント演算子）
    digitalWrite(LED_D1, HIGH);  // 押された瞬間に LED を光らせる
  }else {
    digitalWrite(LED_D1, HIGH);  // LED を消す
  }

  if((SW1_Status_Old == isReleased) && (SW1_Status_New == isPressed)) {
    counter--;  // これで 1 減算される（デクリメント演算子）
    digitalWrite(LED_D2, HIGH);  // 押された瞬間に LED を光らせる
  }else {
    digitalWrite(LED_D1,  LOW);  // LED を消す
  }

  /* オーバーフローを防止する */
  if(counter < 0) {
    counter = 0;
  }
  
  if(counter > 15) {
    counter = 15;
  }

  /* 7 セグに表示する */
  LED_OUT(num_to_bin[counter]);

  /* 少し待つ */
  delay(25);
}
