#ifndef __RAWDATA__
#define __RAWDATA__

#include <vector>
#include "sd_defs.h"
#include <cmath>

#define squ(x,y) 	(_N*x + y)
#define vec(i,k)	(_dim*i + k)


class rawData{

private:

	std::vector<sd_real> _r; // Instantaneous positions
	std::vector<sd_real> _f;	// Instantaneous forces
	std::vector<sd_real> _dw;// zero-mean, unit-var gaussian vector
	std::vector<sd_real> _D; // Diffusion Tensor
	std::vector<sd_real> _B; // sqrt Diffusion Tensor
	std::vector<sd_real> _rr_ij;	// square-separation matrix
	const 	int 			_dim; // dimension of simulation
			int 			_N;
public:

	rawData() : _dim{0} {};
	rawData( int dim, int N ): 	_r( N*dim, 0.0 ),
								_f( N*dim, 0.0),
								_dw( N*dim, 0.0 ),
								_D( N*dim*N*dim, 0.0),
								_B( N*dim*N*dim, 0.0 ),
								_rr_ij( N*N, 0.0),
								_dim{dim},
								_N{ N }
								{};

	sd_real getSeparation( int p1, int p2 ) const;
	sd_real getSquareSeparation( int p1, int p2 ) const;
	void pairForce( int p1, int p2, sd_real f );
	void addSetOfParticles( const particleSet& ps_new );


};


#endif