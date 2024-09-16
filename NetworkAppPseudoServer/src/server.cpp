#include "server.h"
#include <iostream>
#include "mosquittoconnect.h"
#include "serverparser.h"
#include <algorithm>

std::string Server::serverSendTopic = "/testTopicANC/out/";

Server::Server(std::string hostS, int port, int qos) :MosquittoConnect(hostS, port, qos)
{
	/// Значения по умолчанию
	m_sendTopic = "/testTopicANC/out/";
	m_receieveTopic = "/testTopicANC/in/";
}

void Server::server_message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message)
{
	auto msgText = (char*)message->payload;
	if (!msgText)
	{
		std::cout << "An empty message receieved" << std::endl;

		return;
	}
	
	//std::cout << "From Server:	" << msgText << std::endl;
	//auto topic = ServerParser::makeOutTopic(message->topic);

	//std::string s = "17 water, 26.33 shugar, 13,76 milk and 1 egg";
	//std::string s = "8 jhkfd8 1,2 e6.3fa5o   75e1";
	auto nums = ServerParser::parseMessage(msgText);
	
	if (!nums.size())
	{
		std::cout << "Error parsing input message" << std::endl;

		return;
	}

	auto send = sumStr(nums);
	if (serverSendTopic.empty())
	{
		std::cout << "Empty out topic" << std::endl;

		return;
	}

	if (pub(mosq, send.c_str(), serverSendTopic))
	{
		std::cout << "Error publish" << std::endl;
	}
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

	return res;
}

void Server::run()
{
	if (m_receieveTopic.empty() || sub(server_message_callback, m_receieveTopic))
	{
		std::cout << "Error subscribe" << std::endl;

		return;
	}
	
	while (1)
	{
		if (mosquitto_loop(m_mosq, 100, 1))
		{
			std::cout << "Error. Closing" << std::endl;

			return;
		}
	}
}

void Server::setSendTopic(std::string sendTopic)
{
	MosquittoConnect::setSendTopic(sendTopic);
	serverSendTopic = sendTopic;
}
