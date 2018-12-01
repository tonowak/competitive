#!/bin/zsh

function compile() {
	rm .failed -f
	file=${${1}%.cpp}
	if ! clang++ $file.cpp -o $file ${@:2} -fcolor-diagnostics 1>.log 2>&1; then
		print -P "%F{red}%BError: %F{gray}Compilation failed"
		touch .failed
		rm $file -f
	fi

	if [ -s .log ]; then
		less -R .log
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
	compile $1 -std=c++11 -O3 -static # -m32
}

function dc_gdb() {
	compile $1 -std=c++11 -O3 -g3 -ggdb -fno-omit-frame-pointer
}

function run_program() {
	if [ ! -f .failed ]; then
		./$1 < tests/gen.gen
	fi
}

function task() {
	local path="$HOME/src/$1"
	if [ ! -d $path ]; then
		echo "Creating path $path"
		/bin/mkdir -p $path
		/bin/cp -r ~/src/template/* $path/
	fi
	cd $path
}

alias dm='dc main; run_program main'
alias db='dc brute; run_program brute'
alias dg='dc gen'

alias nm='nc main; run_program main'
alias nb='nc brute; run_program brute'
alias ng='nc gen'

alias v='nvim' # or nvim or subl (sublime text)
alias vi='v'
alias vg='v gen.cpp'
alias vm='v main.cpp'
alias vb='v brute.cpp'
alias vtc='v tests/config.gen'
alias vtb='v tests/brute.gen'
alias vtm='v tests/main.gen'
alias vtg='v tests/gen.gen'

alias cg='cat gen.cpp'
alias cm='cat main.cpp'
alias cb='cat brute.cpp'
alias ctc='cat tests/config.gen'
alias ctb='cat tests/brute.gen'
alias ctm='cat tests/main.gen'
alias ctg='cat tests/gen.gen'

alias s='./spr.sh'
alias g='./gen.sh'

