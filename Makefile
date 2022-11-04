src/nobel_prize.o: src/nobel_prize.c src/nobel_prize.h
		gcc -c src/nobel_prize.c -o src/nobel_prize.o

src/quicksort_generic.o: src/quicksort_generic.h src/quicksort_generic.c
		gcc -c src/quicksort_generic.c -o src/quicksort_generic.o

src/nobel_test.o: src/nobel_test.c src/nobel_prize.c src/nobel_prize.h src/quicksort_generic.h src/quicksort_generic.c
		gcc -c src/nobel_test.c -o src/nobel_test.o


src/msort.o: src/msort.h src/msort.c
	gcc -c src/msort.c -o src/msort.o

src/msort_test.o: src/msort.c src/msort.h src/quicksort_generic.h src/quicksort_generic.c
	gcc -c src/msort_test.c -o src/msort_test.o

nobel_test: src/nobel_test.o src/nobel_prize.o src/quicksort_generic.o
	gcc -o build/nobel_test src/nobel_test.o src/nobel_prize.o src/quicksort_generic.o

msort_test: src/msort_test.o src/msort.o src/quicksort_generic.o
	gcc -o build/msort_test src/msort_test.o src/msort.o src/quicksort_generic.o

quicksort_int: src/quicksort_int.c
	gcc -o build/quicksort_int src/quicksort_int.c 


clean:
	rm -f src/*.o
