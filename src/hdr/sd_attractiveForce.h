#ifndef __ATTRACTIVEFORCE__
#define __ATTRACTIVEFORCE__

#include "sd_rawData.h"
#include "sd_defs.h"

class attractiveForce{

public:
	virtual void apply( rawData& raw, int begin, int end ) const = 0; // Must be overridden by derived classes


};


/*
**
**		Hooke
**
*/
class hookeForce : public attractiveForce{

private:
	const sd_real _k; // Spring constant

public:
	hookeForce(): _k(0.0){};
	void apply( rawData& raw, int begin, int end ) const;

};

/*
**
**		Fene
**
*/
class feneForce : public attractiveForce{

private:
	const sd_real _rr0; 
	const sd_real _fmax;

public:
	void apply( rawData& raw, int begin, int end ) const;

};

#endif