# 今日やったこと
- タスクの細分化
- アイディア共有
- Arduino用RTC探し->

# 今日解決すること
## 技術面
- 離れたPC同士を接続できないか?
- 研究室から発表してもいいか?

# タスク
## 遠隔の問題
- お互いのPCどうやってつなぐ?
- 環境構築
## コンポーネント作成
### Arduino RTC(ちょい変更)
- Arduinoと通信するRTC
- アナログ入力ポートから電圧を読みとる．
- シリアル通信で数値送信．
- 出力：風速データ0-100%(TimedLong)
### 電圧速度換算RTC(新規)
- 入力：Arduinoからの電圧値(TimedLong)
- 出力：速度データ(TimedVelocity~~)
- 決め打ちで調整．
### 勝敗RTC(新規)
- 2台のラズパイマウスの距離データを監視．
- どちらが壁に近付いたかを判定．

## 入力デバイス
### 土台
- 適当に3Dプリンタで作成
### 電子回路
- モータ->オペアンプ->Arduino

## 動作テスト
### ハード
- 団扇でモータ回るか?
- 電圧値取得できるか?
### ソフト
- 電圧速度変換できてるか?
- ラズパイマウス動くか?
- 勝敗判定できるか?

## 報告準備
- パワーポイント
- 報告手順確認

# アイディア共有のフィードバック
## 遠隔で繋げる方法
- サーバ(sakuraとか?)を借りて，お互いにvpn接続でつなぐ．
- 同じネットワーク内でやるのと同じ感じにできる．
- Dropboxにエクセルファイル置いておいて，データを取りに行く．
## マウスの台数
- 2台だとシミュレータ改造しないといけない．
- 1台ならそのまま使える．
- 勉強になると思うので見てみてください．
## コメント
- 遠隔で各人の家からできたらおもしろいね
- vpn接続の場合，風量データ送信頻度は0.1sや0.5sぐらいにしておいた方が良い．
## 所感
- 斜め上の所を狙えたようで良かった．

# 変更点
- ラズパイマウスは1台とする
- 距離センサのデータではなく，オドメトリデータ(位置情報)で勝敗決定．
- スタート地点から一定距離離れたら...

# 次回までに
## RTCを完成させる(各自)
- Arduino RTC(関)
- 電圧速度換算RTC(黒川)
- 勝敗RTC(叶)
## Arduinoまわり組み上げる(関)






