
PC-G850 での動作を確認

プログラムの流し込みには、このUSBシリアルケーブルを使う。
http://tss.ram.ne.jp/product/pocket.html#e200usb

ドライバは、Windows7では自動的にインストールされるので、
特別にダウンロードする必要なし。

PuttyやTeratermで通信可能

半角カナが化けないためには、
    - TeratermのKanjicodeをSjisに設定
    - 受信するときは、Logファイルに書き出す
    - 送信は Send file

ポケコン側の設定:

    baud rate   = 9600
    data bit    = 8
    stop bit    = 1
    parity      = none
    end of line = CR LF
    end of file = 1A
    line number = no (c-lang) / yes(basic)
    flow        = Xon/Xoff



キーのチェック方法メモ

    key(0x0820) : Space
    key(0x1080) : Enter

    http://www.akiyan.com/pc-g850_technical_data
