#include "GSRF.hpp"

GSRF::GSRF(int argc, char** argv)
    : argc(argc), argv(argv) 
{}
// ==================   ==================   ==================
bool GSRF::rute1(){

    if (!set()){
        std::cout << "GSRF::set error\n";
        return false;
    }
    
    if (!go()){
        std::cout << "GSRF::go error\n";
        return false;
    }
    if (!close()){
        std::cout << "GSRF::close error\n";
        return false;
    }
    return true;
}
// ==================   ==================   ==================
bool GSRF::set(){
    if (!setWindow()){
    std::cout << "GSRF::setWindow error\n";
    return false;}
    if (!setGlConfig()){
    std::cout << "GSRF::setGlConfig error\n";
    return false;}
    return true;
}
bool GSRF::setWindow(){

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
        return false;
    }
    glfwSwapInterval(0); // 0 = sin vsync,
    return true;
}
bool GSRF::setGlConfig(){
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_PROGRAM_POINT_SIZE); /*GL_LEQUAL (útil con depth pre-pass)
                                        GL_GREATER (para reversed-Z)
                                        GL_ALWAYS (sin ocultamiento)*/
    return true;
                                            
}
bool GSRF::setCosmos(){
    cosmos.cosmosStart();
    return true;
}
// ==================   ==================   ==================
bool GSRF::go() {
    onLoop = true;
    if (!setCosmos()){
    std::cout << "GSRF::setCosmos error\n";
    return false;}

    while (onLoop) {
        if (!pollInput()){
        std::cout << "GSRF::pollInput error\n";
        return false;}
        if (!cosmosTick()){
        std::cout << "GSRF::cosmosTick error\n";
        return false;}
        if (!draw()){
        std::cout << "GSRF::draw error\n";
        return false;}
    }
    return true;
}
bool GSRF::pollInput(){

    glfwPollEvents();
    if (glfwWindowShouldClose(window)) {
        onLoop = false;
        return true;
        }
    return true;
    }
bool GSRF::cosmosTick(){
    cosmos.cosmosUpd();
    return true;
}
bool GSRF::draw(){
    glClearColor(0.1f, 0.1f, 0.15f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(window);
    return true;
}
// ==================   ==================   ==================
bool GSRF::close()
{
    if (window){
        glfwDestroyWindow(window);
        window = nullptr;
    }
    glfwTerminate();
    return true;   
}
// ==================   ==================   ==================