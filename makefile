intr: intr.o
	./bin/dot_product_intrinsics


intr.o:
	g++ -mavx2 dot_product_intrinsics.cpp -o bin/dot_product_intrinsics


native: native.o
	./bin/dot_product_naive

native.o:
	g++ dot_product_naive.cpp -o bin/dot_product_naive

