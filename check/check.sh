#!/bin/bash

NAME='../push_swap'
CHECKER='./checker_Mac'
MYCHECK='../checker'

CNT=10
TESTS=(5 10 100 500)
OK="OK"

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0;0m'

for t in ${TESTS[@]}; do
	i=0
	echo $t testing...
	for (( c = 0; c < $CNT; c++ )); do
		echo -en \\r$c/$CNT
		ARGS=`ruby -e "puts (1..$t).to_a.shuffle.join(' ')"`
		$NAME $ARGS > out.txt
		CHECK=`cat out.txt | $CHECKER $ARGS`
		CHECK2=`cat out.txt | $MYCHECK $ARGS`
		if [ "$CHECK" = "$OK" ] && [ "$CHECK" = "$CHECK2" ]; then
		#if [ "$CHECK" = "$OK" ]; then
			((i++))
		else
			echo -e \\n$REDKO!$NC\\n$ARGS\\n
		fi
		cat out.txt | grep -e '^[prs]' | wc -l >> test$t.txt
	done
	[[ "$i" -eq "$CNT" ]] && COLOR=$GREEN || COLOR=$RED
	echo -e \\r$COLOR$i/$CNT$NC
	echo $t:
	./count < test$t.txt
	rm test$t.txt out.txt
done
