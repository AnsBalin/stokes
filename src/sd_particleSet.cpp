#include "hdr/sd_particleSet.h"

// implies we already know N so end = begin + N
void particleSet::setBeginEnd( int begin ){

	_begin = begin;
	_end = begin + _N;
}

void particleSet::applyAttractiveForces( rawData& raw ) const{

	for ( auto f : _af ) f->apply( raw, _begin, _end );



}

