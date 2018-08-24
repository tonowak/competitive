function compile() {
	clang++ $1.cpp -o $1 ${@:2} -fcolor-diagnostics 1>.log 2>&1
	if [ -s .log ]; then
		less -rR .log
	fi
	rm .log
}

function d() {
	compile $1 -std=c++11 \
        -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wno-unused-result -Wfloat-equal  \
        -g -fsanitize=address,undefined -fno-omit-frame-pointer -fno-optimize-sibling-calls \
        -D_GLIBCXX_DEBUG -DDEBUG
}

function n() {
	compile $1 -std=c++11 -static -O2
}

alias dm='d m && ./m < tg'
alias db='d b && ./b < tg'
alias dg='d g'

alias nm='n m && ./m < tg'
alias nb='n b && ./b < tg'
alias ng='n g'

alias vm='vi m.cpp'
alias vb='vi b.cpp'
alias vg='vi g.cpp'

alias vtm='vi tm'
alias vtb='vi tb'
alias vtg='vi tg'
alias vta='vi ta'

alias v='vim'
alias s='./s.sh'
alias g='./g.sh'
