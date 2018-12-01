#!/bin/zsh

for ((i=0;i<=10000000;i++)); do
    ./gen < tests/config.gen > tests/gen.gen
    ./main < tests/gen.gen   > tests/main.gen
    ./brute < tests/gen.gen  > tests/brute.gen

    if diff -w tests/main.gen tests/brute.gen > /dev/null; then
		print -P "%B[%F{green}OK%F{white}]%b $i"
    else
		print -P "%B[%F{red}WA%F{white}]%b $i"
		print -P "%Binput:%b"
		cat tests/gen.gen
		print -P "%Bbrute:%b"
		cat tests/brute.gen
		print -P "%Bmain:%b"
		cat tests/main.gen
        exit 0
    fi
done     
