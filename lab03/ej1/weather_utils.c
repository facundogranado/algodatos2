#include <stdio.h>
#include <stdlib.h>

#include "weather_utils.h"
#include "weather.h"
#include "array_helpers.h"

int min_tem(WeatherTable a){

    int min = a[0u][january][0u]._min_temp;
    
    for (unsigned int years = 0u; years < YEARS; years++)
    {
        for (t_month months = january; months < MONTHS; months++)
        {
            for (unsigned int days = 0u; days < DAYS; days++)
            {
                if (min<a[years][months][days]._min_temp)
                {
                    min=a[years][months][days]._min_temp;
                }
                
            }
            
        }
        
    }
    
    return min;
} 