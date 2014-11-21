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

#include <vector>
#include <mutex>
#include <condition_variable>

template <class T>
class BlockingQueue {

private:
	//A queue
	std::vector<T> m_queue = new std::vector<T>();

	//The size of the queue
	int m_size;

	//A mutex to lock the critical sections
	std::mutex m_mutex;

	//A condition variable to lock the critical sections
	std::condition_variable m_condition_variable;


public:
	BlockingQueue(int size);
	virtual ~BlockingQueue();

	T Take();
	//Pre:
	//Post: Returns element at the start of m_queue

	void Put();
	//Pre:
	//Post: Puts and element at the back of m_queue
};

#endif /* BLOCKINGQUEUE_H_ */
