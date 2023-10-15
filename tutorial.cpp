#include <immintrin.h>
#include <iostream>

int main() {
    __m128 a = _mm_set_ps(4.0, 3.0, 2.0, 1.0);
    __m128 b = _mm_set_ps(8.0, 7.0, 6.0, 5.0); // 32 + 21 + 12 + 5 = 
    __m128 result;

    // Addition
    //result = _mm_add_ps(a, b);

    // Subtraction
    //result = _mm_sub_ps(a, b);

    // Multiplication
    //result = _mm_mul_ps(a, b);

    // Dot Product
    result = _mm_dp_ps(a, b, 0xFF);

    float resultArray[4];
    _mm_store_ps(resultArray, result);

    // Print the results
    for (int i = 0; i < 4; i++) {
        printf("Result[%d] = %f\n", i, resultArray[i]);
    }

    return 0;
}
