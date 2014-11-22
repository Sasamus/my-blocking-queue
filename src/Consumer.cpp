//============================================================================
// Name        : Consumer.cpp
// Author      : Albin Engström
// Created     : 2014-11-22
// Modified    : 2014-11-22
// Description : Implementation of class Consumer
//============================================================================

#include "Consumer.h"

Consumer::Consumer(BlockingQueue<int> *blockingQueue, int nrElements)
: mSharedBlockingQueue(blockingQueue), mNrElements(nrElements){

}

Consumer::~Consumer(){
}

void Consumer::Run(){

	for(int i=0; i < mNrElements; i++){
		try {

			//Calls mSharedBlockingQueue's Take()
			int value = mSharedBlockingQueue->Take();

			//Print that i was produced
			std::cout << "Consumed: " << value << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

}

