#!/bin/zsh

setxkbmap -option caps:swapescape # swapping caps with esc

function compile() {
	rm .failed -f
	file=${${1}%.cpp}
	if ! clang++ $file.cpp -o $file ${@:2} -fcolor-diagnostics 1>.log 2>&1; then
		print -P "%F{red}%BError: %F{gray}Compilation failed"
		touch .failed
		rm $file -f
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
	local task_path="$HOME/src/$1"
	if [ ! -d $task_path ]; then
		print -P "%BCreating path%b $task_path"
		/bin/mkdir -p $task_path
		/bin/cp -r ~/src/template/* $task_path/
	fi
	cd $task_path
}

function add_test() {
	if [ ! -d "tests" ]; then
		print -P "%BFolder tests/ doesn't exists%b"
		exit 0
	fi

	for ((i=1;i<=10000;i++)); do
		if [ ! -f tests/$i.in ]; then
			print -P "%BWrite input%b [tests/$i.in] (stop writing with an empty line)"
			while read line; do
				if [ -z $line ]; then
					break
				fi
				echo $line >> tests/$i.in
			done

			print -P "%BWrite expected output%b [tests/$i.out]"
			while read line; do
				if [ -z $line ]; then
					break
				fi
				echo $line >> tests/$i.out
			done

			break
		fi
	done
}

alias dm='dc main; run_program main'
alias db='dc brute; run_program brute'
alias dg='dc gen'

alias nm='nc main; run_program main'
alias nb='nc brute; run_program brute'
alias ng='nc gen'

alias v='vim' # or nvim or subl (sublime text)
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

