cd ~
git clone https://github.com/tonowak/competitive/
cp competitive/src ~ -r
# vim
cp competitive/src/utils/vimrc ~/.vimrc
mkdir -p "~/.vim/colors/"
cp competitive/src/utils/one.vim ~/.vim/colors/
mv competitive ~/src/.github
echo "source ~/src/aliases.sh" >> ~/.zshrc
echo "Jeżeli tego jeszcze nie zrobiłeś/zrobiłaś, wpisz w konsoli: sudo sysctl kernel.perf_event_paranoid=-1"
