#!/bin/zsh

function myprint() {
	print -P "$@%{$reset_color%}"
}

for ((i=0;i<=10000000;i++)); do
    ./gen < tests/config.gen > tests/gen.gen
    ./main < tests/gen.gen   > tests/main.gen
    ./brute < tests/gen.gen  > tests/brute.gen

    if diff -w tests/main.gen tests/brute.gen > /dev/null; then
		print -Pn "%B[%F{green}OK%F{white}]%b $i\r"
    else
		myprint "%B[%F{red}WA%F{white}]%b $i"

		myprint "%B- input:%b"
		if (( $(wc -c < tests/gen.gen) > 150 )); then
			myprint "input too big"
		else
			cat tests/gen.gen
		fi

		myprint "%B- expected output:%b"
		if (( $(wc -c < tests/brute.gen) > 150 )); then
			myprint "expected output too big"
		else
			cat tests/brute.gen
		fi

		myprint "%B- got output:%b"
		if (( $(wc -c < tests/main.gen) > 150 )); then
			myprint "output too big"
		else
			cat tests/main.gen
		fi

        exit 0
    fi
done     
