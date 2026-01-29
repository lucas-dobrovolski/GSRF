#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>

using sclock = std::chrono::steady_clock;

#include "cosmos.hpp"

struct GSRF
{
    GSRF(int argc, char** argv);
    ~GSRF() = default;
    // ==================
    int argc;
    char** argv;
    // ==================
    GLFWwindow* window = nullptr;
    Cosmos cosmos;
    bool onLoop = false;
    sclock::time_point time0;
    sclock::time_point last_time;   
    // ==================
    bool rute1();

    bool set();
        bool setWindow();
        bool setGlConfig();
        bool setCosmos();
    bool go();
        bool pollInput();
        bool cosmosTick();
        bool draw();
    bool close();

    //void update(double dt);
    //void render();
    

};