// NetworkApp.cpp: определяет точку входа для приложения.
//

#include "NetworkApp.h"
//#include <cpp/mosquittopp.h>
#include <mosquitto.h>

using namespace std;

int main()
{
	cout << "Hello CMake1." << endl;
	const char* id = new char(1);
	void* obj = nullptr;
	//mosqpp::mosquittopp();
	auto res = mosquitto_new(id, false, obj);
	cout << "Hello moscuitto" << endl;

	return 0;
}
