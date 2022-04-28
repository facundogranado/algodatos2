#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include "weather.h"
#include "array_helpers.h" 

int min_tem(WeatherTable a);

void may_tem_max_year(WeatherTable a, int b[YEARS]);

void mon_prec_max_year(WeatherTable a, t_month b[MONTHS]);

#endif