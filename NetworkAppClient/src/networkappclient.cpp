#include "networkappclient.h"
#include <iostream>
#include <mosquitto.h>
#include <string>

bool Client::subscribe = true;

Client::Client(std::string hostS, int port, int qos):MosquittoConnect(hostS, port, qos)
{
}

void Client::message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message)
{
	subscribe = false;
	auto o = (char*)message->payload;
	std::cout << o << std::endl;
}

void Client::run()
{
	//std::string s = "13.76 26.33 1 17";

	std::string s;

	// Отправка сообщения
	while (1)
	{
		std::string receieveTopic = "/testTopicANC/out/";
		unSub(receieveTopic);

		std::getline(std::cin, s);
		pub(m_mosq, s.c_str(), "/testTopicANC/in/");
		//s.clear();
		sub(message_callback, receieveTopic);
		subscribe = true;

		while (subscribe)
		{
			mosquitto_loop(m_mosq, 100, 1);
		}
	}
}
