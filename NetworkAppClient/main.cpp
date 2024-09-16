#include <iostream>
#include "src/client.h"
#include "src/parser.h"
//#include <signal.h>

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		std::cout << "usage:	NetworkAppClient	<sendtopic>/in/	<receievetopic>/out/" << std::endl;

		return 0;
	}

	// Парсинг командной строки (неограниченная длина, только ASCII)
	// Пример: 
	//	17 water, 26.33 shugar, 13,76 milk and 1 egg
	try
	{
		auto client = Client();
		client.setReceieveTopic(argv[1]);
		client.setSendTopic(argv[2]);
		//client.setReceieveTopic("test/out/");
		//client.setSendTopic("test/in/");
		client.run();
	}
	catch (...)
	{
		std::cout << "Error occured. Closing" << std::endl;

		return 0;
	}

	// Получение ответа от сервера

	// Отображение результата
	// Пример:
	//	1 13.76 17 26.33
	//	58.09

	return 0;
}
