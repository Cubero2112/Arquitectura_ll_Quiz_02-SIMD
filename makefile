
intr: intr.o
	./bin/dot_product_intrinsics


intr.o:
	g++ -mavx2 dot_product_intrinsics.cpp -o bin/dot_product_intrinsics



pd_intr: pd_intr.o
	./bin/dot_product_pd_intrinsic


pd_intr.o:
	g++ -mavx2 dot_product_pd_intrinsic.cpp -o bin/dot_product_pd_intrinsic




native: native.o
	./bin/dot_product_naive

native.o:
	g++ dot_product_naive.cpp -o bin/dot_product_naive

