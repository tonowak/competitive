#!/bin/zsh

source ~/src/aliases.sh
print -P "%BCompiling main...%b"
if ! nc main; then
	exit 0
fi
print -P "%BDone!%b"

for i in $(ls tests/*.in -v); do # -Sr
	local file="${i%.in}"
	~/src/utils/oiejq/oiejq_modified.sh ./main < $file.in > tests/main.out 2>.sio2jail

	if diff -w $file.out tests/main.out > /dev/null; then
		print -P "%B[%F{green}OK%F{white}]%b ${file#"tests/"}  " | tr '\n' ' '
		cat .sio2jail
		print ""
	else
		print -P "%B[%F{red}WA%F{white}]%b ${file#"tests/"}  " | tr '\n' ' '
		cat .sio2jail
		print ""

		cp $file.in tests/gen.gen
		cp $file.out tests/brute.gen
		cp tests/main.out tests/main.gen
		rm tests/main.out

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

