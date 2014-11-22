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
	std::queue<T> m_queue = new std::queue<T>();

	//The size of the queue
	int mSize;

	//A mutex to lock the critical sections
	static std::mutex mMutex;

	//A condition variable to lock the critical sections
	static std::condition_variable mConditionVariable;


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

#endif /* BLOCKINGQUEUE_H_ */
