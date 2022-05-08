#include "project_functions.h"

double moisture_percentage(int ADC_val){
    int minimum = 1200; // Minimal possible voltage, this means that the sensor is currently dipped in water
    int maximum = 2900; // Maximal possible voltage, this means that the sensor is currently measuring the air
    double max_value = maximum - minimum; // Maximal possible delta-Voltage

    double voltage = (float)ADC_val / 4096 * 3300;

    if(voltage < minimum){
        return 0.00;
    } else if(voltage > maximum){
        return 100.00;
    } else {
        double delta_voltage = voltage - minimum;
        double percentage = (max_value - delta_voltage) / max_value * 100.00;
        return percentage;
    }
}


double measured_lux(int ADC_val){
    return 3.0 * 1000000.0 * pow(((double)ADC_val), -1.367);
}