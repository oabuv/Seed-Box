#include "project_functions.h"

TEST(moistureReader, tooHighValue){
    int ADC_val = 4095;
    double percentage = moisture_percentage(ADC_val);

    EXPECT_EQ(percentage, 100.00);
}

TEST(moistureReader, tooLowValue){
    int ADC_val = 1;
    double percentage = moisture_percentage(ADC_val);

    EXPECT_EQ(percentage, 0.00);
}

TEST(moistureReader, normalValue){
    int ADC_val = 2544;
    int percentage = moisture_percentage(ADC_val);

    EXPECT_EQ(percentage, 50);
}


TEST(luxReader, normalValue){
    int ADC_val = 700;
    int lux = measured_lux(ADC_val);

    EXPECT_EQ(lux, 387);
}