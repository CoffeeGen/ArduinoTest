#include <protothread.h>

ProtoThread::ProtoThread( unsigned long interval,void (*function)() ) 
{
    _active = true;
	_interval = interval;
	_execute = function;
}

void ProtoThread::check()
{
    _current = millis();
    if( _active && ( _current - _previous >= _interval ) ) 
    {
        _previous = _current;
        _execute();
    }
}

void ProtoThread::reset()
{
    _previous = millis();
}

void ProtoThread::disable()
{
    _active = false;
}

void ProtoThread::enable()
{
	_active = true;
}

void ProtoThread::setInterval( unsigned long interval )
{
	_interval = interval;
}