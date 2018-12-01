cd ~
git clone https://github.com/tonowak/competitive/tree/master/src
cp competitive/src ~ -r
cp competitive/src/utils/vimrc ~/.vimrc
mv competitive ~/src/.github
echo "source ~/src/aliases.sh" >> ~/.zshrc
