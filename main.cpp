#include <iostream>
#include "tools/Protocol.h"

int main() {

    Protocol* byName = new ProtocolByCity{ "London"};
    std::cout << byName->computeUrl() << std::endl;
    byName->getData();

    return 0;
}