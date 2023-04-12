compiler := gcc
name := main

$(name).exe: $(name).o
	$(compiler) $(name).o -o $(name).exe
$(name).o: $(name).c
	$(compiler) -c $(name).c -o $(name).o
run:
	.\$(name)
clean:
	-del -f $(name).exe *.o