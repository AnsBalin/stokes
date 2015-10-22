#include "hdr/sd_simulation.h"


simulation::simulation( int simnum, std::string simdir ): 	_simnum{simnum}, 
													_simdir{simdir},
													_elapsed{0},
													_data{} 
{

	/* Pseudo-psuedocode */
	for( auto file : directory ){

		data.addSetOfParticles( readParticleSet( file ) );

	}

}

void simulation::run( const sd_time& steps ){

	clock_t t1 = clock();
	clock_t t2 = t1;
	
	for (auto t = 0; t < steps; ++t)
	{
		_data.update();
	}

	lookAtClock( &t1, &t2, &steps );
}

void simulation::lookAtClock( sd_time& t1, sd_time& t2, const sd_time& steps ){

	t1 = clock();
	_elapsed += (t2-t1)/1000000;
	t2 = t1;

}



void simulation::output(){

	_data.printData();
}