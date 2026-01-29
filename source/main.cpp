#include "GSRF.hpp"

int main(int argc, char** argv)
{
    GSRF core(argc, argv);
    bool state = core.rute1();
    std::cout << state; 

    return 0;
}
