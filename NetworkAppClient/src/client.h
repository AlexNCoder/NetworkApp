#pragma once
#include "mosquittoconnect.h"

/*!
* \brief Класс клиента
*/
class Client : public MosquittoConnect
{

public:
	/*!
	* \brief Конструктор
	* \param hostS IP адрес хоста
	* \param port Сетевой порт
	* \param qos QoS
	*/
	Client(std::string hostS = "localhost", int port = 1883, int qos = 0);
	static void message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message);

	void run() override;
	static bool subscribe;
};