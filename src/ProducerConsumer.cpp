//============================================================================
// Name        : ProducerConsumer.cpp
// Author      : Albin Engström
// Created     : 2014-11-22
// Modified    : 2014-11-22
// Description : Implementation/Declaration/main
//============================================================================

#include "ProducerConsumer.h"

void ProducerConsumer::Run(){

	//Create a BlockingQueue
	BlockingQueue<int> sharedQueue =
	new BlockingQueue<int>(Q_SIZE);

	//Create Producer and Consumer threads
	producerThread = new std::thread(new Producer(sharedQueue, N_ELEM));
	consumerThread = new std::thread(new Consumer(sharedQueue, N_ELEM));

}

