#include "mosquittoconnect.h"

#include <iostream>


MosquittoConnect::MosquittoConnect(std::string hostS, int port, int qos)
	:m_qos(qos)
{
	initConnection(hostS, port, qos);
}

MosquittoConnect::~MosquittoConnect()
{
	// �������� ��������
	mosquitto_disconnect(m_mosq);
	mosquitto_lib_cleanup();
}

void MosquittoConnect::initConnection(std::string hostS, int port, int qos)
{
	void* obj = nullptr;
	mosquitto_lib_init();
	m_mosq = mosquitto_new(NULL, true, obj);
	char* host = const_cast<char*>(hostS.c_str());
	auto connRes = mosquitto_connect(m_mosq, host, 1883, 0);
}

void MosquittoConnect::connect_callback(struct mosquitto* mosq, void* obj, int result)
{
	std::cout << "connected" << std::endl;
	auto res = mosquitto_subscribe(mosq, NULL, "testTopicANC\0", 0);
	std::cout << "subs_result:	" << res << std::endl;
}

void MosquittoConnect::message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message)
{
	std::cout << "From MosquittoConnect:\n" 
		<< "topic:	" << message->topic << "\n"
		<< "message:	" << (char*)message->payload << std::endl;
}

void MosquittoConnect::pub(struct mosquitto* mosq, std::string message, std::string topic, int qos)
{
	// ���������� ���������
	int* mid = new int;
	const char* topicS = topic.c_str();
	int payloadlen = message.length();
	const void* payload = message.c_str();
	bool retain = true;

	// �������� ���������
	auto res = mosquitto_publish(mosq, mid, topicS, payloadlen, payload, qos, retain);
}

void MosquittoConnect::sub(
	void (*message_callback)(mosquitto* mosq, void* userdata,
		const mosquitto_message* message),
	std::string topic)
{
	mosquitto_connect_callback_set(m_mosq, connect_callback);
	mosquitto_message_callback_set(m_mosq, message_callback);
	auto res = mosquitto_subscribe(m_mosq, NULL, topic.c_str(), 0);
}