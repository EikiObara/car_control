#include "carCalculator.h"

#include <cmath>

//回転角度の算出
double CalcAngle(const double radius,const double wheelBase){
	return asin(radius/wheelBase);
}

//回転半径の算出
double CalcRadius(const double wheelAngle, const double wheelBase){
	return wheelBase/sin(wheelAngle);
}

//2輪モデルによる近似をした内側回転半径の算出
double CalcInnerRadius(double angle, Trl::CarParam p){
	double centerRad = CalcRadius(fabs(angle), p.wheelBase);

	double innerRad = pow(p.wheelBase,2)-pow(centerRad*cos(fabs(angle))+p.tread[1]/2,2);

	return sqrt(innerRad);
}


//2輪モデルによる近似をした外側回転半径の算出
//approximate model by two wheel
double CalcOuterRad(double angle,Trl::CarParam p){
	double originRad = CalcRadius(fabs(angle),p.wheelBase);

	double buf = pow(p.wheelBase,2) + pow(originRad*cos(fabs(angle))+p.tread[1]/2,2);

	return sqrt(buf);
}

