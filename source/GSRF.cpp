#include "GSRF.hpp"

#include <chrono>
using sclock = std::chrono::steady_clock;

GSRF::GSRF(int argc, char** argv)
    : argc(argc), argv(argv) 
{}

int GSRF::run(){
    if (!init()) return -1;
    running = true;
    loop();
    shutdown();
    return 0;
}

bool GSRF::init(){
    if (!glfwInit()){
        std::cerr << "GLFW init failed\n";
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(
        800, 600,
        "GSRF",
        nullptr,
        nullptr
    );

    if (!window)
    {
        std::cerr << "Window creation failed\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "GLAD init failed\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_PROGRAM_POINT_SIZE); /*GL_LEQUAL (útil con depth pre-pass)
                                        GL_GREATER (para reversed-Z)
                                        GL_ALWAYS (sin ocultamiento)*/

    glfwSwapInterval(0); // 0 = sin vsync,
    return true;
}

void GSRF::loop()
{
    auto last_time = sclock::now();

    while (running)
    {
        glfwPollEvents();
        
        if (glfwWindowShouldClose(window)) {running = false; break;}

        auto now = sclock::now();
        std::chrono::duration<double> delta = now - last_time;
        last_time = now;

        update(delta.count());
        render();
    }
}

void GSRF::update(double dt){
    (void)dt;
}

void GSRF::render(){
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(window);
}

void GSRF::shutdown()
{
    if (window){
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}
