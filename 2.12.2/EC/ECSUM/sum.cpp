#include <iostream>
#include <NTL/ZZ>
#include <NTL/ZZ_p>
#include <NTL/ZZ_px>
#include <sum.h>

using namespace NTL;

EC::EC(ZZ a, ZZ b, ZZ p)
{
	ZZ_p::init(p);
}

Point EC::sum(Point p1, Point p2)
{
	ZZ_p u = p2.y - p1.y;
        ZZ_p uu = u * u;	
      	ZZ_p v = p2.x - p1.x;
      	ZZ_p vv = v * v;
	ZZ_p vvv = v * vv;
	ZZ_p R = vv * p1.x;
	ZZ_p A = uu - vvv - 2*R;
      	ZZ_p x3 = v * A;
      	ZZ_p y3 = u * (R - A) - vvv * p1.y;
      	ZZ_p Z3 = vvv;
	return EC:Point{x3, y3, z3};
}

struct EC::Point{
	ZZ_p x, y, z;
};
