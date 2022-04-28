#include <stdio.h>
#include <stdlib.h>

#include "weather_utils.h"
#include "weather.h"
#include "array_helpers.h"

int min_tem(WeatherTable a){

    int min = a[0u][january][0u]._min_temp;

    for (unsigned int years = 0u; years < YEARS; years++){
        for (t_month months = january; months < MONTHS; months++){
            for (unsigned int days = 0u; days < DAYS; days++){
                if (min > a[years][months][days]._min_temp){
                    min = a[years][months][days]._min_temp;
                }
            }
        }
    }

    return min;
}

void may_tem_max_year(WeatherTable a, int b[YEARS]){

    int temMaxYear;
    for (unsigned int years = 0u; years < YEARS; years++)
    {
        temMaxYear = 0;
        for (t_month months = january; months < MONTHS; months++){
            for (unsigned int days = 0u; days < DAYS; days++){
                if (temMaxYear < a[years][months][days]._max_temp){
                    temMaxYear = a[years][months][days]._max_temp;
                }
            }
        }
        b[years] = temMaxYear;
    }
}

void mon_prec_max_year(WeatherTable a, t_month b[MONTHS]){
    unsigned int precMax;
    unsigned int precM;
    t_month precMaxMon;
    for (unsigned int years = 0u; years < YEARS; years++){
        precMaxMon = january;
        precMax = 0;
        for (t_month months = january; months < MONTHS; months++){
            precM = 0;
            for (unsigned int days = 0u; days < DAYS; days++){
                    precM += a[years][months][days]._rainfall;
            }

            if (precMax<precM){
                precMax = precM;
                precMaxMon = months;
            }         
        }
        b[years] = precMaxMon;
    }
}
