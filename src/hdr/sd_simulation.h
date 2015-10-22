#ifndef __SIMULATION__
#define __SIMULATION__

#include "sd_data.h"
#include "sd_defs.h"
#include <ctime>
#include <string>

class simulation{

private:
			data 		_data;
			
			sd_clock	_elapsed;
	const	int			_simnum;
	const 	std::string	_simdir;

public:

	simulation( int simnum, std::string simdir );

	void run( const sd_time& steps );
	void lookAtClock( sd_time& t1, sd_time& t2, const sd_time& steps );
	void output();


};

#endif