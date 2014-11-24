//============================================================================
// Name        : Producer.cpp
// Author      : Albin Engström
// Created     : 2014-11-22
// Modified    : 2014-11-22
// Description : Implementation of class Producer
//============================================================================

#include "Producer.h"

Producer::Producer(BlockingQueue<int> *blockingQueue, int nrElements, std::mutex *coutMutex)
: mSharedBlockingQueue(blockingQueue), mNrElements(nrElements), mCoutMutex(coutMutex){

}

Producer::~Producer(){
}


void Producer::Run(){

	for(int i=1; i < mNrElements + 1; i++){
		try {

			//Calls mSharedBlockingQueue's Put() with i
			mSharedBlockingQueue->Put(i);

			//Print that i was produced
			std::lock_guard<std::mutex> lock(*mCoutMutex);
			std::cout << "Produced: " << i << std::endl;

		} catch (std::exception &e) {
			std::lock_guard<std::mutex> lock(*mCoutMutex);
			std::cout << e.what() << std::endl;
		}
	}

}

