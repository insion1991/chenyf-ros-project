#ifndef RANGEREADING_H
#define RANGEREADING_H

#include <vector>
#include <gmapping/sensor/sensor_base/sensorreading.h>
#include <gmapping/sensor/sensor_range/rangesensor.h>

namespace GMapping{
/*
 * 激光传感器数据类
 * 这个类集自传感器数据类
 * 也就说从传感器数据类(SebsirReading)里面继承了两个变量 传感器的名字 + 数据的时间戳
 *
 * 这个类相当于用集成自vector的数组来储存激光的距离数据。
 * 然后用RangeSensor这个类来储存激光的角度数据
 * 实际上角度数据 也可以储存在这里面
 *
 */
class RangeReading: public SensorReading, public std::vector<double>{
	public:
    /*构造函数*/
		RangeReading(const RangeSensor* rs, double time=0);
		RangeReading(unsigned int n_beams, const double* d, const RangeSensor* rs, double time=0);
		virtual ~RangeReading();
    //得到这帧激光数据的位置
		inline const OrientedPoint& getPose() const {return m_pose;}
     //设置这帧传感器数据的位置
		inline void setPose(const OrientedPoint& pose) {m_pose=pose;}
		unsigned int rawView(double* v, double density=0.) const;
		std::vector<Point> cartesianForm(double maxRange=1e6) const;
		unsigned int activeBeams(double density=0.) const;
	protected:
    //这帧激光数据的位置 这里的位置表示的是机器人的位姿 不是激光雷达的位姿
		OrientedPoint m_pose;
};

};

#endif
