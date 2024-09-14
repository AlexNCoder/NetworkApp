#pragma once
#include <mosquittoconnect.h>

class Server : public MosquittoConnect
{
public:
	static void server_message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message);
	void run() override;

private:
	//MosquittoConnect m_mosquittoConnect;
};
