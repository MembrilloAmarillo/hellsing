#include <vec2_math.h>

#include <algorithm> // Provisional
#include <iostream>  // Provisional
#include <cstring>

#include "timer.cpp"

class check_times
{
private:
	int    n_iterations;
	double    SIMD_Time;
	double    Arry_Time;

	vec2    SIMD_Vector;
	int Normal_Array[2];

public:
	check_times( int iter, vec2 SV, int NA[2] );

	static int start( int argc, char *argv[] );
	inline double vec2_time() { return SIMD_Time; }
	inline double arr2_time() { return Arry_Time; }

	~check_times() = default;
};
