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

			//Print that i was consumed
			std::lock_guard<std::mutex> lock(*mCoutMutex);
			std::cout << "Consumed: " << value << std::endl;

		} catch (std::exception &e) {
			std::lock_guard<std::mutex> lock(*mCoutMutex);
			std::cout << e.what() << std::endl;
		}
	}

}

