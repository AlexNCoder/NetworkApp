#include "server.h"
#include <iostream>
#include "mosquittoconnect.h"
#include "serverparser.h"
#include <algorithm>
#include <sstream>
#include <ios>

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
    std::stringstream ss;

	for (auto e : numsF)
	{
        ss << e << " ";
	}
    ss.seekp(-1, std::ios_base::end);
	
    ss << "\n" << sum;
    res = ss.str();
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
