#include <immintrin.h>
#include <iostream>
#include <chrono>


const int arraySize = 1024*4*4;
const int chunkSize = 4;

float DotProductArrays(float* arrayA, float* arrayB, int size) {
    __m128 dotProductAccumulator = _mm_setzero_ps();

    for (int i = 0; i < size; i += chunkSize) {

        // Load a chunk of data from arrayA and arrayB into __m128 registers
        __m128 chunkA = _mm_loadu_ps(&arrayA[i]);
        __m128 chunkB = _mm_loadu_ps(&arrayB[i]);
     

        // Multiply the two chunks element-wise and accumulate the result
        //__m128 dotProductContribution = _mm_dp_ps(chunkA, chunkB, 0xFF);
        //std::cout << "Dot Product actual: " << dotProductContribution << std::endl;
        //dotProductAccumulator += dotProductContribution;
        dotProductAccumulator = _mm_add_ps(dotProductAccumulator, _mm_dp_ps(chunkA, chunkB, 0xFF));        
    }

    // Extract the result from the accumulator
    float dotProductResult[4];
    _mm_storeu_ps(dotProductResult, dotProductAccumulator);
    

    // Sum the partial dot products to get the final result
    float finalDotProduct = dotProductResult[0];// + dotProductResult[1] + dotProductResult[2] + dotProductResult[3];


    return finalDotProduct;
}

int main() {
    float arrayA[arraySize];
    float arrayB[arraySize];

    // Initialize both arrays with your data here...

    /*
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
    */

   
    for (size_t i = 0; i < arraySize; i++)
    {

        arrayA[i] = 15.0f; // 15 15 15 15
        arrayB[i] = 23.0f; // 23 23 23 23 

    }
    
    auto start = std::chrono::high_resolution_clock::now();

    float dotProduct = DotProductArrays(arrayA, arrayB, arraySize);


    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    //std::cout << "Dot Product: " << dotProduct << std::endl;
    printf("Dot Product: %f\n", dotProduct);

    return 0;
}
