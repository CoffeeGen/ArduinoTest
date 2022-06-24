#include <Arduino.h>

class Led 
{
    public:
        Led(int ledPin);
        void trigger( bool toggle );

    private:
        int _ledPin;
};