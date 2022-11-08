for t in 500000 1000000 5000000 10000000 50000000 
do
		for i in `seq 1 5`
		do
			python test.py -s $t 
		done
done
