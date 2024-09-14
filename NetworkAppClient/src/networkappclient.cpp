#include "networkappclient.h"
#include <iostream>
#include <mosquitto.h>

void Client::message_callback(mosquitto* mosq, void* userdata, const mosquitto_message* message)
{
	std::cout << (char*)message->payload << std::endl;
}

void Client::run()
{
}
