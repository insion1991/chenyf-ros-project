#ifndef SENSORREADING_H
#define SENSORREADING_H

#include "sensor.h"
namespace GMapping{
/*传感器读取的基类*/
class SensorReading{
	public:
		SensorReading(const Sensor* s=0, double time=0);
		inline double getTime() const {return m_time;}
		inline const Sensor* getSensor() const {return m_sensor;}
	protected:
    //时间
		double m_time;
    //传感器
		const Sensor* m_sensor;
};

}; //end namespace
#endif
