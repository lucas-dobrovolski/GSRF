#include "GSRF.hpp"

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <chrono>

using sclock = std::chrono::steady_clock;

void GSRF::atStart(){

    return;
}

void GSRF::evyTime(){
    std::cout << "dt: " << dt << " s" << std::endl;
    return;
}