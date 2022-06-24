#include "Arduino.h"
#include <usensor.h>
#include <led.h>
#include <mqsensor.h>
#include <eth.h>
#include <protothread.h>

#define echoPin         2
#define trigPin         3
#define greenLedPin     4
#define redLedPin       7
#define mqSensorPin     A0

USensor* uSensor;
MqSensor* mqSensor;

Led* greenLed;
Led* redLed;

Eth* eth0;

void updateLeds() 
{
    // Distance Sensor - Green Led
    int distance = uSensor->calcDistance();
    greenLed->trigger( distance < 5 );

    // Smoke Sensor - Red Led
    int smokeValue = mqSensor->value();
    redLed->trigger( smokeValue > 1000 );

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm | ");
    Serial.print("Smoke value: ");
    Serial.println(smokeValue);
}

void checkNetwork( )
{
    // Network
    IPAddress addr = eth0->getIpAddress();

    Serial.print( "IP Address: " );
    Serial.println( addr );
}

ProtoThread threads[] = {
    ProtoThread(200, updateLeds),
    ProtoThread(1000, checkNetwork),
};

void setup()
{
    // Sensors
    uSensor = new USensor( echoPin, trigPin );
    mqSensor = new MqSensor( mqSensorPin );

    // Leds
    greenLed = new Led( greenLedPin );
    redLed = new Led( redLedPin );

    // Eth
    eth0 = new Eth();

    // Serial
    Serial.begin(9600);

    Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
    Serial.println("with Arduino UNO R3");
}

void loop()
{
    for( ProtoThread &t : threads )
    {
        t.check();
    }
}