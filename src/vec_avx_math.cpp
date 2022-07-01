#include "../include/vec_avx_math.h"

vec_avx::vec_avx( float _a ) {
    for( int i = 0; i < 8; i++ ) __A[i] = _a;
    a = _mm256_broadcast_ss( &__A[0] );
}

vec_avx::vec_avx( float* A ) {
    for( int i = 0; i < 8; i++ ) __A[i] = A[i];
    a = _mm256_load_ps( __A );
}

vec_avx& vec_avx::operator =( const vec_avx& va ) {
    if( this != &va ) {
        for( int i = 0; i < 8; i++ ) __A[i] = va.__A[i];
        a = va.a;
    }
    
    return *this;
}

vec_avx& vec_avx::operator +=( const vec_avx& va ) {
    a = _mm256_add_ps( a, va.a );
    _mm256_store_ps( __A, a );
    
    return *this;
}

vec_avx& vec_avx::operator *=( const vec_avx& va ) {
    a = _mm256_mul_ps( a, va.a );
    _mm256_store_ps( __A, a );
    
    return *this;
}

vec_avx operator +( const vec_avx& va1, const vec_avx& va2 ) {
    vec_avx v = va1;
    return v += va2;
}

vec_avx operator *( const vec_avx& va1, const vec_avx& va2 ) {
    vec_avx v = va1;
    return v *= va2;
}

