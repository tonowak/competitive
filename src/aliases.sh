#!/bin/zsh

function compile() {
	rm .failed -f
	if ! clang++ $1.cpp -o $1 ${@:2} -fcolor-diagnostics 1>.log 2>&1; then
		print -P "%F{red}%BError: %F{gray}Compilation failed"
		touch .failed
		rm $1 -f
	fi

	if [ -s .log ]; then
		less .log
		rm .log
	fi
}

function dc() {
	compile $1 -std=c++11 \
        -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wno-unused-result -Wfloat-equal \
        -g -ggdb -fsanitize=address,undefined -fno-omit-frame-pointer -fno-optimize-sibling-calls \
        -D_GLIBCXX_DEBUG -DDEBUG
}

function nc() {
	compile $1 -std=c++11 -O2
}

function dc_gdb() {
	compile $1 -std=c++11 -O2 -g3 -ggdb
}

function run_program() {
	if [ ! -f .failed ]; then
		./$1 < tg
	fi
}

function ntask() {
	local path=~/src/$1
	/bin/mkdir $path 2>/dev/null
	# cp ~/git/algorithms/templates/rich/* $path/
	/bin/cp ~/src/templates/* $path/
	cd $path
}

function task() {
	cd ~/src/$1
}

alias dm='dc m; run_program m'
alias db='dc b; run_program b'
alias dg='dc g'

alias nm='nc m; run_program m'
alias nb='nc b; run_program b'
alias ng='nc g'

alias v='nvim'
alias vm='v m.cpp'
alias vb='v b.cpp'
alias vg='v g.cpp'
alias vtm='v tm'
alias vtb='v tb'
alias vtg='v tg'
alias vta='v ta'

alias cm='cat m.cpp'
alias cb='cat b.cpp'
alias cg='cat g.cpp'
alias ctm='cat tm'
alias ctb='cat tb'
alias ctg='cat tg'
alias cta='cat ta'

alias s='./s.sh'
alias g='./g.sh'

