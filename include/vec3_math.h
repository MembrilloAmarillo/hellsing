#pragma once

#include <xmmintrin.h>

class vec3 {
public:
    vec3();
    vec3( float* f );
    vec3( __m128 a );

    /* Funciones observadoras */
    const float* vector() const;
    const __m128 sse() const;

    /* Funciones de guardado */
    void load_vector( const float* v1 );
    void load_sse( const __m128 ymm1 );

    ~vec3();
private:
    float* _V;
    __m128 _ymm0;
};