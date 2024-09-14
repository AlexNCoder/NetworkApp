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

	static void pub(struct mosquitto* mosq, std::string message, std::string topic = "testTopicANC\0", int qos = 0);
	void sub(void (*message_callback)(mosquitto* mosq, void* userdata, const mosquitto_message* message) = message_callback, std::string topic = "testTopicANC\0");

	virtual void run() = 0;

protected:
	static void connect_callback(struct mosquitto* mosq, void* obj, int result);
	static void message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message);
	void initConnection(std::string hostS, int port, int qos);

	struct mosquitto* m_mosq = nullptr;
	int m_qos = 0;
	int* m_mid = NULL;
};