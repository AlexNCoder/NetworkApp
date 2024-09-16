#pragma once
#include "mosquittoconnect.h"

class Client : public MosquittoConnect
{

public:
	Client(std::string hostS = "localhost", int port = 1883, int qos = 0);
	static void message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message);

	void run() override;
	static bool subscribe;

private:
	std::string m_sendTopic = "/testTopicANC/in/"; 
	std::string m_receieveTopic = "/testTopicANC/out/";
};