#include "GSRF.hpp"

GSRF::GSRF(int argc, char** argv)
    : argc(argc), argv(argv) 
{}
// ==================   defaultRun   
void GSRF::defaultRun(){

    setWindow();
    setGlConfig();
    time0 = last_time = now = sclock::now();
    local_time = 0.0;
    atStart();
    onLoop = true;
    while (onLoop) {
        now = sclock::now();
        dt = std::chrono::duration<double>(now - last_time).count();
        last_time = now;
        local_time += dt;
        pollInput();
        evyTime();
        draw();
    }
    close();
}
// ==================   defaultRun   setWindow
void GSRF::setWindow(){

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(
        800, 600,
        "GSRF",
        nullptr,
        nullptr
    );
    
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "GLAD init failed\n";
        glfwDestroyWindow(window);
        glfwTerminate();
    }
    glfwSwapInterval(0); // 0 = sin vsync
}
void GSRF::setGlConfig(){
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_PROGRAM_POINT_SIZE); /*GL_LEQUAL (útil con depth pre-pass)
                                        GL_GREATER (para reversed-Z)
                                        GL_ALWAYS (sin ocultamiento)*/
}

void GSRF::pollInput(){
    glfwPollEvents();
    if (glfwWindowShouldClose(window)) {
        onLoop = false;
    }
}
void GSRF::draw(){
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(window);
}
void GSRF::close()
{
    if (window){
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
}