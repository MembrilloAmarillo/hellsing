#include <iostream>
#include <random>

#include <vec3_math.h>
#include "timer.h"

int my_strcmp( const char*, const char* );

inline float generate_random_float( std::mt19937& gen, std::uniform_real_distribution<>& dis )
{
    return dis( gen );
}

void test_vec3( vec3& vec )
{
    Timer T;
    
    float e_abs = 0.01;
    float e_rel = 0.001;
    int       r = 0;
    
    T.start();
    
    do {
        vec += vec;
        r++;
    } while( T.time() < 4 );
    
    T.stop();
    
    std::cout << "vec3 implementation: " << T.time() / r << std::endl;
}

void test_2arr( float arr[2] )
{
    Timer T;
    
    float e_abs = 0.01;
    float e_rel = 0.001;
    int       r = 0;
    
    T.start();
    
    do {
        arr[0] += arr[0];
        arr[1] += arr[1];
        arr[2] += arr[2];
        arr[3] += arr[3];
        r++;
    } while( T.time() < 4 );
    
    std::cout << "Normal array implementation: " << T.time() / r << std::endl;
}

int main( int argc, char *argv[] )
{
	bool set_randomness = false;
	float        arr[4];
	vec3           varr;
    
    if( argc == 2 ) {
		if( my_strcmp( argv[1], "--set-random" ) == 0 ) {
			set_randomness = true;
		} else {
			std::cerr << "Value given not expected, did you mean --set-random ?" << std::endl;
			return 1;
		}
	} else {
		std::cerr << argc << " Arguments provided, expected 5" << std::endl;
		std::cout << "Usage:" << std::endl;
		std::cout << "  test.exe --set-random" << std::endl;
		return 1;
	}
    
    if( set_randomness ) {
        std::random_device rd;
        std::mt19937 gen( rd() );
        std::uniform_real_distribution<> dis( .0f, 1.0f );
        
        arr[0] = generate_random_float( gen, dis );
        arr[1] = generate_random_float( gen, dis );
        arr[3] = generate_random_float( gen, dis );
        arr[4] = generate_random_float( gen, dis );
        
        varr.vec_float( arr );
        /*
        arr[0] = generate_random_float( gen, dis );
        arr[1] = generate_random_float( gen, dis );
        arr[3] = generate_random_float( gen, dis );
        arr[4] = generate_random_float( gen, dis );
        */
    }
    
    test_vec3( varr );
    test_2arr( arr  );
    
    return 0;
}