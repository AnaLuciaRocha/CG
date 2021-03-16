//1. make
//2. ./tp1.ex1/tp1.ex1

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// settings
const unsigned int SCR_WIDTH = 400;
const unsigned int SCR_HEIGHT = 400;
const float MAX_TIME_WINDOW = 30.0;


//Change backgroung color when keys R,G and B are pressed
void changeBackgoundColor(GLFWwindow *window)
{
  
  if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
  {
    glClearColor(1, 0, 0, 0); // Red
  }
  else if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
  {
    glClearColor(0, 1, 0, 0); // Green
  }
  else if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
  {
    glClearColor(0, 0, 1, 0); // Blue
  }
  glClear(GL_COLOR_BUFFER_BIT);

}

/* process all input: query GLFW whether relevant keys are pressed/released 
this frame and react accordingly 
-----------------------------------------------------------------------*/
// Funcao que deteta o Enter
void processInput(GLFWwindow *window)
{
  if (glfwGetKey(window, GLFW_KEY_ENTER) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

/* glfw: whenever the window size changed (by OS or user resize) this
   callback function executes
   -------------------------------------------------------------------*/
// Funcao que cria a janela e deteta movimento, dimensoes,etc
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
  // make sure the viewport matches the new window dimensions; note that
  // width and height will be significantly larger than specified on
  // retina displays.
  glViewport(0, 0, width, height);
}



void renderLoop(GLFWwindow *window)
{
    while (!glfwWindowShouldClose(window))
  {
    
    // input
    // -----
    processInput(window);

    /* glfw: swap buffers and poll IO events (keys pressed/released, 
	 mouse moved etc.)
	 --------------------------------------------------------------*/
    //cria janela e processa tudo o que nela se passa
    glfwSwapBuffers(window);
    changeBackgoundColor(window);
    
    glfwPollEvents();
    
    //std::cout << (glfwGetTime());
    float time_ellapsed = glfwGetTime();
    if(time_ellapsed >= MAX_TIME_WINDOW){
      glfwSetWindowShouldClose(window, true);
    }
  }
}

int main()
{

  // glfw: initialize and configure
  // ------------------------------
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // glfw window creation
  // --------------------
   GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Janela Temporizada", NULL,
                                        NULL);

  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // glad: load all OpenGL function pointers
  // ---------------------------------------
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  //Background color
  glClearColor(49.0f / 255.0f, 51.0f / 255.0f, 53.0f / 255.0f, 0); //dark grey
  glClear(GL_COLOR_BUFFER_BIT);

  // render loop
  // -----------
  renderLoop(window);

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}
