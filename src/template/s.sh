for i in $(ls t/*.in -Sr); do
	cp $i tg
	cp ${i%.in}.out tb
	./m < tg > tm
	if diff -w tm tb > /dev/null; then
		echo OK ${i%.in}
	else
		echo WA ${i%.in}
		exit 0
	fi
done

