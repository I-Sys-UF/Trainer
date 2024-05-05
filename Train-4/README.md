# 使い方

1. とりあえず書き込んで実行してみる
2. `uint8_t data = 0b11111111;` のところを自由に変えて遊んでみる
3. `NUM0` ~ `NUM9` に当てはまる数字を考えてみる

# 説明

ここでは基板上の大部分を占めている，7 セグメント LED を操作するということをやります

操作するのに使用する関数を作れというのは流石に酷なので，用意しました．`LED_OUT()` という関数がありますがそれです．ここに 8bit の数字を渡すと，その数字をシフトレジスタに送信し，LED を駆動するトランジスタアレイをオンオフします．なので，7 セグメント LED を駆動できる形式のデータが必要になります．つまり，単純に `LED_OUT(7)` とすれば `7` が表示されるわけではありません．これは実際にやってみるとわかると思います

そこで，まずはそのまま実行し，すべての LED が光ることを確認してください．その後，8 桁のうちどれか一桁だけを 1 にして（ビットを立てて，と表現します）実行する．というのを，場所を変えて 8 回やってみてください．そうすると，どのビットがどのセグメントに対応するかがわかるはずです  
それがわかったら，`0` ~ `9` の数字を表現するにはどこを光らせるといいかを考え，そのためにはどのようなデータを送ればいいかを考え，用意された変数に保存してみてください．そうすれば，その変数を使うことで，`LED_OUT(NUM7)` とすれば `7` と表示されるはずです

次の `Train-5` で配列を学習し，その次 `Train-6` でその配列を使って使いやすくするということを行います  
`Train-6` に手を付けるまでに `NUM0` ~ `NUM9` に当てはまる数字を探してください