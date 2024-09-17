#include <iostream>
#include "src/client.h"
#include "src/parser.h"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "usage:	NetworkAppClient	<sendtopic>/in/	<receievetopic>/out/" << std::endl;

        return 0;
    }

    try
    {
        auto client = Client();
        client.setReceieveTopic(argv[1]);
        client.setSendTopic(argv[2]);
        client.run();
    }
    catch (...)
    {
        std::cout << "Error occured. Closing" << std::endl;

        return 0;
    }

    return 0;
}
