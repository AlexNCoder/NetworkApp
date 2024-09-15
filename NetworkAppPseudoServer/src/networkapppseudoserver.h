#pragma once
#include <mosquittoconnect.h>
#include <string>
#include <vector>

class Server : public MosquittoConnect
{
public:
	static void server_message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message);
	static std::string sumStr(std::vector<std::string>& nums);
	void run() override;

private:
	//MosquittoConnect m_mosquittoConnect;
};
