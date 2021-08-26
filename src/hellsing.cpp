#include <cstdio>

#include <vec2_math.h>
#include <vec3_math.h>

int main( void )
{
	/* Recordar que esta funcion guarda los elementos del reves:
	 * _mm_set_ps(e3, e2, e1, e0);
	 */
	__m128 ymm0 = _mm_set_ps(1.01f, 2.001f, 3.014f, 4.333f);

	vec2 a_1{ ymm0 };

	vec2 a_2{ 2.002f };

	a_1 *= a_2;

	a_1 *= 2.3f;

	auto vec{ a_1.vec_float() };

	vec2 a_3;
	a_3.vec_float(vec);

	auto new_vec{ a_3.vec_float() };

	for (int i = 0; i < 4; i++)
	{
		fprintf(stdout, "%.10f\n", new_vec[i]);
	}

	return 0;
}
