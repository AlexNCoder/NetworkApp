#include "networkapppseudoserver.h"
#include <iostream>
#include "mosquittoconnect.h"
#include <cstring>

void Server::message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message)
{
	std::cout << "From Server:	" << (char*)message->payload << std::endl;
	auto len = message->payloadlen + 5;
	char* topic = new char(len);
	
	const char* tag = "/out/";
	
	strcpy(topic, message->topic);
	strcat(topic, tag);
	std::cout << topic << std::endl;
	pub(mosq, "newanswer", topic);
	//pub(mosq, "answer", "testTopicANC/out/");
	/// ...обработка
	//m_mosquittoConnect.pub("from server", "testTopicANC\0");// mosquitto_publish(mosq, NULL, mosq->topic, payloadlen, payload, m_qos, retain);
}

void Server::run()
{
	sub(message_callback);
	//sub();
	while (1)
	{
		mosquitto_loop(m_mosq, 100, 1);
	}
}
