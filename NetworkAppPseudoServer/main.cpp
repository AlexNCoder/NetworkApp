#include "src/networkapppseudoserver.h"
#include <iostream>
#include "src/receiver.h"
#include <mosquittoconnect.h>

int main()
{
	try
	{
		// Прием сообщения
		//auto mosqInstance = MosquittoConnect();
		//mosqInstance.sub();
		Server().run();
		// Выделение только чисел

		// Сортировка чисел по возрастанию

		// Вычисление суммы

		// Формирование итоговой строки

		// Отправка сообщения со строкой клиенту
		//mosquitto_destroy(mosq);

		Receiver().print();
	}
	catch (const std::exception&)
	{
		std::cout << "Выход" << std::endl;
	}

	return 0;
}
