#pragma once
#include <string>
#include <mosquitto.h>

/*!
* \brief �����-������� � mosquitto
* 
* \details �������� ��������, ������ ����� ������
��� ����������� ������ � ��������� ��������� �������� ��������
������ message_callback �����������. � ��������� ������ �����
����������� ���������� �� ��������� (������ ����� ��������� � �������)
*/
class MosquittoConnect
{
public:
	/*!
	* \brief �����������
	* \param hostS IP ����� �����
	* \param port ������� ����
	* \param qos QoS
	*/
	MosquittoConnect(std::string hostS = "localhost", int port = 1883, int qos = 0);

	/*!
	* \brief ����������
	*/
	~MosquittoConnect();

	/*!
	* \brief ��������� ���������
	* \param mosq Mosquitto-instance ����������
	* \param message ������������ ��������
	* \param topic ���� ���������
	* \return ������
	*/
	static int pub(struct mosquitto* mosq, std::string message, std::string topic = "testTopicANC", int qos = 0);

	/*!
	* \brief ������������� �� ���������� ��������� �� ����
	* \param message_callback ���������������� ������� ��� ��������� �������� ���������
	* \param topic ���� ���������
	* \return ������
	*/
	int sub(void (*message_callback)(mosquitto* mosq, void* userdata, const mosquitto_message* message) = message_callback, std::string topic = "testTopicANC");
	
	/*!
	* \brief ���������� �������� �� ���������
	* \param topic ���� ���������
	* \return ������
	*/
	int unSub(std::string topic = "testTopicANC");

	/*!
	* \brief ���������� ���� ��� ��������� ���������
	* \param topic ���� ���������
	*/
	virtual void setSendTopic(std::string sendTopic);
	
	/*!
	* \brief ���������� ���� ��� �������� ���������
	* \param topic ���� ���������
	*/
	virtual void setReceieveTopic(std::string receieveTopic);
	
	/*!
	* \brief �������� ���� ������ mosquitto-�������
	*/
	virtual void run() = 0;

protected:
	/*!
	* \brief ���������������� ������� ��������� �������� ���������
	* \param mosq Mosquitto-instance ����������
	* \param userdata ���������������� ������
	* \param message �������� ���������
	*/
	static void message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message);
	
	/*!
	* \brief ������������� ���������� � mosquitto ��������
	* \param hostS IP ����� �����
	* \param port ������� ����
	* \param qos QoS
	*/
	void initConnection(std::string hostS, int port, int qos);

protected:

	/// Mosquitto-instance ����������
	struct mosquitto* m_mosq = nullptr;
	
	/// QoS
	int m_qos = 0;
	int* m_mid = NULL;

	std::string m_sendTopic = "/testTopicANC/in/";
	std::string m_receieveTopic = "/testTopicANC/out/";
};