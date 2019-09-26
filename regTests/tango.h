#ifndef TANGO_H
#define TANGO_H

#include <vector>
#include <sstream>
#include <iostream>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>
#include <string.h>

using namespace std;

//#define INFO_STREAM cout

class omni_thread
{
public:
	omni_thread(){};
	void start_undetached(){};
	int join(void**){};
};

class omni_mutex
{
public:
	omni_mutex():mut(PTHREAD_MUTEX_INITIALIZER){};
	int lock(){return pthread_mutex_lock(&mut);};
	int unlock(){return pthread_mutex_unlock(&mut);};
	int trylock(){return pthread_mutex_trylock(&mut);};
private:
	pthread_mutex_t mut;
};

namespace Tango
{

class DevState
{
	int state;
};

class DevFailed
{
	int failCause;
};


class DeviceImpl
{
};

class LogAdapter
{
public:
	LogAdapter(DeviceImpl *dev){};
};

};
#endif
