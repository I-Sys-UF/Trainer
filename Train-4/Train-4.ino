/* ピンアサインの定義 */
#define ShiftRegister_IN  4
#define ShiftRegister_CLK 2
#define ShiftRegister_SET 3

/* もし表示が数字になるようなデータを見つけれたら，下の変数に保存しよう */
uint8_t NUM0 = 0b0;
uint8_t NUM1 = 0b0;
uint8_t NUM2 = 0b0;
uint8_t NUM3 = 0b0;
uint8_t NUM4 = 0b0;
uint8_t NUM5 = 0b0;
uint8_t NUM6 = 0b0;
uint8_t NUM7 = 0b0;
uint8_t NUM8 = 0b0;
uint8_t NUM9 = 0b0;

void setup() {
  /* 74595 と繋がっている GPIO の初期化 */
  pinMode(ShiftRegister_IN , OUTPUT);  digitalWrite(ShiftRegister_IN ,  LOW);
  pinMode(ShiftRegister_CLK, OUTPUT);  digitalWrite(ShiftRegister_CLK,  LOW);
  pinMode(ShiftRegister_SET, OUTPUT);  digitalWrite(ShiftRegister_SET,  LOW);

  /* 表示をクリアする */
  LED_OUT(0x00);

  /* 二進数 8 桁で好きな値を表現してみよう．10 進数でどうなるかを考える必要はない */
  /* 一つだけ 1 にした状態で実行し，どのセグメントが光るかやってみよう */
  uint8_t data = 0b11111111;

  /* 74595 にデータを送る */
  LED_OUT(data);
}

void loop() {
}

/* この関数の中身については理解できなくても大丈夫 */
void LED_OUT(uint8_t data) {
  for(uint8_t i = 0; i < 8; i++) {
    digitalWrite(ShiftRegister_IN , (data & 1 << i) == 0 ? 0 : 1);
    digitalWrite(ShiftRegister_CLK, HIGH);
    digitalWrite(ShiftRegister_CLK,  LOW);
  }
  digitalWrite(ShiftRegister_SET, HIGH);
  digitalWrite(ShiftRegister_SET,  LOW);
}