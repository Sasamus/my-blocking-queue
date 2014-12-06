//============================================================================
// Name        : BlockingQueue.h
// Author      : Albin Engström
// Created     : 2014-11-21
// Modified    : 2014-11-21
// Description : Declaration of class BlockingQueue
// Purpose	   : My own C++ version of java's Blocking Queue
//============================================================================

#ifndef BLOCKINGQUEUE_H_
#define BLOCKINGQUEUE_H_

#include <queue>
#include <mutex>
#include <condition_variable>
#include <iostream>

/*
 * My implementation of a blocking queue is based around normal queue
 * with FIFO functionality and added thread-safety, size management
 * and lastly blocking implemented with mutex's, condition_variable's
 * and unique_locks.
 */

template <class T>
class BlockingQueue {

private:
	//A queue
	std::queue<T> *mQueue = new std::queue<T>();

	//The size of the queue
	int mSize;

	//Mutex to lock the critical sections
	std::mutex mMutex;

	//Condition variable's to lock the critical sections
	std::condition_variable mPutConditionVariable;
	std::condition_variable mTakeConditionVariable;

public:
	BlockingQueue(int size);
	~BlockingQueue();

	T Take();
	//Pre:
	//Post: Returns the element at the start of m_queue

	void Put(const T &element);
	//Pre:
	//Post: Adds an element at the back of m_queue
};

//Implementations of the functions

template <class T>
BlockingQueue<T>::BlockingQueue(int size)
: mSize(size){

}

template <class T>
BlockingQueue<T>::~BlockingQueue() {
 delete mQueue;
}

template <class T>
T BlockingQueue<T>::Take(){

	std::unique_lock<std::mutex> lock = std::unique_lock<std::mutex>(mMutex);

	//While mQueue is empty
	while (mQueue->empty())
	{
		//Wait mTakeConditionVariable with takeLock
		mTakeConditionVariable.wait(lock);
	}

	//Get the first element int mQueue
	T element = mQueue->front();

	//Remove the first element i mQueue
	mQueue->pop();

	//Notify one thread waiting with mPutConditionVariable
	mPutConditionVariable.notify_one();

	//Return element
	return element;
}

template <class T>
void BlockingQueue<T>::Put(const T &element){

	std::unique_lock<std::mutex> lock = std::unique_lock<std::mutex>(mMutex);

	//While mQueue is full
	while (mQueue->size() == (unsigned)mSize)
	{
		//Wait mPutConditionVariable with putLock
		mPutConditionVariable.wait(lock);
	}

	//Add element to the end of m_queue
	mQueue->push(element);

	//Notify one thread waiting with mTakeConditionVariable
	mTakeConditionVariable.notify_one();

}

#endif /* BLOCKINGQUEUE_H_ */

