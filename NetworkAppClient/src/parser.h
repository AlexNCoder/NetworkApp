#pragma once
#include <string>

/*!
* \brief Функции для парсинга и проверки сообщений
*/
class Parser
{
public:
	/*!
	* \brief Функция для парсинга и проверки сообщений
	* \param s Входная строка
	* \return Результат проверки
	*/
	static bool isAllASCII(std::string s);
};