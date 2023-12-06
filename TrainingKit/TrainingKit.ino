/* デバッグ処理の有効無効を制御する定義文 */
#define DEBUG

/* ピンアサインの定義 */
#define ShiftRegister_IN  4
#define ShiftRegister_CLK 2
#define ShiftRegister_SET 3

/* 各種グローバル変数 */
uint8_t num_to_bin[] = {0b11111100, 0b01100000, 0b11011010, 0b11110010,   // 0, 1, 2, 3
                        0b01100110, 0b10110110, 0b10111110, 0b11100100,   // 4, 5, 6, 7
                        0b11111110, 0b11110110, 0b11101110, 0b00111110,   // 8, 9, A, b
                        0b00011010, 0b01111011, 0b10011110, 0b10001110};  // c, d, E, F

volatile uint8_t LED_VRAM = 0;

void setup() {
  GPIO_Init();
  LED_Init();
  delay(1000);
}

void loop() {
  for(uint8_t i = 0; i < sizeof(num_to_bin); i++) {
    LED_VRAM = i;
    /* 7 セグメント LED を光らせる */
    LED_Flash();

    delay(500);
  }
}

/* 74HC595 で使用する GPIO の初期化をする関数 */
void GPIO_Init(void) {
  pinMode(ShiftRegister_IN , OUTPUT);  digitalWrite(ShiftRegister_IN ,  LOW);
  pinMode(ShiftRegister_CLK, OUTPUT);  digitalWrite(ShiftRegister_CLK,  LOW);
  pinMode(ShiftRegister_SET, OUTPUT);  digitalWrite(ShiftRegister_SET,  LOW);
}

/* シフトレジスタの中身をクリアする関数 */
void LED_Init(void) {
  LED_OUT(0x00);
}

/* シフトレジスタにデータを送る */
void LED_Flash(void) {
  uint8_t data = num_to_bin[LED_VRAM];
  
  /* 独自実装の shiftOut 関数 */
  for(uint8_t i = 0; i < 8; i++) {
    digitalWrite(ShiftRegister_IN , (data & 1 << i) == 0 ? 0 : 1);
    digitalWrite(ShiftRegister_CLK, HIGH);
    digitalWrite(ShiftRegister_CLK,  LOW);
  }
  digitalWrite(ShiftRegister_SET, HIGH);
  digitalWrite(ShiftRegister_SET,  LOW);
}

/* ラッパー関数 */
void LED_OUT(uint8_t data) {
  LED_VRAM = data;
  LED_Flash();
}