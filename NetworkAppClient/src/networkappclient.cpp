#include "networkappclient.h"
#include <iostream>
#include <mosquitto.h>
#include <string>
#include "parser.h"

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
	std::string receieveTopic = "/testTopicANC/out/";

	// Отправка сообщения
	while (1)
	{
		unSub(receieveTopic);
		std::cout << "Input a string or \"exit\":" << std::endl;
		std::getline(std::cin, s);

		if (s == "exit")
		{
			return;
		}

		if (!Parser::isAllASCII(s))
		{
			std::cout << "Non ACSII characters are. Please repeate input" << std::endl;

			continue;
		}

		pub(m_mosq, s.c_str(), "/testTopicANC/in/");
		
		sub(message_callback, receieveTopic);
		subscribe = true;
		
		while (subscribe)
		{
			if (mosquitto_loop(m_mosq, -1, 1))
			{
				subscribe = false;
				unSub(receieveTopic);
				std::cout << "Connection lost" << std::endl;

				return;
			}
		}
	}
}
