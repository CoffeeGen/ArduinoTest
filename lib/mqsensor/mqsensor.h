#include <Arduino.h>

class MqSensor 
{
    public:
        MqSensor( uint8_t sensorPin );
        int value();

    private:
        uint8_t _sensorPin;
};