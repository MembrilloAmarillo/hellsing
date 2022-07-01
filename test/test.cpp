#include <iostream>
#include <random>

#include <vec3_math.h>
#include <vec_avx_math.h>
#include "timer.h"

int my_strcmp( const char*, const char* );
void test_vec3( vec3& vec );
void test_4arr( float arr[4] );

void test_vec_avx( vec_avx& vec );
void test_8arr( float arr[8] );

inline float generate_random_float( std::mt19937& gen, std::uniform_real_distribution<>& dis )
{
    return dis( gen );
}

int main( int argc, char *argv[] )
{
	bool set_randomness = false;
	float arr4[4];
    float arr8[8];
    
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
        
        arr8[0] = arr4[0] = generate_random_float( gen, dis );
        arr8[1] = arr4[1] = generate_random_float( gen, dis );
        arr8[2] = arr4[2] = generate_random_float( gen, dis );
        arr8[3] = arr4[3] = generate_random_float( gen, dis );
        
        
        arr8[4] = generate_random_float( gen, dis );
        arr8[5] = generate_random_float( gen, dis );
        arr8[6] = generate_random_float( gen, dis );
        arr8[7] = generate_random_float( gen, dis );
        
    }
    
    vec3    varr( (const float*)arr4 );
    vec_avx  vav( arr8 );
    
    test_vec3( varr );
    test_vec_avx( vav );
    
    test_4arr( arr4 );
    test_8arr( arr8 );
    
    return 0;
}


void test_vec3( vec3& vec )
{
    Timer T;
    
    int r = 0;
    
    T.start();
    
    do {
        vec *= vec;
        r++;
    } while( T.time() < 4 );
    
    T.stop();
    
    std::cout << "vec3 implementation: " << T.time() / r << std::endl;
}

void test_vec_avx( vec_avx& vec )
{
    Timer T;
    
    int r = 0;
    
    T.start();
    
    do {
        vec *= vec;
        r++;
    } while( T.time() < 4 );
    
    T.stop();
    
    std::cout << "vec_avx implementation: " << T.time() / r << std::endl;
}

void test_4arr( float arr[4] )
{
    Timer T;
    
    int r = 0;
    
    T.start();
    
    do {
        arr[0] *= arr[0];
        arr[1] *= arr[1];
        arr[2] *= arr[2];
        arr[3] *= arr[3];
        r++;
    } while( T.time() < 4 );
    
    std::cout << "Normal array[4] implementation: " << T.time() / r << std::endl;
}

void test_8arr( float arr[8] )
{
    Timer T;
    
    int r = 0;
    
    T.start();
    
    do {
        arr[0] *= arr[0];
        arr[1] *= arr[1];
        arr[2] *= arr[2];
        arr[3] *= arr[3];
        arr[4] *= arr[4];
        arr[5] *= arr[5];
        arr[6] *= arr[6];
        arr[7] *= arr[7];
        r++;
    } while( T.time() < 4 );
    
    std::cout << "Normal array[8] implementation: " << T.time() / r << std::endl;
}