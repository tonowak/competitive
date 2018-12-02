cd ~
git clone https://github.com/tonowak/competitive/
cp competitive/src ~ -r
cp competitive/src/utils/vimrc ~/.vimrc
mv competitive ~/src/.github
echo "source ~/src/aliases.sh" >> ~/.zshrc
echo "Jeżeli tego jeszcze nie zrobiłeś/zrobiłaś, wpisz w konsoli: sudo sysctl kernel.perf_event_paranoid=-1"
