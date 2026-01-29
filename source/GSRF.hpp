#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class GSRF
{
public:
    GSRF(int argc, char** argv);
    ~GSRF() = default;

    GSRF(const GSRF&) = delete; // evita copias
    GSRF& operator=(const GSRF&) = delete;

    int run();

private:
    bool running = false;

    bool init();

    void loop();
    void update(double dt);
    void render();
    
    void shutdown(); 

    GLFWwindow* window = nullptr;
    
    int argc;
    char** argv;
};