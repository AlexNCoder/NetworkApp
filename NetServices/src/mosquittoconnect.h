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
	/*!
	* \brief Конструктор
	* \param hostS IP адрес хоста
	* \param port Сетевой порт
	* \param qos QoS
	*/
	MosquittoConnect(std::string hostS = "localhost", int port = 1883, int qos = 0);

	/*!
	* \brief Деструктор
	*/
	~MosquittoConnect();

	/*!
	* \brief Публикует сообщение
	* \param mosq Mosquitto-instance соединения
	* \param message Передаваемое собщение
	* \param topic Тема сообщения
	* \return Статус
	*/
	static int pub(struct mosquitto* mosq, std::string message, std::string topic = "testTopicANC", int qos = 0);

	/*!
	* \brief Подписывается на публикацию сообщения по теме
	* \param message_callback Пользовательская функция для обработки входящих сообщений
	* \param topic Тема сообщения
	* \return Статус
	*/
	int sub(void (*message_callback)(mosquitto* mosq, void* userdata, const mosquitto_message* message) = message_callback, std::string topic = "testTopicANC");
	
	/*!
	* \brief Прекращает подписку на сообщения
	* \param topic Тема сообщения
	* \return Статус
	*/
	int unSub(std::string topic = "testTopicANC");

	/*!
	* \brief Установить тему для исходящих сообщений
	* \param topic Тема сообщения
	*/
	virtual void setSendTopic(std::string sendTopic);
	
	/*!
	* \brief Установить тему для входящих сообщений
	* \param topic Тема сообщения
	*/
	virtual void setReceieveTopic(std::string receieveTopic);
	
	/*!
	* \brief Основной цикл работы mosquitto-клиента
	*/
	virtual void run() = 0;

protected:
	/*!
	* \brief Пользовательская функция обработки входящих сообщений
	* \param mosq Mosquitto-instance соединения
	* \param userdata Пользовательские данные
	* \param message Входящее сообщение
	*/
	static void message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message);
	
	/*!
	* \brief Инициализация соединения с mosquitto сервером
	* \param hostS IP адрес хоста
	* \param port Сетевой порт
	* \param qos QoS
	*/
	void initConnection(std::string hostS, int port, int qos);

protected:

	/// Mosquitto-instance соединения
	struct mosquitto* m_mosq = nullptr;
	
	/// QoS
	int m_qos = 0;
	int* m_mid = NULL;

	std::string m_sendTopic = "/testTopicANC/in/";
	std::string m_receieveTopic = "/testTopicANC/out/";
};