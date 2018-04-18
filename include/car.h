//2017/11/23
//auther: eiki obara

#ifndef __CAR_H__
#define __CAR_H__

#include <vector>

namespace Trl{

struct CarParam{
	double weight;
	double length;
	double width;
	double wheelBase;
	double tread[2];

	double maxVel[2];
};

typedef std::vector<double> WayT;
typedef std::vector<double> VelT;

class Car{
private:
	//車の情報を保持
	CarParam param;

	//現在のハンドル角度を保持
	double handleAngle;

	//(x,y,theta): car state parametor
	//car controller

public:
	//どんな車か情報を与える
	Car(CarParam p);

	//経路情報を与える
	//たぶん操舵角の角度変化情報と、タイヤの回転速度を与えると思う
	//車を走らせる
	void Run(WayT w, VelT v);	

};






}	//namespace Trl

#endif	// __CAR_H__
