#include "hdr/sd_particleSetInitializer.h"

/*int lineInitializer::nextPos( std::vector<sd_real>& r, const rawData& raw  ){

	int retval;

	int i = 0;

	r.clear();

	for ( auto& dr_k : _dr )
	{
		r.push_back( _ri[++i] + dr_k );
	}

	return retval;

}*/

void lineInitializer::make(){

	build(); // Maybe make this part of constructor
	if ( ! raw.overlap( _ri ) )
	{
		raw.addParticles( _ri );
	}
}

void lineInitializer::build( ){


	for (int i = 0; i < _N; ++i)
	{
		for (int k = 0; k < _dim; ++k)
		{
			_ri.push_back( _r0[k] + k*_dr[k] );
		}
	}


}