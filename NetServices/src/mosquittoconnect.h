#pragma once
#include <string>
#include <mosquitto.h>

/*!
* \brief Класс-адаптер к mosquitto
* 
* \details Ключевым моментом, котрый нужно учесть
для обеспечения приема и обработки сообщений является передача
своего message_callback обработчика. В противном случае будет
использован обработчик по умолчанию (просто вывод сообщения в консоль)
*/
class MosquittoConnect
{
public:
	MosquittoConnect(std::string hostS = "localhost", int port = 1883, int qos = 0);
	~MosquittoConnect();

	static int pub(struct mosquitto* mosq, std::string message, std::string topic = "testTopicANC", int qos = 0);
	int sub(void (*message_callback)(mosquitto* mosq, void* userdata, const mosquitto_message* message) = message_callback, std::string topic = "testTopicANC");
	int unSub(std::string topic = "testTopicANC");

	virtual void setSendTopic(std::string sendTopic);
	virtual void setReceieveTopic(std::string receieveTopic);
	
	virtual void run() = 0;

protected:
	static void message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message);
	void initConnection(std::string hostS, int port, int qos);

protected:
	struct mosquitto* m_mosq = nullptr;
	int m_qos = 0;
	int* m_mid = NULL;

	std::string m_sendTopic = "/testTopicANC/in/";
	std::string m_receieveTopic = "/testTopicANC/out/";
};