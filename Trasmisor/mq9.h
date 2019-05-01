#ifndef _MQ9_H
#define _MQ9_H
#include "inicializar.h"

float ConcentracionMQ9();
float readMQ(int mq_pin);
float getMQResistance(int raw_adc);
float getConcentration(float rs_ro_ratio);


#endif
