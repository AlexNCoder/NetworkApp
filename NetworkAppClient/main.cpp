#include <iostream>
#include "src/NetworkAppClient.h"
#include "src/parser.h"

int main()
{
	// ������� ��������� ������ (�������������� �����, ������ ASCII)
	// ������: 
	//	17 water, 26.33 shugar, 13,76 milk and 1 egg
	Client().run();

	// ��������� ������ �� �������

	// ����������� ����������
	// ������:
	//	1 13.76 17 26.33
	//	58.09

	return 0;
}
