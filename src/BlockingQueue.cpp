//============================================================================
// Name        : BlockingQueue.cpp
// Author      : Albin Engström
// Created     : 2014-11-21
// Modified    : 2014-11-21
// Description : Implementation of class BlockingQueue
//============================================================================

#include "BlockingQueue.h"

template <class T>
BlockingQueue<T>::BlockingQueue(int size)
: mSize(size){


}

template <class T>
BlockingQueue<T>::~BlockingQueue() {

}

template <class T>
T BlockingQueue<T>::Take(){

	//Creates an unique_lock with m_mutex
	std::unique_lock<std::mutex> lock(mMutex);

	//While m_queue is empty
	while (m_queue.empty())
	{
		//Wait m_condition_variable with lock
		mConditionVariable.wait(lock);
	}

	//Get the first element int m_queue
	T element = m_queue.front();

	//Remove the first element i m_queue
	m_queue.pop();

	//Return element
	return element;
}

template <class T>
void BlockingQueue<T>::Put(const T &element){

	//Creates an unique_lock with m_mutex
	std::unique_lock<std::mutex> lock(mMutex);

	//Add element to the end of m_queue
	m_queue.push(element);

	//Unlock lock
	lock.unlock();

	//Notify one thread waiting with m_condition_variable
	mConditionVariable.notify_one();

}
