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

template <class T>
class BlockingQueue {

private:
	//A queue
	std::queue<T> *m_queue = new std::queue<T>();

	//The size of the queue
	int mSize;

	//A mutex to lock the critical sections
	std::mutex mMutex;

	//A condition variable to lock the critical sections
	std::condition_variable mConditionVariable;


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
 delete m_queue;
}

template <class T>
T BlockingQueue<T>::Take(){

	//Creates an unique_lock with m_mutex
	std::unique_lock<std::mutex> lock(mMutex);

	//While m_queue is empty
	while (m_queue->empty())
	{
		//Wait m_condition_variable with lock
		mConditionVariable.wait(lock);
	}

	//Get the first element int m_queue
	T element = m_queue->front();

	//Remove the first element i m_queue
	m_queue->pop();

	//Return element
	return element;
}

template <class T>
void BlockingQueue<T>::Put(const T &element){

	//Creates an unique_lock with m_mutex
	std::unique_lock<std::mutex> lock(mMutex);

	//Add element to the end of m_queue
	m_queue->push(element);

	//Unlock lock
	lock.unlock();

	//Notify one thread waiting with m_condition_variable
	mConditionVariable.notify_one();

}

#endif /* BLOCKINGQUEUE_H_ */

