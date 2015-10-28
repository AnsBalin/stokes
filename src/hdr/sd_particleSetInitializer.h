#ifndef __PARTICLESETINITIALIZER__
#define __PARTICLESETINITIALIZER__

#include <vector>
#include "sd_defs.h"
#include "sd_rawData.h"

class particleSetInitializer{

protected:
	std::vector<sd_real> _r0; // Position of Particle set
	std::vector<sd_real> _ri;
	const int 			 _dim, _N;

public:
	particleSetInitializer( std::vector<sd_real> r0, std::vector<sd_real> ri ) : _r0{ r0 }, _ri{ ri } {}						 
	//virtual int nextPos( std::vector<sd_real>& r  ) = 0;
	virtual make( rawData& raw ) = 0;
	virtual build() = 0;
};

class lineInitializer : public particleSetInitializer {

private:
	std::vector<sd_real> _dr;

public:
	LineInitializer( 	std::vector<sd_real> r0, 
						std::vector<sd_real> ri, 
						std::vector<sd_real> dr ) : particleSetInitializer( r0, ri ), 
													_dr{ dr } {};
	LineInitializer() : particleSetInitializer(), _dr{ 1.0, 0.0, 0.0 } {};

	//int nextPos( std::vector<sd_real>& r, const rawData& raw  ) = 0;
	void make( rawData& raw );
	void build();

};




#endif