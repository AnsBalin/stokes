#include "hdr/sd_attractiveForce.h"

void hookeForce::apply( rawData& raw, int begin, int end ) const{

	sd_real f;

	for ( int particle = begin; particle < end-1; ++particle){

		f = -_k * raw.getSeparation( particle, particle+1 );
	
		raw.pairForce( particle, particle+1, f );

	}

}

void feneForce::apply( rawData& raw, int begin, int end ) const{

	sd_real rr, f;

	for ( int particle = begin; particle < end-1; ++particle){

		rr = raw.getSquareSeparation( particle, particle+1 );
		f = (rr > 0.6*_rr0) ? (_fmax) : (30*_rr0*sqrt(rr)/(rr - _rr0));
		
		raw.pairForce( particle, particle+1, f );

	}

}

