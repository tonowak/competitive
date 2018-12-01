#!/bin/zsh

for i in $(ls tests/*.in -v); do # -Sr
	local file="${i%.in}"
	./main < $file.in > main.out

	if diff -w $file.out main.out > /dev/null; then
		print -P "%B[%F{green}OK%F{white}]%b $file"
	else
		print -P "%B[%F{red}WA%F{white}]%b $file"
		print -P "%Binput:%b"
		cat $file.in
		print -P "%Bexpected output:%b"
		cat $file.out
		print -P "%Bgot output:%b"
		cat main.out
		rm main.out
		exit 0
	fi
done

