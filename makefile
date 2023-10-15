intr: intr.o
	./bin/1024_dot_product_intrinsics


intr.o:
	g++ -mavx2 1024_dot_product_intrinsics.cpp -o bin/1024_dot_product_intrinsics


native: native.o
	./bin/dot_product_naive

native.o:
	g++ dot_product_naive.cpp -o bin/dot_product_naive

