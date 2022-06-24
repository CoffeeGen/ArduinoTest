#include <thread.h>

Thread::Thread( unsigned long interval,void (*function)() ) 
{
    _active = true;
	_interval = interval;
	_execute = function;
}

void Thread::check()
{
    _current = millis();
    if( _active && ( _current - _previous >= _interval ) ) 
    {
        _previous = _current;
        _execute();
    }
}

void Thread::reset()
{
    _previous = millis();
}

void Thread::disable()
{
    _active = false;
}

void Thread::enable()
{
	_active = true;
}

void Thread::setInterval( unsigned long interval )
{
	_interval = interval;
}