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
: m_size(size){


}

template <class T>
BlockingQueue<T>::~BlockingQueue() {

}

template <class T>
T BlockingQueue<T>::Take(){

	//Creates an unique_lock with m_mutex
	std::unique_lock<std::mutex> lock(m_mutex);

	//While m:queue is empty
	while (m_queue.empty())
	{
		//Wait m_condition_variable with lock
		m_condition_variable.wait(lock);
	}

	//Get the first element int m_queue
	T element = m_queue.front();

	//Remove the first element i m_queue
	m_queue.pop();

	//Return element
	return element;
}

template <class T>
void BlockingQueue<T>::Put(const T &item){

	//Creates an unique_lock with m_mutex
	std::unique_lock<std::mutex> lock(m_mutex);

	//Add item to the end of m_queue
	m_queue.push(item);

	//Unlock lock
	lock.unlock();

	//Notify one thread waiting with m_condition_variable
	m_condition_variable.notify_one();

}
