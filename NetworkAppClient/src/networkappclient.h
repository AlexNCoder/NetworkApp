#pragma once
#include "mosquittoconnect.h"

class Client : public MosquittoConnect
{
public:
	
	void message_callback(struct mosquitto* mosq, void* userdata, const struct mosquitto_message* message);

	void run() override;
	
private:
	//MosquittoConnect m_mosquittoConnect;
};