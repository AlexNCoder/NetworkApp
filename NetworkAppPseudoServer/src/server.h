#pragma once
#include <mosquittoconnect.h>
#include <string>
#include <vector>

/*!
* \brief Класс сервера для расчета суммы чисел
*/
class Server : public MosquittoConnect
{
public:
	/*!
	* \brief Конструктор
	* \param hostS IP адрес хоста
	* \param port Сетевой порт
	* \param qos QoS
	*/
	Server(std::string hostS = "localhost", int port = 1883, int qos = 0);
	static void server_message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message);
	static std::string sumStr(std::vector<std::string>& nums);
	void run() override;

	virtual void setSendTopic(std::string sendTopic) override;

	static std::string serverSendTopic;
};
