#!/bin/zsh

local file=${${1}%.cpp}
if [ -z "$file" ]; then
	local file="main"
fi

source ~/src/aliases.sh
myprint "%BCompiling %b$file..."
nc $file
if [[ ! -a ./$file ]]; then
	exit 0
fi
myprint "%BDone!"

for i in $(ls tests/*.in -v); do # -Sr
	local input="${i%.in}"
	~/src/utils/oiejq/oiejq_modified.sh ./$file < $input.in > tests/$file.out 2>.sio2jail

	if diff -w $input.out tests/$file.out > /dev/null; then
		print -Pn "%B[%F{green}OK%F{white}]%b ${input#"tests/"}  "
		cat .sio2jail
		print -Pn "                                            \r"
	else
		print -Pn "%B[%F{red}WA%F{white}]%b ${input#"tests/"}  "
		cat .sio2jail
		print ""

		cp $input.in tests/gen.gen
		cp $input.out tests/brute.gen
		cp tests/$file.out tests/$file.gen
		rm tests/$file.out

		myprint "%B- input:"
		if (( $(wc -c < tests/gen.gen) > 150 )); then
			print "input too big"
		else
			cat tests/gen.gen
		fi

		myprint "%B- expected output:"
		if (( $(wc -c < tests/brute.gen) > 150 )); then
			print "expected output too big"
		else
			cat tests/brute.gen
		fi

		myprint "%B- got output:"
		if (( $(wc -c < tests/$file.gen) > 150 )); then
			print "output too big"
		else
			cat tests/$file.gen
		fi

		exit 0
	fi
done
print ""

