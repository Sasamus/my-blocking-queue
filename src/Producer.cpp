//============================================================================
// Name        : Producer.cpp
// Author      : Albin Engström
// Created     : 2014-11-22
// Modified    : 2014-11-22
// Description : Implementation of class Producer
//============================================================================

#include "Producer.h"

Producer::Producer(BlockingQueue<int> blockingQueue, int nrElements)
: mSharedBlockingQueue(blockingQueue), mNrElements(nrElements){


}

void Producer::Run(){

	for(int i=0; i < mNrElements; i++){
		try {

			//Calls mSharedBlockingQueue's Put() with i
			mSharedBlockingQueue.Put(i);

			//Print that i was produced
			std::cout << "Produced: " << i << std::endl;

		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;;
		}
	}

}

