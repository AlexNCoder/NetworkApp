#pragma once
#include <string>
#include <vector>

/*!
* \brief Функции для парсинга сообщений
*/
class ServerParser
{
public:
	static std::string makeOutTopic(std::string currentTopic);
	/*!
	* \brief Извлекает из строки все числа
	* \param message Входная строка
	* \return Вектор, содержащий извлеченные числа
	*/
	static std::vector<std::string> parseMessage(std::string message);
};