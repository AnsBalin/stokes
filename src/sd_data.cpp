#include "hdr/sd_data.h"


data::data( int dim, int N): 	_raw{dim, N}, 
								_setsOfParticles{ 
													particleSet { 0, N }												} 
								{ }

void data::computeForces(){

	for( const auto& ps : _setsOfParticles ) ps.applyAttractiveForces( _raw );

}


void data::addSetOfParticles( particleSet& ps_read ){

	sd_err = error_status;
	particleSet ps_new { ps_read };
	ps_new.setBeginEnd( _Ntot );
	_Ntot+=ps_new.getN();

	_raw.addSetOfParticles( ps_new );

	//error_status = ps_new.addSetOfParticles( _raw );

	if ( error_status )
	{
		print("Exiting with error_status %d\n", error_status);
		exit();
	}

	_setsOfParticles.push_back( ps_new );

}