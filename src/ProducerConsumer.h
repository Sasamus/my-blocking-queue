//============================================================================
// Name        : ProducerConsumer.h
// Author      : Albin Engström
// Created     : 2014-11-22
// Modified    : 2014-11-22
// Description : Declaration of class ProducerConsumer
// Purpose	   : Create and start Producer and Consumer threads
// 			   : and their shared objects
//============================================================================

#ifndef PRODUCERCONSUMER_H_
#define PRODUCERCONSUMER_H_

#include <BlockingQueue.h>

#include <thread>

class ProducerConsumer {
private:
	//Nr of elements to handle
	const int N_ELEM = 200;

	//Size of the queue
	const int Q_SIZE = 3;

	//Threads
	std::thread producerThread = NULL, consumerThread = NULL;

public:
	ProducerConsumer();
	~ProducerConsumer();
};

#endif /* PRODUCERCONSUMER_H_ */
