#ifndef __PARTICLESETINITIALIZER__
#define __PARTICLESETINITIALIZER__

#include <vector>
#include "sd_defs.h"

class particleSetInitializer{

protected:
	std::vector<sd_real> _r0; // Position of Particle set
	std::vector<sd_real> _ri; 

public:
	particleSetInitializer( std::vector<sd_real> r0, std::vector<sd_real> ri ) : _r0{ r0 }, _ri{ ri } {}						 
	virtual 
};

class LineInitializer : public particleSetInitializer {

private:
	std::vector<sd_real> _dr;

public:
	LineInitializer( 	std::vector<sd_real> r0, 
						std::vector<sd_real> ri, 
						std::vector<sd_real> dr ) : particleSetInitializer( r0, ri ), 
													_dr{ dr } {};
	LineInitializer() : particleSetInitializer(), _dr{ 1.0, 0.0, 0.0 } {};

};

#endif