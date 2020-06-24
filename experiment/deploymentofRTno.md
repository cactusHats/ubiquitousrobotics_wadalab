# RTno
## 概要
- Arduinoと通信するためのRTC
## 詳細ページ
- http://ysuga.net/?p=124

# 導入
## インストール
- Arduino用ライブラリ
- RTno(RTC)ソースコード

## Arduino側準備
- ArduinoのlibrariesにDLしたフォルダごと移動
- Arduino IDE再起動
- サンプルプログラムにRTno見れた
- 完了

- Arduino側にもコードを書き込んでみる．
- エラー...

C:\Program Files (x86)\Arduino\libraries\RTno\EtherTcp.cpp:3:10: fatal error: ../SPI/SPI.h: No such file or directory
 #include <../SPI/SPI.h>
          ^~~~~~~~~~~~~~
compilation terminated.

- SPI.hが無いらしい．
- 確かに入ってるの小文字でspi.hだったけど，この..の意味が分からない．

- サイトに書いてあったので，RTnoProxy.confの中のポート設定の所をwinのを有効にして，macのを無効にした．

### 解決
- Arduino1.8.13に更新
- SPI.hが見つからないエラーが出るものの，パスを修正したらビルドできた．
- RTno > EtherTcp.cppの
- #include <../SPI/SPI.h>
- #include <../Ethernet/Ethernet.h>
- を，それぞれ
- #include <../../\hardware\arduino\avr\libraries\SPI\src\SPI.h>
- #include <../Ethernet/src/Ethernet.h>
- に変更．

## RTC側準備
- サイトの「インストール」タブに，色々あってよく分からなかったけど，vsから普通にやる場合はwinのインストーラ等は不要と見た．
- それがない人はインストーラからでも出来ますよ的な感じだろう．
- GitHubからコードをDLして，cmake，問題なし．
- ビルドするとエラー．

- RTnoProfile.hの
- const bool operator==(const PortProfile& p) {
- という関数をconst関数に変更．
- const bool operator==(const PortProfile& p) const {

- このまま実行すると，エラー出てコンソール画面が閉じてしまう．

- rtc.confをbuild/srcフォルダにコピー
- RTnoProxy.cppの38行目のCOM10をCOM6へ変更（デバイスマネージャでCOM番号チェック）
- ビルドし直してもう一度実行すると，先に進めた・

[RTnoProxy] Configuration Values
[RTnoProxy]  - conf.default.connectionType:serial
[RTnoProxy]  - Serial Port Connection
[RTnoProxy]     - conf.default.comport:\\.\COM6
[RTnoProxy]     - conf.default.baudrate:57600
[RTnoProxy] Opening SerialPort(\\.\COM6)..... [RTnoProxy] Opened.
[RTnoProxy] Waiting for Startup the arduino...
[RTnoProxy]  - 3......
[RTnoProxy]  - 2....
[RTnoProxy]  - 1..
[RTnoProxy]  - Go!
[RTnoProxy] Starting up onInitialize sequence.
[RTnoProxy]  - RTnoProtocol::getRTnoProfile() called.
[RTnoProxy]     - Transfer Profile Request to Arduino.



# メモ
- ARnoはいじらないでそのまま使った方が良さそう．
- TimedLong型の配列データが出てくるはずだから，それを受け取って，平滑化するためのコンポーネントを作るか...
