for((i=0;i<=100000;i++))
do
    ./g < t/a > t/g
    ./m < t/g > t/m
    ./b < t/g > t/b

    if diff -w t/m t/b > /dev/null
    then
        echo OK $i
    else
        echo WA $i
        exit 0
    fi
done     
