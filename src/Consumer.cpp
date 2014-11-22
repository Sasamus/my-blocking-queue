//============================================================================
// Name        : Consumer.cpp
// Author      : Albin Engström
// Created     : 2014-11-22
// Modified    : 2014-11-22
// Description : Implementation of class Consumer
//============================================================================

#include "Consumer.h"

Consumer::Consumer(BlockingQueue<int> *blockingQueue, int nrElements, std::mutex *coutMutex)
: mSharedBlockingQueue(blockingQueue), mNrElements(nrElements), mCoutMutex(coutMutex){

}

Consumer::~Consumer(){
}

void Consumer::Run(){

	for(int i=0; i < mNrElements; i++){
		try {

			//Calls mSharedBlockingQueue's Take()
			int value = mSharedBlockingQueue->Take();

			//Print that i was produced
			mCoutMutex->lock();
			std::cout << "Consumed: " << value << std::endl;
			mCoutMutex->unlock();

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

}

