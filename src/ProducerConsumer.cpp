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

	//Producer *producer = new Producer(*sharedQueue, N_ELEM);
	//Consumer *consumer = new Consumer(*sharedQueue, N_ELEM);

	//Create Producer and Consumer threads
	producerThread = new std::thread(&Producer::Run, Producer(*sharedQueue, N_ELEM));
	consumerThread = new std::thread(&Consumer::Run, Consumer(*sharedQueue, N_ELEM));

}

