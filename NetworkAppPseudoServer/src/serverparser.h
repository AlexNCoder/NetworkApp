#pragma once
#include <string>
#include <vector>

/*!
* \brief ������� ��� �������� ���������
*/
class ServerParser
{
public:
	static std::string makeOutTopic(std::string currentTopic);
	static std::vector<std::string> parseMessage(std::string message);
};