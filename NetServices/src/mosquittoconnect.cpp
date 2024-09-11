#include "mosquittoconnect.h"
#include <mosquitto.h>

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
	mosquitto_lib_init();
	m_mosq = mosquitto_new(NULL, true, obj);
	char* host = const_cast<char*>(hostS.c_str());
	auto connRes = mosquitto_connect(m_mosq, host, 1883, 0);

	mosquitto_message_callback_set(m_mosq, message_callback);
}

void MosquittoConnect::pub(std::string message, std::string topic)
{
	// Подготовка сообщения
	int* mid = new int;
	const char* topicS = topic.c_str();
	int payloadlen = message.length();
	const void* payload = message.c_str();
	bool retain = true;

	// Отправка сообщения
	auto res = mosquitto_publish(m_mosq, mid, topicS, payloadlen, payload, m_qos, retain);
}

void MosquittoConnect::sub(std::string topic)
{
	mosquitto_subscribe(m_mosq, m_mid, topic.c_str(), m_qos);
}

void message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message)
{

}