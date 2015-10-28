#ifndef __PARTICLESET__
#define __PARTICLESET__

#include <vector>
#include <memory>
#include "sd_attractiveForce.h"
#include "sd_defs.h"
#include "sd_particleSetInitializer.h"

typedef std::vector<attractiveForce*> af_type;

class particleSet{

private:

	particleSetInitializer 	_init;
	af_type					_af; 
	int						_begin, _end; // Particle IDs 
	int						_N;
	const int				_type;

public:

	// Constructors
	particleSet(  ): 	_af{}, 
						_N{0}, 
						_type{ SD_GAS } {};

	particleSet( int begin, int end ): 	_af{  },
										_begin{begin}, 
										_end{end}, 
										_N{end-begin}, 
										_type{SD_GAS} {};
	
	// Setters and Getters
	void setBeginEnd( int begin );
	auto getN() const { return _N };
	auto getType() const { return _type };

	// Other
	void applyAttractiveForces( rawData& raw ) const;
};

#endif