#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>

using sclock = std::chrono::steady_clock;

struct GSRF
{
    GSRF(int argc, char** argv);
    ~GSRF() = default;
    // ==================
    int argc;
    char** argv;
    // ==================   vars
    GLFWwindow* window = nullptr;
    bool onLoop = false;
    sclock::time_point time0;
    sclock::time_point last_time;   
    sclock::time_point now;   
    double local_time;
    double dt;
    // ==================   defaultRun
    void defaultRun();
    void setWindow();
    void setGlConfig();
    void pollInput();
    void draw();
    void close();
    //program.cpp
    void atStart();
    void evyTime();
};