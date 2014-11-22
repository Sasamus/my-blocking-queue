//============================================================================
// Name        : Consumer.h
// Author      : Albin Engström
// Created     : 2014-11-22
// Modified    : 2014-11-22
// Description : Declaration of class Consumer
// Purpose	   : Consume numbers from mSharedBlockingQueue
//============================================================================

#ifndef CONSUMER_H_
#define CONSUMER_H_

#include "BlockingQueue.h"

#include <iostream>
#include <exception>
#include <mutex>

class Consumer {
private:
	//Variable to hold the shared BlockingQueue
	BlockingQueue<int> *mSharedBlockingQueue;

	//Nr of elements to handle
	int mNrElements;

	//Mutex to keep cout from interleaving
	std::mutex *mCoutMutex;

public:
	Consumer(BlockingQueue<int> *blockingQueue, int nrElements, std::mutex *coutMutex);
	~Consumer();

	void Run();
	//Pre:
	//Post: Consume numbers from mSharedBlockingQueue
};

#endif /* CONSUMER_H_ */
