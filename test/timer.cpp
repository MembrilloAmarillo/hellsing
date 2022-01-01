#include <ctime>

class Timer {
private:

	bool active;

	std::clock_t str, end;

	/* CLOCKS PER SEC*/
	static double CPS;

public:
	Timer() : active( false ) {}
	~Timer() = default;

	void   start();
	void   stop();
	double time() const;
};

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
