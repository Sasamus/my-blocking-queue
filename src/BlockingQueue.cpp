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

