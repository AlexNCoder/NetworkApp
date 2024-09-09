#include "src/networkapppseudoserver.h"
#include <mosquitto.h>
#include <iostream>
#include "src/receiver.h"

int main()
{
	std::cout << "Hello CMake1." << std::endl;
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
	std::string payloadS = "fromPseudoServer";
	int payloadlen = payloadS.length();
	const void* payload = payloadS.c_str();
	int qos = 0;
	bool retain = true;
	auto res = mosquitto_publish(mosq, mid, topic, payloadlen, payload, qos, retain);
	std::cout << "Hello moscuitto" << std::endl;
	mosquitto_destroy(mosq);

	Receiver().print();

	return 0;
}
