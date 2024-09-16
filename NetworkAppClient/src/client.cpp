#include "client.h"
#include <iostream>
#include <mosquitto.h>
#include <string>
#include "parser.h"
#include <time.h>

bool Client::subscribe = true;

Client::Client(std::string hostS, int port, int qos):MosquittoConnect(hostS, port, qos)
{
}

void Client::message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message)
{
	subscribe = false;
	auto msg = (char*)message->payload;

	if (msg)
	{
		std::cout << msg << std::endl;
	}
	else
	{
		std::cout << "Empty message received" << std::endl;
	}
}

void Client::run()
{
	//std::string s = "13.76 26.33 1 17";
	std::string s;
	time_t startTime;
	
	// Отправка сообщения
	while (1)
	{
		if (unSub(m_receieveTopic))
		{
			std::cout << "Error unsubscrining" << std::endl;

			return;
		}
		std::cout << "Input a string or \"exit\":" << std::endl;
		std::getline(std::cin, s);

		if (s.empty())
		{
			std::cout << "Empty string. Please repeate input" << std::endl;

			continue;
		}

		if (s == "exit")
		{
			return;
		}

		if (!Parser::isAllASCII(s))
		{
			std::cout << "Non ACSII characters are. Please repeate input" << std::endl;

			continue;
		}

        if (sub(message_callback, m_receieveTopic))
        {
            std::cout << "Error subscribing" << std::endl;

            return;
        }
		
		if (pub(m_mosq, s.c_str(), m_sendTopic))
		{
			std::cout << "Error publishing" << std::endl;

			return;
		}
		subscribe = true;		
		startTime = time(NULL);

		while (subscribe)
		{
			if (mosquitto_loop(m_mosq, -1, 1))
			{
				subscribe = false;
				if (unSub(m_receieveTopic))
				{
					std::cout << "Error unsubscrining, connection lost" << std::endl;

					return;
				}

				std::cout << "Connection lost" << std::endl;

				return;
			}

			if (difftime(time(NULL), startTime) > 2)
			{
				std::cout << "Server doesn't answer.Try again? (any input - Yes, for exit input \"No\")" << std::endl;
				std::getline(std::cin, s);

				if (s == "No")
				{
					return;
				}
				else
				{
					startTime = time(NULL);
				}
			}
		}
	}
}
