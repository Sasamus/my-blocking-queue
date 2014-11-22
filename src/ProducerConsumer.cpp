//============================================================================
// Name        : ProducerConsumer.cpp
// Author      : Albin Engström
// Created     : 2014-11-22
// Modified    : 2014-11-22
// Description : Implementation/Declaration/main
//============================================================================

#include "ProducerConsumer.h"

ProducerConsumer::ProducerConsumer()
: producerThread(NULL), consumerThread(NULL){

}

ProducerConsumer::~ProducerConsumer(){

}

void ProducerConsumer::Run(){

	//Create a BlockingQueue
	BlockingQueue<int> *sharedQueue =
	new BlockingQueue<int>(Q_SIZE);

	std::mutex *coutMutex = new std::mutex;

	//Create Producer and Consumer threads
	producerThread = new std::thread(&Producer::Run, Producer(sharedQueue, N_ELEM, coutMutex));
	consumerThread = new std::thread(&Consumer::Run, Consumer(sharedQueue, N_ELEM, coutMutex));

	producerThread->join();
	consumerThread->join();

}

