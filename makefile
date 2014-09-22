cc = g++
OBJ: craps.o

craps: $(OBJ)
	$(cc) $(OBJ) -o $@

.cpp.o:
	$(cc) -c $<

clean:
	rm *.o craps
