#include "networkappclient.h"
#include <iostream>
#include <mosquitto.h>
#include <string>

void Client::message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message)
{
	std::cout << (char*)message->payload << std::endl;
}

void Client::run()
{
	//std::string s = "13.76 26.33 1 17";

	std::string s;

	// Отправка сообщения
	while (1)
	{
		std::getline(std::cin, s);
		pub(m_mosq, s.c_str(), "/testTopicANC/in/");
	}
}
