all: tst

tst: main.o PicPay.o Nodo.o DoubleChaining.o Transaction.o
	g++ main.o PicPay.o Nodo.o DoubleChaining.o Transaction.o -o tst

main.o: main.cpp PicPay.h Nodo.h DoubleChaining.h Transaction.h
	g++ -c main.cpp -o main.o

PicPay.o: PicPay.cpp PicPay.h
	g++ -c PicPay.cpp -o PicPay.o

Nodo.o: Nodo.cpp Nodo.h
	g++ -c Nodo.cpp -o Nodo.o

DoubleChaining.o: DoubleChaining.cpp DoubleChaining.h
	g++ -c DoubleChaining.cpp -o DoubleChaining.o

Transaction.o: Transaction.cpp Transaction.h
	g++ -c Transaction.cpp -o Transaction.o

clean:
	rm -f *.o tst
