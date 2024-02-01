CC = gcc
CCFLAGS = -Wall -g

all: mains maindloop maindrec loops

program: main.o basicClassification.o advancedClassificationRecursion.o
	$(CC) $(CCFLAGS) main.o basicClassification.o advancedClassificationRecursion.o -o program

mains: main.o libclassrec.a
	$(CC) main.o -L. -lclassrec -o mains

maindloop: main.c libclassloops.so
	$(CC) -Wall main.c -L. -lclassloops -o maindloop

maindrec: main.c libclassrec.so
	$(CC) -Wall main.c -L. -lclassrec -o maindrec

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar rcu libclassloops.a basicClassification.o advancedClassificationLoop.o
	ranlib libclassloops.a

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar rcu libclassrec.a basicClassification.o advancedClassificationRecursion.o
	ranlib libclassrec.a

libclassrec.so:
	$(CC) -Wall -fPIC -c basicClassification.c
	$(CC) -Wall -fPIC -c advancedClassificationRecursion.c
	$(CC) -shared basicClassification.o advancedClassificationRecursion.o -o libclassrec.so

libclassloops.so:
	$(CC) -Wall -fPIC -c basicClassification.c
	$(CC) -Wall -fPIC -c advancedClassificationLoop.c
	$(CC) -shared basicClassification.o advancedClassificationLoop.o -o libclassloops.so

main.o: main.c NumClass.h
	$(CC) $(CCFLAGS) -c main.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CCFLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CCFLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CCFLAGS) -c advancedClassificationRecursion.c

clean:
	rm -f *.o
	rm -f *.so
	rm -f *.a

veryClean:
	rm -f *.o
	rm -f *.so
	rm -f *.a
	rm -f mains maindloop maindrec