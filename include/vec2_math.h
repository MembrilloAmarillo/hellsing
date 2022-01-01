#pragma once

#include <xmmintrin.h>
#include <cassert>

class vec2
{
public:
	vec2();
	vec2( __m128 aux );
	vec2( float f );
	vec2( float* C );

	// Devuelve instruccion sse
	inline const __m128& sse() const { return a; } 
	void sse( const __m128& );
	
	// Devuelve el vector float
	inline const float* vec_float(void) const { return __A; }
	void vec_float( const float* );

	vec2& operator  = ( const vec2& );

	vec2& operator += ( const vec2& );
	vec2& operator += ( const float& );
	vec2& operator *= ( const vec2& );
	vec2& operator *= ( const float& );

	friend vec2 operator + ( const vec2&, const vec2& );
	friend vec2 operator + ( const vec2&, const float& );
	friend vec2 operator + ( const float&, const vec2& );
	friend vec2 operator * ( const vec2&, const vec2& );
	friend vec2 operator * ( const vec2&, const float& );
	friend vec2 operator * ( const float&, const vec2& );
	
	~vec2();

private:
	float* __A = nullptr;
	__m128 a;

	// Convierte el vector sse en vector float
	void convert_to_float();
};
