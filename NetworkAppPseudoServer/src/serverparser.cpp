#include "serverparser.h"
#include <regex>

std::string ServerParser::makeOutTopic(std::string currentTopic)
{
	auto pos = currentTopic.rfind("/in/");
	if (pos == currentTopic.npos)
	{
		return "";
	}
	currentTopic.replace(pos, currentTopic.size() - 1, "/out/");

	return currentTopic;
}

std::vector<std::string> ServerParser::parseMessage(std::string message)
{
	std::regex ex(R"(((\d+)[,.](\d+))|(\d+))");

	message = std::regex_replace(message, std::regex("[^0-9,.]"), " ");
	message = std::regex_replace(message, std::regex(","), ".");

	std::vector<std::string> res;
	std::copy(
		std::sregex_token_iterator(message.begin(), message.end(), ex, 0),
		std::sregex_token_iterator(),
		std::back_inserter(res));

	return res;
}
