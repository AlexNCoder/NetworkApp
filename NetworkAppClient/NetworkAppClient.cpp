// NetworkApp.cpp: определяет точку входа для приложения.
//

#include "NetworkAppClient.h"
//#include <cpp/mosquittopp.h>
#include <mosquitto.h>

using namespace std;

int main()
{
	cout << "Hello CMake1." << endl;
	const char* id = new char(1);
	void* obj = nullptr;
	//mosqpp::mosquittopp();
	mosquitto_lib_init();
	auto mosq = mosquitto_new(NULL, true, obj);
	std::string hostS = "localhost";
	char* host = const_cast<char*>(hostS.c_str());
	auto connRes = mosquitto_connect(mosq, host, 1883, 0);
	
	int* mid = new int;
	const char* topic = "testTopicANC\0";
	int payloadlen = 7;
	const void* payload = "testMsg";
	int qos = 0;
	bool retain = true;
	auto res = mosquitto_publish(mosq, mid, topic, payloadlen, payload, qos, retain);
	cout << "Hello moscuitto" << endl;
	mosquitto_destroy(mosq);

	return 0;
}
