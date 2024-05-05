# 使い方

1. とりあえず書き込んで実行してみる
2. マクロ定義で設定されている変数を変えてみる
   - `waitTime` と `TimerInt` の二箇所

# 説明

マクロ定義と配列まではこれまでの通りだが，新たに `#include` というものが出てきている  
これは，ライブラリという，便利な関数たちをまとめた辞書のようなものを，文字通りインクルードしてくれる機能である．ここでは，`MsTimer2` というライブラリを読み込んでいる

あたらな修飾子がついた変数も用意されている．これは，タイマー割り込みなどにより，予期せぬ方法で値が変更される可能性があるということをコンパイラに教えるために使用する

`setup()` 関数では，諸々の初期化を行っている．それぞれ何をやっているのかはそれぞれの関数の実装を眺めてみて欲しい

`loop()` 関数では，`LED_VRAM` という変数に LED を光らせるためのデータを配列から呼び出し，代入するという作業を行っている  
普通はこれだけだとただ値が代入されるだけだが，このプログラムでは「タイマー割り込み」により一定時間ごとにある関数が実行されている．その関数が `LED_Flash()` 関数である  
この関数の中で，`LED_VRAM` から値を取り出し，シフトレジスタに送信するということをやっている．これにより，データの送信は勝手にやってくれるので，ただ変数を更新するだけで，表示を変更することができるようになっている．便利