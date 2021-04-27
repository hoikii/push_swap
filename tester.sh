#!/usr/bin/zsh

bar="[....................................................................................................]"
function put_line() {
	echo -en "\r$bar\r["
	for i in {1..$i}; do
		echo -en "\033[0;32m#\033[0;0m"
	done
}

function test_avg() {
	echo -e 'Testing 100 times in a range from' $1 'to' $2
	put_line
	ERR=0
	let sum=0
	for i in {1..100}; do
		ARG=`ruby -e "puts ($1..$2).to_a.shuffle.join(' ')"`
		RET=`./push_swap $ARG | ./checker $ARG`
		if [ "$RET" != "OK" ]; then
			((ERR++))
			break
		else
			put_line $i
			RET=`./push_swap $ARG | wc -l`
			sum=`expr $sum + $RET` 
		fi
	done

	if [ $ERR -eq 0 ]; then
		echo -e '] \033[0;32m Success\033[0;0m'
		echo -e "Average: `expr $sum / 100`"
	else
		echo -e "\033[0;31m Fail $ERR"
	fi
	echo
}


if [ "$1" = "" ]; then
	test_avg 0 49
#	test_avg 0 99
#	test_avg 0 499
else
	ARG=`ruby -e "puts (1..$1).to_a.shuffle.join(' ')"`
	./push_swap $ARG
	./push_swap $ARG | ./checker $ARG
fi
