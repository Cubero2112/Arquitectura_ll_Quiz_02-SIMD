#include <iostream>
#include <chrono>
#include <iomanip>


float dotProduct(const float array1[], const float array2[], int size) {
    // Se realiza el calculo del producto punto por medio de un bucle
    float result = 0.0;
    for (int i = 0; i < size; i++) {
        result += array1[i] * array2[i];
    }
    // se retorna el resultado del producto punto.
    return result;
}


// g++ dot_product_naive.cpp -o bin/dot_product_naive
// ./bin/dot_product_naive
int main() {
    // Crea variables para el tamano del array
    const int size = 1024*4*4;

    // Crea los arrays
    float arrayA[size]; 
    float arrayB[size]; 
    

   // Inicializa los arrays
    for ( int i = 0; i < size; i++)
    {

        arrayA[i] = 15.0f;
        arrayB[i] = 23.0f;
    }
    

    // Inicia la toma de tiempo
    auto start = std::chrono::high_resolution_clock::now();

    // Llama a la funcion del producto punto.
    float result = dotProduct(arrayA, arrayB, size);

    // Termina la toma de tiempo
    auto end = std::chrono::high_resolution_clock::now();
    // Calcula el tiempo de ejecucion
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken: " << duration.count() << " seconds" << std::endl;
    
    // Se imprime el resultado de la operacion
    printf("Dot Product: %f\n", result);

    return 0;
}
