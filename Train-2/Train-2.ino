/* LED と，繋がっている GPIO の対応を定義 */
#define LED_D1 11
#define LED_D2 10

/* スイッチと，繋がっている GPIO の対応を定義 */
#define SW1 5
#define SW2 6

/* スイッチが押されている状態での GPIO の状態を定義しておく */
#define SW_isPressed LOW

void setup() {
  /* LED が繋がっている GPIO を出力に設定する */
  pinMode(LED_D1, OUTPUT);
  pinMode(LED_D2, OUTPUT);

  /* スイッチが繋がっている GPIO を入力に設定し，内部プルアップ抵抗を有効にする */
  pinMode(SW1,  INPUT_PULLUP);
  pinMode(SW2,  INPUT_PULLUP);

  /* まずは以下の通り実行する */
  /* 実行できたら，true と false を入れ替えてみたり好きに変えてみたりする */
  if(true) {
    digitalWrite(LED_D1, HIGH);
  }else {
    digitalWrite(LED_D1,  LOW);
  }

  if(false) {
    digitalWrite(LED_D2, HIGH);
  }else {
    digitalWrite(LED_D2,  LOW);
  }

  /* if 文の挙動が理解できたら下の行をコメントアウトしよう */
  while(true);
}

void loop() {
  /* スイッチの状態を保存する変数を用意する */
  uint8_t SW1_Status, SW2_Status;

  /* スイッチの状態を読み取り，変数に保存する */
  SW1_Status = digitalRead(SW1);
  SW2_Status = digitalRead(SW2);
  
  /* スイッチの状態に応じて LED を光らせる */
  if(SW1_Status == SW_isPressed) {
    digitalWrite(LED_D1, HIGH);
  }else {
    digitalWrite(LED_D1,  LOW);
  }

  if(SW2_Status == SW_isPressed) {
    digitalWrite(LED_D2, HIGH);
  }else {
    digitalWrite(LED_D2,  LOW);
  }
}