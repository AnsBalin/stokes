#include <iostream>

//#include "hdr/sd_data.h"
//#include "hdr/sd_defs.h"
#include <vector>

class Foo{

	protected: 
		int _x;

	public:
		int getX() const {return _x;};
		void setX( int x ){ _x = x; };
};

class Bar: public Foo{

public:
	void altSetX( int x ){ _x = x; };
};


int main(){

	std::cout << "Testing..." << std::endl;
	
	Bar b;
	b.altSetX(4);
	std::cout << b.getX() << std::endl;

	return 0;
}