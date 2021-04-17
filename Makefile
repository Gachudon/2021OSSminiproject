CC = gcc
shop : main.c product.o manager.o
	$(CC) -o $@ $^
shop_debug : main.c product.o manager.o
	$(CC) -DEBUG -o $@ $^
clean:
	rm *.o shop shop_debug
