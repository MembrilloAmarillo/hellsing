/* date = June 30th 2022 6:16 pm */

#ifndef VEC_AVX_MATH_H
#define VEC_AVX_MATH_H

#include <immintrin.h>
#include <cassert>

class vec_avx {
    public:
    vec_avx( float );
    vec_avx( float * );
    
    inline const __m256& avx() const { return a; }
    //void avx( const __m256& );
    
    inline const float* vec_float( void ) const { return __A; }
    //void vec_float( const float* );
    
    vec_avx& operator =( const vec_avx& );
    
    vec_avx& operator +=( const vec_avx& );
    //vec_avx& operator +=( const float& );
    vec_avx& operator *=( const vec_avx& );
    //vec_avx& operator *=( const float& );
    
    friend vec_avx operator +( const vec_avx&, const vec_avx& );
    //friend vec_avx operator +( const vec_avx&, const float& );
    
    friend vec_avx operator *( const vec_avx&, const vec_avx& );
    //friend vec_avx operator *( const vec_avx&, const float& );
    
    private:
    float __A[8] __attribute__( ( aligned (32) ) );
    __m256 a;
};

#endif //VEC_AVX_MATH_H
