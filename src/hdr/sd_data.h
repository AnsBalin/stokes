#ifndef __DATA__
#define __DATA__

#include <iostream>
#include <vector>
#include "sd_rawData.h"
#include "sd_particleSet.h"
#include "sd_defs.h"
#include "sd_attractiveForce.h"

class data{

private:
	std::vector<particleSet> _setsOfParticles;
	rawData					 _raw;
	int						 _Ntot;
	
public:

	data() {};
	data( int dim, int N );
	void computeForces();
	
};
#endif 