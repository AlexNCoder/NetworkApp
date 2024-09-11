#include "sender.h"
#include <iostream>
#include <mosquittoconnect.h>

void Sender::send(std::string message)
{
	const char* id = new char(1);
	void* obj = nullptr;
	auto mosqInstance = MosquittoConnect();

	mosqInstance.pub("testMsg110824");
}
