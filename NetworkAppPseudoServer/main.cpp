#include "src/networkapppseudoserver.h"
#include <iostream>
#include "src/receiver.h"
#include <mosquittoconnect.h>

int main()
{
	// ����� ���������
	auto mosqInstance = MosquittoConnect();
	mosqInstance.sub();
	// ��������� ������ �����

	// ���������� ����� �� �����������

	// ���������� �����

	// ������������ �������� ������

	// �������� ��������� �� ������� �������
	//mosquitto_destroy(mosq);

	Receiver().print();
	

	return 0;
}
