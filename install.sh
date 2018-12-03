cd "$HOME/"
git clone https://github.com/tonowak/competitive/
cp competitive/src "$HOME/" -r

# vim
cp competitive/src/utils/vimrc "$HOME/.vimrc"
mkdir -p "$HOME/.vim/colors/"
cp competitive/src/utils/one.vim "$HOME/.vim/colors/"

mv competitive "$HOME/src/.github"
echo "source $HOME/src/aliases.sh" >> ~/.zshrc
echo "Jeżeli tego jeszcze nie zrobiłeś/zrobiłaś, wpisz w konsoli: sudo sysctl kernel.perf_event_paranoid=-1"
