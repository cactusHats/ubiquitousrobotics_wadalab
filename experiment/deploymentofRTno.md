# RTno
## 概要
- Arduinoと通信するためのRTC
## 詳細ページ
- http://ysuga.net/?p=124

# 導入手順
## インストール
- Arduino用ライブラリ
- RTno(RTC)ソースコード

## Arduino側準備
- ArduinoのlibrariesにDLしたフォルダごと移動
- Arduino IDE再起動
- RTnoのサンプルプログラム確認完了

### プログラム修正
- Arduino1.8.13に更新
- SPI.hが見つからないエラーが出るものの，パスを修正したらビルドできた．
- RTno > EtherTcp.cppの  
#include <../SPI/SPI.h>  
#include <../Ethernet/Ethernet.h>  
を，それぞれ  
#include <../../hardware/arduino/avr/libraries/SPI/src/SPI.h>  
#include <../Ethernet/src/Ethernet.h>  
に変更．  

## RTC側準備
- サイトの「インストール」タブに，色々あってよく分からなかったけど，vsから普通にやる場合はwinのインストーラ等は不要と見た．
- GitHubからコードをDLして，cmake，問題なし．

### プログラム修正
- ビルドするとエラー．
- RTnoProfile.hの
const bool operator==(const PortProfile& p) {  
という関数をconst関数に変更．  
const bool operator==(const PortProfile& p) const {  
- このまま実行すると，Arduinoを認識できず，コンソール画面が閉じる．  

1. rtc.confをbuild/srcフォルダにコピー
2. RTnoProxy.confのCOMポートの設定を有効化
3. RTnoProxy.cppの38行目のCOM10をCOM6へ変更（デバイスマネージャでCOM番号チェック）
4. ビルドし直してもう一度実行すると，先に進めた．

- 正常時のコンソール出力画面  
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
