//=============================================================
// Name         : main.cpp
// Author       : Albin Engström
// Created      : 2014-11-21
// Modified     : 2014-11-21
// Description  : main for project my-blocking-queue
// Purpose      : Start the program
//=============================================================


using namespace std;

int main()
{
	//Create a PruducerConsumer
	ProducerConsumer producerconsumer = new ProducerConsumer();

	//Call its Run() method
	producerconsumer.Run();

	//Return 0
    return 0;
}
