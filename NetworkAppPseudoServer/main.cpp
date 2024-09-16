#include "src/server.h"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		std::cout << "usage:	NetworkAppServer	<sendtopic>/out/	<receievetopic>/in/" << std::endl;

		return 0;
	}

	try
	{
		auto server = Server();
		server.setReceieveTopic(argv[1]);
		server.setSendTopic(argv[2]);
		server.run();
	}
	catch (...)
	{
		std::cout << "Error occured. Closing" << std::endl;
	}

	return 0;
}
