# file paths
o_path = obj
lib_path = lib
src_path = src

# compiler options
flags = -c -std=c99
paths = -I/home/calcifer/Documents/code/BurningBacon/$(src_path)

all: $(lib_path) $(o_path) vector.o math.o
	ar -cvr $(lib_path)/libBurningBacon.a $(o_path)/*.o

clean:
	rm -rf $(o_path)
	rm -rf $(lib_path)

rebuild: clean
	make all

debug: flags += -g
debug: o_path = dbg
debug: all

math.o: $(src_path)/bbmath.h $(src_path)/bbmath.c
	gcc $(src_path)/bbmath.c -o $(o_path)/math.o $(flags) $(paths)

vector.o: $(src_path)/bbvector.c $(src_path)/bbvector.h
	gcc $(src_path)/bbvector.c -o $(o_path)/vector.o $(flags) $(paths)

$(lib_path):
	mkdir $(lib_path)

$(o_path):
	mkdir $(o_path)