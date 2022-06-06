CC=gcc
CCOPTS=--std=gnu99 -Wall
AR=ar 

OBJS= 24_harmonic_oscillator.o 24_integratoin_method.o 24_utils.o
HEADERS= 24_harmonic_oscillator.h 24_integratoin_method.h
LIBS= DemaLib.a
BINS= 24_test

all:	$(BINS) $(LIBS)

24_integratoin_method.o:	24_integratoin_method.c 24_integratoin_method.h
	$(CC) $(CCOPTS) -c -o $@ $<

24_harmonic_oscillator.o:	24_harmonic_oscillator.c 24_harmonic_oscillator.h 
	$(CC) $(CCOPTS) -c -o $@ $<
	
24_utils.o: 24_utils.c 
	$(CC) $(CCOPTS) -o -c $@ $<

DemaLib.a:	$(OBJS)
	$(AR) -rcs $@ $^

24_test:	24_test.c $(LIBS)
	$(CC) $(CCOPTS) -o $@ $^

clean: 
	rm -rf *.o *.~ $(LIBS) $(BINS)
