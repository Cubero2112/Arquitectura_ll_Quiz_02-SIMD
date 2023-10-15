#include <iostream>
#include <chrono>

const int size = 1024;
float dotProduct(const float array1[], const float array2[], int size) {
    float result = 0.0;
    for (int i = 0; i < size; i++) {
        result += array1[i] * array2[i];
    }
    return result;
}


// g++ dot_product_naive.cpp -o bin/dot_product_naive
// ./bin/dot_product_naive
int main() {
   
    
    // Initialize your data arrays
    float arrayA[size]; // 1 1 1 1
    float arrayB[size]; // 2 2 2 2   = 32(2)
    for (size_t i = 0; i < size; i++)
    {
        if ((i%2)==0)
        {
            arrayA[i] = 17.0f;
            arrayB[i] = 61.0f;
        }else{
            arrayA[i] = 106.0f;
            arrayB[i] = 88.0f;
        }
    }
    
    auto start = std::chrono::high_resolution_clock::now();

    float result = dotProduct(arrayA, arrayB, size);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    printf("Dot Product: %f\n", result);

    return 0;
}
