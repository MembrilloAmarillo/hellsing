#pragma once

#include <xmmintrin.h>
#include <cassert>

class vec3
{
    public:
	vec3();
	vec3( __m128 aux );
	vec3( float f );
	vec3( float* C );
    
	// Devuelve instruccion sse
	inline const __m128& sse() const { return a; } 
	void sse( const __m128& );
	
	// Devuelve el vector float
	inline const float* vec_float(void) const { return __A; }
	void vec_float( const float* );
    
	vec3& operator  = ( const vec3& );
    
	vec3& operator += ( const vec3& );
	vec3& operator += ( const float& );
	vec3& operator *= ( const vec3& );
	vec3& operator *= ( const float& );
    
	friend vec3 operator + ( const vec3&, const vec3& );
	friend vec3 operator + ( const vec3&, const float& );
	friend vec3 operator + ( const float&, const vec3& );
	friend vec3 operator * ( const vec3&, const vec3& );
	friend vec3 operator * ( const vec3&, const float& );
	friend vec3 operator * ( const float&, const vec3& );
	
	~vec3();
    
    private:
	float* __A = nullptr;
	__m128 a;
    
	// Convierte el vector sse en vector float
	void convert_to_float();
};
