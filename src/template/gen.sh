#!/bin/zsh

for ((i=0;i<=10000000;i++)); do
    ./gen < tests/config.gen > tests/gen.gen
    ./main < tests/gen.gen   > tests/main.gen
    ./brute < tests/gen.gen  > tests/brute.gen

    if diff -w tests/main.gen tests/brute.gen > /dev/null; then
		print -P "%B[%F{green}OK%F{white}]%b $i"
    else
		print -P "%B[%F{red}WA%F{white}]%b $i"

		print -P "%B- input:%b"
		if (( $(wc -c < tests/gen.gen) > 150 )); then
			print "input too big"
		else
			cat tests/gen.gen
		fi

		print -P "%B- expected output:%b"
		if (( $(wc -c < tests/brute.gen) > 150 )); then
			print "expected output too big"
		else
			cat tests/brute.gen
		fi

		print -P "%B- got output:%b"
		if (( $(wc -c < tests/main.gen) > 150 )); then
			print "output too big"
		else
			cat tests/main.gen
		fi

		print ""

        exit 0
    fi
done     
