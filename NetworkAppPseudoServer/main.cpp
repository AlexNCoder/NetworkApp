#include "src/networkapppseudoserver.h"
#include <iostream>
#include "src/receiver.h"
#include <mosquittoconnect.h>

int main()
{
	// Прием сообщения
	auto mosqInstance = MosquittoConnect();
	mosqInstance.sub();
	// Выделение только чисел

	// Сортировка чисел по возрастанию

	// Вычисление суммы

	// Формирование итоговой строки

	// Отправка сообщения со строкой клиенту
	//mosquitto_destroy(mosq);

	Receiver().print();
	

	return 0;
}
