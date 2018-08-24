for((i=0;i<=10000000;i++)); do
    ./g < ta > tg
    ./m < tg > tm
    ./b < tg > tb

    if diff -w tm tb > /dev/null; then
        echo OK $i
    else
        echo WA $i
        exit 0
    fi
done     
