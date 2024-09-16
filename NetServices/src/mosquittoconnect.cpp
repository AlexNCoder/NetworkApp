#include "mosquittoconnect.h"

#include <iostream>


MosquittoConnect::MosquittoConnect(std::string hostS, int port, int qos)
	:m_qos(qos)
{
	initConnection(hostS, port, qos);
}

MosquittoConnect::~MosquittoConnect()
{
	// Удаление инстанса
	mosquitto_disconnect(m_mosq);
	mosquitto_lib_cleanup();
}

void MosquittoConnect::initConnection(std::string hostS, int port, int qos)
{
	void* obj = nullptr;
	if (mosquitto_lib_init())
	{
		return;
	}
	m_mosq = mosquitto_new(NULL, true, obj);
	char* host = const_cast<char*>(hostS.c_str());
	
	if (!m_mosq || mosquitto_connect(m_mosq, host, port, 0))
	{
		return;
	}
}

void MosquittoConnect::message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message)
{
	std::cout << "From MosquittoConnect:\n" 
		<< "topic:	" << message->topic << "\n"
		<< "message:	" << (char*)message->payload << std::endl;
}

int MosquittoConnect::pub(struct mosquitto* mosq, std::string message, std::string topic, int qos)
{
	// Подготовка сообщения
	int* mid = new int;
	const char* topicS = topic.c_str();
	int payloadlen = message.length();
	const void* payload = message.c_str();
	bool retain = false;

	// Отправка сообщения
	return mosquitto_publish(mosq, mid, topicS, payloadlen, payload, qos, retain);
}

int MosquittoConnect::sub(
	void (*message_callback)(mosquitto* mosq, void* userdata,
		const mosquitto_message* message),
	std::string topic)
{
	//mosquitto_connect_callback_set(m_mosq, connect_callback);
	mosquitto_message_callback_set(m_mosq, message_callback);
	
	return mosquitto_subscribe(m_mosq, NULL, topic.c_str(), 0);
}
int MosquittoConnect::unSub(std::string topic)
{
	return mosquitto_unsubscribe(m_mosq, NULL, topic.c_str());
}

void MosquittoConnect::setSendTopic(std::string sendTopic)
{
	m_sendTopic = sendTopic;
}

void MosquittoConnect::setReceieveTopic(std::string receieveTopic)
{
	m_receieveTopic = receieveTopic;
}