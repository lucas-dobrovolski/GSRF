#include "GSRF.hpp"

int main(int argc, char** argv)
{
    GSRF instance(argc, argv);
    instance.defaultRun();
    std::cout << "end\n"; 
    return 0;
}
