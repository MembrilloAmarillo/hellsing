/* date = January 2nd 2022 5:10 pm */

#ifndef TIMER_H
#define TIMER_H

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

#endif //TIMER_H
