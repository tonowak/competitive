#!/bin/zsh

letter() {
	local alphabet=({a..z})
	local x="$1"
	local ans=""
	while ((x > 0)); do
		local mod=$(((x - 1) % 26))
		ans="${alphabet[$((mod + 1))]}$ans"
		x=$(((x - mod) / 26))
	done
	echo $ans
}

no_group=1
no_test=1

new_group() {
	no_group=$((no_group + 1))
	no_test=1
}

generate() {
	local test_count=$1
	for ((i=0; i<$test_count; i++)); do
		./g ${@:2} > ../in/$label$no_group$(letter $no_test).in
		echo "made in  $label$no_group$(letter $no_test)"
		no_test=$((no_test + 1))
	done
}

prepare() {
	rm ../in/*.in -f
	rm ../out/*.out -f
	clang++ gen.cpp -o g -O2 -std=c++11 -DDEBUG
	clang++ ../prog/$label.cpp -o main -O2 -std=c++11
	echo "compiled"
}

finish() {
	echo "made in"
	for file in ../in/*.in; do
		echo "made out ${file%.in}"
		./main < $file > "${file%.in}.out"
	done
	mv ../in/*.out ../out/
	echo "made out"

	rm g
	rm main
}


label='???'
prepare

generate test_number arguments
new_group
generate 69 1 2 3

finish
