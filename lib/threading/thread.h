#ifndef THREAD_H
#define THREAD_H

/**
 * Custom implementation for multi-threading.
 * This isn't really multi-threading, but it achieves the same goal more or less by using time checks.
 **/

#include <Arduino.h>

class Thread 
{
    public:
        Thread( unsigned long interval,void (*function)() );
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