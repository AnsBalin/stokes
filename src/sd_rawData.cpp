#include "hdr/sd_rawData.h"

sd_real rawData::getSeparation( int p1, int p2 ) const {

	return (sd_real) sqrt( _rr_ij[ squ(p1,p2) ] );
}


sd_real rawData::getSquareSeparation( int p1, int p2 ) const {

	sd_real rval = 0.0;
	for (int k = 0; k < _dim; ++k)
	{
	 	rval += (_r[ vec(p1,k) ]-_r[ vec(p2,k) ])*(_r[ vec(p1,k) ]-_r[ vec(p2,k) ]);
	} 
	return rval;
}

void rawData::pairForce( int p1, int p2, sd_real f ){

	sd_real tmp;
	for (int k = 0; k < _dim; ++k)
	{
		
		tmp = f*(_r[ vec(p1,k) ] - _r[ vec(p2,k) ]);
	 	_f[ vec(p1,k) ] += tmp;
	 	_f[ vec(p2,k) ] -= tmp;

	}

}

