# Pricer-for-BSmodel

ビルド済みの実行ファイルは ./pricer となります。

# オプション価値の求め方について

call option value = e^{-rT} E(（S exp{(r-sigma^2/2)T + sigma * sqrt(T) * W} - K)^{+}]  
put option value = e^{-rT} E(（K -S exp{(r-sigma^2/2)T + sigma * sqrt(T) * W})^{+}]
で計算しています。（ヨーロピアンです）  
このプログラムでは、金利や現在価格などのインプットをもとに、モンテカルロ法で右辺を算出しています。  
C++での正規乱数の発生のさせ方はボックスミューラー法を使用しました。  

