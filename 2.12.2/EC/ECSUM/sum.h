#ifndef SUM_H
#define SUM_H

#include <NTL/ZZ>
#include <NTL/ZZ_p>

using namespace NTL;

class EC{
public:
	EC(ZZ , ZZ, ZZ);
	Point sum(Point, Point);
//TODO hide this values
	struct Point;
};


#endif
