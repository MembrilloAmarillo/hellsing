#include <ctime>
#include "timer.h"

double Timer::CPS( CLOCKS_PER_SEC );

void Timer::start()
{
	active = true;
	str    = std::clock();
} 

void Timer::stop()
{
	end    = std::clock();
	active = false;
}

double Timer::time() const 
{
	return ( ( active ? std::clock() : end ) - str ) / CPS;
}
