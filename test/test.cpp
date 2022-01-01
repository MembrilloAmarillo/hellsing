#include <iostream>
#include <vec2_math.h>

class Timer;

int my_strcmp( const char*, const char* );

int main( int argc, char *argv[] )
{
	bool set_randomness = false;
	float        arr[2];
	vec2           varr;

	if( argc == 5 ) 
	{
		arr[0] = atof( argv[1] );
		arr[1] = atof( argv[2] );
		varr.vec_float( arr );
		arr[0] = atof( argv[3] );
		arr[1] = atof( argv[4] );
	} else if( argc == 2 ) {
		if( my_strcmp( argv[1], "--set-random" ) == 0 ) {
			set_randomness = true;
		} else {
			std::cerr << "Value given not expected, did you mean --set-random ?" << std::endl;
			return 1;
		}
	} else {
		std::cerr << argc << " Arguments provided, expected 5" << std::endl;
		std::cout << "Usage:" << std::endl;
		std::cout << "  test.exe vec2_val1 vec2_val2 arr_val1 arr_val2" << std::endl;
		std::cout << "  test.exe --set-random" << std::endl;
		return 1;
	}
}