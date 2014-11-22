//============================================================================
// Name        : Producer.h
// Author      : Albin Engström
// Created     : 2014-11-22
// Modified    : 2014-11-22
// Description : Declaration of class Producer
// Purpose	   : Produce numbers and add them to mSharedBlockingQueue
//============================================================================

#ifndef PRODUCER_H_
#define PRODUCER_H_

#include "BlockingQueue.h"

#include <iostream>
#include <exception>

class Producer {
private:
	//Variable to hold the shared BlockingQueue
	BlockingQueue<int> *mSharedBlockingQueue;

	//Nr of elements to handle
	int mNrElements;

public:
	Producer(BlockingQueue<int> *blockingQueue, int nrElements);
	~Producer();

	void Run();
	//Pre:
	//Post: Produce numbers and add them to mSharedBlockingQueue
};

#endif /* PRODUCER_H_ */
