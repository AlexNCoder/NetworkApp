#include "sender.h"
#include <mosquitto.h>
#include <iostream>

void Sender::send(std::string message)
{
	std::cout << "from Sender" << std::endl;

	const char* id = new char(1);
	void* obj = nullptr;
	
	// Инициализация mosquitto
	mosquitto_lib_init();
	auto mosq = mosquitto_new(NULL, true, obj);
	std::string hostS = "localhost";
	char* host = const_cast<char*>(hostS.c_str());
	auto connRes = mosquitto_connect(mosq, host, 1883, 0);

	// Подготовка сообщения
	int* mid = new int;
	const char* topic = "testTopicANC\0";
	int payloadlen = message.length();
	const void* payload = message.c_str();
	int qos = 0;
	bool retain = true;

	// Отправка сообщения
	auto res = mosquitto_publish(mosq, mid, topic, payloadlen, payload, qos, retain);
	
	// Удаление инстанса
	mosquitto_disconnect(mosq);
	mosquitto_lib_cleanup();
	//mosquitto_destroy(mosq);
}
