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

template <class T>
class BlockingQueue {

private:
	std::vector<T> m_queue = new std::vector<T>();
	int m_size;

public:
	BlockingQueue(int size);
	virtual ~BlockingQueue();
};

#endif /* BLOCKINGQUEUE_H_ */
