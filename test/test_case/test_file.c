#include "project_functions.h"

// Test cases for soil sensor
TEST(moistureReader, MaxValueExceeded){
    int ADC_val = 4095;
    double percentage = moisture_percentage(ADC_val);

    EXPECT_EQ(percentage, 100.00);
}

TEST(moistureReader, MinValueExceeded){
    int ADC_val = 1;
    double percentage = moisture_percentage(ADC_val);

    EXPECT_EQ(percentage, 0.00);
}

TEST(moistureReader, normalValue){
    int ADC_val = 2544;
    int percentage = moisture_percentage(ADC_val);

    EXPECT_EQ(percentage, 50);
}

// Test cases for light sensor
TEST(luxReader, tooDark){
    int ADC_val = 10000;
    int lux = measured_lux(ADC_val);

    EXPECT_EQ(lux, 10);
}

TEST(luxReader, tooBright){
    int ADC_val = 100;
    int lux = measured_lux(ADC_val);

    EXPECT_EQ(lux, 5535);
}

TEST(luxReader, normalLight){
    int ADC_val = 700;
    int lux = measured_lux(ADC_val);

    EXPECT_EQ(lux, 387);
}