#pragma once
#include <string>

class MosquittoConnect
{
public:
	MosquittoConnect(std::string hostS = "localhost", int port = 1883, int qos = 0);
	~MosquittoConnect();

	void pub(std::string message, std::string topic = "testTopicANC\0");
	void sub(std::string topic = "testTopicANC\0");
	static void message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message);

private:
	void initConnection(std::string hostS, int port, int qos);

	struct mosquitto* m_mosq = nullptr;
	int m_qos = 0;
	int* m_mid = NULL;
};