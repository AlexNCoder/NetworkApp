#include "src/networkapppseudoserver.h"
#include <iostream>
#include "src/receiver.h"
#include <mosquittoconnect.h>

int main()
{
	try
	{
		// ����� ���������
		//auto mosqInstance = MosquittoConnect();
		//mosqInstance.sub();
		Server().run();
		// ��������� ������ �����

		// ���������� ����� �� �����������

		// ���������� �����

		// ������������ �������� ������

		// �������� ��������� �� ������� �������
		//mosquitto_destroy(mosq);

		Receiver().print();
	}
	catch (const std::exception&)
	{
		std::cout << "�����" << std::endl;
	}

	return 0;
}
