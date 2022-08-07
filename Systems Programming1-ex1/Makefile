CC = gcc
AR = ar
OBJECT_LOOP = advancedClassificationLoop.c basicClassification.c
OBJECT_REC = advancedClassificationRecursion.c basicClassification.c
OBJECTS_MAIN = main.c
FLAGS = -Wall -g

loops: $(OBJECT_LOOP)
	$(AR) -rcs libclassloops.a $(OBJECT_LOOP)

recursives: $(OBJECT_REC)
	$(AR) -rcs libclassrec.a $(OBJECT_REC)

recursived: $(OBJECT_REC) 
	$(CC) -shared -o libclassrec.so $(OBJECT_REC) -lm

loopd: $(OBJECT_LOOP)
	$(CC) -shared -o libclassloops.so $(OBJECT_LOOP) -lm

mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) -lm

maindloop: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so -lm

maindrec: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so -lm

all: loops recursives recursived loopd mains maindloop maindrec

clean:
	rm -f *.o *.a *.so loops recursives
