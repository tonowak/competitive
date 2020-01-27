#!/bin/zsh

# setxkbmap -option caps:swapescape # swapping caps with esc

function myprint() {
	print -P "$@%{$reset_color%}"
}

function compile() {
	file=${${1}%.cpp}
	if [[ $file =~ "\." ]]; then
		myprint "%F{red}%BError: %F{gray}Wrong extension"
		return
	fi

	if ! g++ $file.cpp -o $file ${@:2} -fdiagnostics-color=always 1>.log 2>&1; then
		myprint "%F{red}%BError: %F{gray}Compilation failed"
		rm $file -f
	fi

	if [ -s .log ]; then
		less .log
		rm .log
	fi
}

function c() {
	compile $1 -std=c++11 \
        -Wall -Wextra -Wshadow -Wconversion -Wno-sign-conversion -Wno-unused-result -Wfloat-equal \
        -g -ggdb -fsanitize=address,undefined -fno-omit-frame-pointer -fno-optimize-sibling-calls \
        -D_GLIBCXX_DEBUG -DDEBUG
}

function nc() {
	compile $1 -std=c++11 -O3 -static # -m32
}

function c_gdb() {
	compile $1 -std=c++11 -O3 -g3 -ggdb -fno-omit-frame-pointer
}

function run_program() {
	if [ -f $1 ]; then
		./$1 < tests/gen.gen
	fi
}

function task() {
	local task_path="$HOME/src/$1"
	if [ ! -d $task_path ]; then
		myprint "%BCreating path%b $task_path"
		/bin/mkdir -p $task_path
		/bin/cp -r ~/src/template/* $task_path/
	fi
	cd $task_path
}

function add_test() {
	if [ ! -d "tests" ]; then
		myprint "%BFolder tests/ doesn't exists%b"
		exit 0
	fi

	for ((i=1;i<=10000;i++)); do
		if [ ! -f tests/$i.out ]; then
			rm -f tests/$i.in 2>/dev/null
			myprint "%BWrite input%b [tests/$i.in] (stop writing with an empty line)"
			while read line; do
				if [ -z $line ]; then
					break
				fi
				echo $line >> tests/$i.in
			done

			myprint "%BWrite expected output%b [tests/$i.out]"
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

function cpc() {
	xclip -sel c < $1
}

alias dm='c main; run_program main'
alias db='c brute; run_program brute'
alias dg='c gen'
alias nm='nc main; run_program main'
alias nb='nc brute; run_program brute'
alias ng='nc gen'

alias vg='vim gen.cpp'
alias vm='vim main.cpp'
alias vb='vim brute.cpp'
alias vtc='vim tests/config.gen'
alias vtb='vim tests/brute.gen'
alias vtm='vim tests/main.gen'
alias vtg='vim tests/gen.gen'

alias cg='cat gen.cpp'
alias cm='cat main.cpp'
alias cb='cat brute.cpp'
alias ctc='cat tests/config.gen'
alias ctb='cat tests/brute.gen'
alias ctm='cat tests/main.gen'
alias ctg='cat tests/gen.gen'

