#include <immintrin.h>
#include <iostream>
#include <chrono>

const int arraySize = 1024;
const int chunkSize = 4;  // We use 4-element chunks for SSE operations

// Function to calculate the dot product using SSE intrinsics
float DotProductSSE(float* arrayA, float* arrayB, int size) {
    __m128 dotProductAccumulator = _mm_setzero_ps();

    for (int i = 0; i < size; i += chunkSize) {
        // Load 4 float elements from arrayA and arrayB
        __m128 a = _mm_loadu_ps(&arrayA[i]);
        __m128 b = _mm_loadu_ps(&arrayB[i]);

        // Perform dot product on the 4 elements and accumulate the result
        dotProductAccumulator = _mm_add_ps(dotProductAccumulator, _mm_mul_ps(a, b));
    }

    // Extract the dot product result
    float dotProductResult[4];
    _mm_storeu_ps(dotProductResult, dotProductAccumulator);


    // Sum the partial dot products to get the final result
    float finalDotProduct = dotProductResult[0] + dotProductResult[1] + dotProductResult[2] + dotProductResult[3];

    return finalDotProduct;
}

int main() {

    // Initialize your data arrays
    float arrayA[arraySize]; 
    float arrayB[arraySize]; 

    for (size_t i = 0; i < arraySize; i++)
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
    
    float dotProduct = DotProductSSE(arrayA, arrayB, arraySize);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    printf("Dot Product: %f\n", dotProduct);

    return 0;
}


/*

#include <iostream>
#include <immintrin.h>


const int arraySize = 4096;
float dotProduct(float array1[], float array2[], int size) {
    __m128 v1, v2;
    float result = 0.0;

    for (int i = 0; i < size; i += 4) {
        v1 = _mm_loadu_ps(&array1[i]);
        v2 = _mm_loadu_ps(&array2[i]);
        __m128 dp = _mm_dp_ps(v1, v2, 0xFF);
        result += _mm_cvtss_f32(dp);
    }

    return result;
}

// g++ -mavx2 dot_product_intrinsics.cpp -o bin/dot_product_intrinsics
// ./bin/dot_product_intrinsics
int main() {

    //const int size = 4096;
    // Initialize your data arrays
    float arrayA[arraySize]; // 1 1 1 1
    float arrayB[arraySize]; // 2 2 2 2   = 32(2)

    for (size_t i = 0; i < arraySize; i++)
    {
        if ((i%2)==0)
        {
            arrayA[i] = 17.0f;
            arrayB[i] = 9.0f;
        }else{
            arrayA[i] = 5.0f;
            arrayB[i] = 2.0f;
        }
    }



    float result = dotProduct(arrayA, arrayB, arraySize);

    std::cout << "Dot Product: " << result << std::endl;

    return 0;
}


*/