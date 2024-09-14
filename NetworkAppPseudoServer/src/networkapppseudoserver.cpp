#include "networkapppseudoserver.h"
#include <iostream>
#include "mosquittoconnect.h"
#include <cstring>

class Parser
{
public:
	static std::string f(std::string str)
	{
		auto pos = str.rfind("/in/");
		if (pos == str.npos)
		{
			return "";
		}
		str.replace(pos, str.size() - 1, "/out/");

		return str;
		
		
			/*
			char* pch = strtok(str, "/");

		while (pch != NULL)
		{
			std::cout << pch << "n";
			pch = strtok(NULL, "/");
		}*/
	}
};

void Server::server_message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message)
{
	std::cout << "From Server:	" << (char*)message->payload << std::endl;
	auto topic = Parser::f(message->topic);
	std::cout << topic << std::endl;
	
	/// ...обработка
	auto serveranswer = "serveranswer";
	/// ...обработка
	
	pub(mosq, serveranswer, topic);
}

void Server::run()
{
	sub(server_message_callback, "/testTopicANC/in/");
	//sub();
	while (1)
	{
		mosquitto_loop(m_mosq, 100, 1);
	}
}
