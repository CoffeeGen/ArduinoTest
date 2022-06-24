#ifndef PROTOTHREAD_H
#define PROTOTHREAD_H

#include <Arduino.h>

class ProtoThread 
{
    public:
        ProtoThread( unsigned long interval,void (*function)() );
        void reset();
        void disable();
        void enable();
        void check();
	    void setInterval( unsigned long interval );

    private:
        bool _active;
        unsigned long _previous;
        unsigned long _interval;
        unsigned long _current;
        void (*_execute)();
};

#endif