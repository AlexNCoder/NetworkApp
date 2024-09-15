#include "networkapppseudoserver.h"
#include <iostream>
#include "mosquittoconnect.h"
#include <cstring>
#include <regex>
#include <sstream>

class Parser
{
public:
	static std::string makeOutTopic(std::string currentTopic)
	{
		auto pos = currentTopic.rfind("/in/");
		if (pos == currentTopic.npos)
		{
			return "";
		}
		currentTopic.replace(pos, currentTopic.size() - 1, "/out/");

		return currentTopic;
		
		
			/*
			char* pch = strtok(str, "/");

		while (pch != NULL)
		{
			std::cout << pch << "n";
			pch = strtok(NULL, "/");
		}*/
	}

	static std::vector<std::string> parseMessage(std::string message)
	{
		std::regex ex(R"(((\d+)[,.](\d+))|(\d+))");
		
		message = std::regex_replace(message, std::regex("[^0-9,.]"), " ");
		message = std::regex_replace(message, std::regex(","), ".");

		std::vector<std::string> res;
		std::copy(
			std::sregex_token_iterator(message.begin(), message.end(), ex, 0),
			std::sregex_token_iterator(),
			std::back_inserter(res));

		return res;
	}
};

Server::Server(std::string hostS, int port, int qos) :MosquittoConnect(hostS, port, qos)
{
}

void Server::server_message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message)
{
	auto msgText = (char*)message->payload;
	
	//std::cout << "From Server:	" << msgText << std::endl;
	auto topic = Parser::makeOutTopic(message->topic);

	//std::string s = "17 water, 26.33 shugar, 13,76 milk and 1 egg";
	//std::string s = "8 jhkfd8 1,2 e6.3fa5o   75e1";
	auto nums = Parser::parseMessage(msgText);
	
	auto send = sumStr(nums);
	pub(mosq, send.c_str(), topic);
}

std::string Server::sumStr(std::vector<std::string>& nums)
{
	std::vector<double> numsF;
	auto sum = 0.0;

	for (auto e : nums)
	{
		auto f = atof(e.c_str());
		numsF.push_back(f);

		sum += f;
	}
	std::sort(numsF.begin(), numsF.end());

	std::string res;

	for (auto e : numsF)
	{
		res.append(std::to_string(e).c_str());
		res.append(" ");
	}
	res.erase(res.find_last_of(" "));
	
	res.append("\n");
	res.append(std::to_string(sum).c_str());
	std::cout << res << std::endl;
	//res.push_back(itoa(0,));

	return res;
}

void Server::run()
{
	sub(server_message_callback, "/testTopicANC/in/");
	
	while (1)
	{
		mosquitto_loop(m_mosq, 100, 1);
	}
}
