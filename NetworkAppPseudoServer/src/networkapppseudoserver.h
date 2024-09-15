#pragma once
#include <mosquittoconnect.h>
#include <string>
#include <vector>

class Server : public MosquittoConnect
{
public:
	Server(std::string hostS = "localhost", int port = 1883, int qos = 0);
	static void server_message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message);
	static std::string sumStr(std::vector<std::string>& nums);
	void run() override;

private:
	//MosquittoConnect m_mosquittoConnect;
};
