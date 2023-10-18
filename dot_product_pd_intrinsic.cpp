#include <immintrin.h>
#include <iostream>
#include <chrono>

// Crea variables para el tamano del array y del chunk
const int arraySize = 1024*4*4;
const int chunkSize = 4;

float DotProductArrays(float* arrayA, float* arrayB, int size) {
    // Se crea variable de tipo __m128 para usar un registro vectorial como acumulador de los productos puntos parciales.
    __m128 dotProductAccumulator = _mm_setzero_ps();

    // Realiza el calculo del producto punto en chunks de 4 datos por iteracion.
    for (int i = 0; i < size; i += chunkSize) {

        // Load a chunk of data from arrayA and arrayB into __m128 registers
        __m128 chunkA = _mm_loadu_ps(&arrayA[i]);
        __m128 chunkB = _mm_loadu_ps(&arrayB[i]);
     
        // Multiply the two chunks element-wise and accumulate the result
        __m128 dotProductContribution = _mm_dp_ps(chunkA, chunkB, 0xFF);

        //dotProductAccumulator += dotProductContribution;
        dotProductAccumulator = _mm_add_ps(dotProductAccumulator, dotProductContribution);        
    }

    // Extract the result from the accumulator
    float dotProductResult[4];
    _mm_storeu_ps(dotProductResult, dotProductAccumulator);
    

    // Guarda el producto punto final para retornarlo.
    float finalDotProduct = dotProductResult[0];


    return finalDotProduct;
}

int main() {
    // Crea los vectores/arrays
    float arrayA[arraySize];
    float arrayB[arraySize];

    // Inicializa los vectores
    for (size_t i = 0; i < arraySize; i++)
    {

        arrayA[i] = 15.0f; 
        arrayB[i] = 23.0f;

    }
    
    // Inicia la toma de tiempo
    auto start = std::chrono::high_resolution_clock::now();

    // Llama a la funcion del producto punto.
    float dotProduct = DotProductArrays(arrayA, arrayB, arraySize);

    // Termina la toma de tiempo
    auto end = std::chrono::high_resolution_clock::now();
    // Calcula el tiempo de ejecucion
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;

    // Se imprime el resultado de la operacion
    printf("Dot Product: %f\n", dotProduct);

    return 0;
}
