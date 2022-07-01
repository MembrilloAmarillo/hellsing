#include "vec3_math.h"

vec3::vec3()
{
	a = _mm_set_ps1(0.0f);
	_mm_store_ps(__A, a);
}

vec3::vec3( __m128 aux ) :
a(aux)
{ 
	convert_to_float();
}

vec3::vec3( float f ) {
	a = _mm_set_ps1(f);
	_mm_store_ps(__A, a);
}

vec3::vec3( const float* C ) {
	
    assert( C != nullptr );
    
    for( int i = 0; i < 4; i++ ) __A[i] = C[i];
	a = _mm_load_ps(__A);
}

vec3& vec3::operator = (const vec3& v2)
{
	if (this != &v2) // Evitamos autoasignacion
	{
		// Copiamos parametros
		for( int i = 0; i < 4; i++ ) __A[i] = v2.__A[i];
		this->a   = v2.a;
	}
	return *this;
}

inline void vec3::convert_to_float()
{
	_mm_store_ps(__A, a);
}

inline void vec3::sse( const __m128& ymm0 )
{
	this->a = ymm0;
	convert_to_float();
}

void vec3::vec_float( const float* f )
{
	a = _mm_load_ps(f);
	convert_to_float();
}

// Nota, si queremos usar el vector float __A, debemos hacer uso
// de la funcion convert_to_float(), en caso contrario, dara error.
vec3& vec3::operator += (const vec3& v2)
{
	__m128 r = _mm_add_ps(a, v2.sse());
	this->a = r;
	convert_to_float();
	return *this;
}

vec3& vec3::operator += ( const float& f )
{
	__m128 b = _mm_set_ps1(f);
	__m128 r = _mm_add_ps(this->a, b);
	this->a = r;
	convert_to_float();
	return *this;
}

vec3 operator + (const vec3& v1, const float& f2)
{
	vec3 aux{v1};
    
	return aux += f2;
}

vec3 operator + (const float& f2, const vec3& v1)
{
	vec3 aux{v1};
    
	return aux += f2;
}

vec3 operator + ( const vec3& v1, const vec3& v2 )
{
	vec3 aux{v1.__A};
	
	return aux += v2;
}

vec3& vec3::operator *= ( const vec3& v2 )
{
	__m128 r = _mm_mul_ps(a, v2.sse());
	this->a  = r;
	convert_to_float();
	return *this;
}

vec3& vec3::operator *= ( const float& f )
{
	__m128 b = _mm_set_ps1(f);
	__m128 r = _mm_mul_ps(this->a, b);
	this->a  = r;
	convert_to_float();
	return *this;
}

vec3 operator * (const vec3& v1, const float& f2)
{
	vec3 aux{v1};
    
	return aux *= f2;
}

vec3 operator * (const float& f2, const vec3& v1)
{
	vec3 aux{v1};
    
	return aux *= f2;
}

vec3 operator * ( const vec3& v1, const vec3& v2 )
{
	vec3 aux{v1.__A};
    
	return aux *= v2;
}

vec3::~vec3()
{
}
