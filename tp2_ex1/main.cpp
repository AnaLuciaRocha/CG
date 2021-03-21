#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// settings
const unsigned int SCR_WIDTH = 400;
const unsigned int SCR_HEIGHT = 400;
const float MAX_TIME_WINDOW = 30.0;

//============================================

// declare and define vshader, position 4 in vector declaration
// is for "w" = perspective division
const char *vertexShaderSource = "#version 330 core\n"
                                 "layout (location = 0) in vec3 aPos;\n"
                                 "void main()\n"
                                 "{\n"
                                 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                 "}\0";
// declare and define fshader, position in color vector declaration
// are RGBA from [0,1] and where A = alpha (opacity)
const char *fragmentShaderSource = "#version 330 core\n"
                                   "out vec4 FragColor;\n"
                                   "void main()\n"
                                   "{\n"
                                   "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                   "}\n\0";

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

// void renderLoop(GLFWwindow *window, unsigned int)
// {
//   while (!glfwWindowShouldClose(window))
//   {

//     // render
//     // ------
//     //glClearColor(0.5f, 0.5f, 0.5f, 1.0f); //grey rendering
//     glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //green? rendering
//     glClear(GL_COLOR_BUFFER_BIT);

//     // draw our first triangle: using shader program
//     glUseProgram(shaderProgram);
//     glBindVertexArray(VAO);
//     // seeing as we only have a single VAO there's no need to bind
//     // it every time, but we'll do so to keep things a bit more organized
//     glDrawArrays(GL_TRIANGLES, 0, 3);
//     // glBindVertexArray(0); // no need to unbind it every time

//     // optional: de-allocate all resources once they've outlived their purpose:
//     // ------------------------------------------------------------------------
//     glDeleteVertexArrays(1, &VAO);
//     glDeleteBuffers(1, &VBO);
//     glDeleteProgram(shaderProgram);
//   }
// }

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

  //shader();
  //===========================================
  // build and compile our shader program
  // ------------------------------------
  // vertex shader
  unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);
  // check for vertex shader compile errors
  int success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }
  // fragment shader
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  // check for fragment shader compile errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"
              << infoLog << std::endl;
  }

  // link shaders : puts together the vertex and the fragment shaders
  // into a "shader program object"
  unsigned int shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  // check for shader linking errors
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success)
  {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
              << infoLog << std::endl;
  }
  // delete shaders, we don't need them anymore
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  //=================================================
  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------

  //  vertices(); for a square (basically there are 2 triangles)
  float vertices[] = {
-0.705333, -0.7175, 0,
 -0.488333, -0.68325, 0,
 -0.678333, -0.746, 0,
 -0.705333, -0.661, 0,
 -0.705333, -0.7175, 0,
 -0.488333, -0.68325, 0,
 -0.703333, -0.6595, 0,
 -0.488333, -0.68325, 0,
 -0.488667, -0.65375, 0,
 -0.703333, -0.5, 0,
 -0.703333, -0.5075, 0,
 -0.486667, -0.655, 0,
 -0.49, -0.6475, 0,
 -0.7, -0.5025, 0,
 -0.493333, -0.54, 0,
 -0.496667, -0.5375, 0,
 -0.7, -0.5025, 0,
 -0.496667, -0.4725, 0,
 -0.7, -0.5, 0,
 -0.7, -0.1875, 0,
 -0.5, -0.4725, 0,
 -0.7, -0.1875, 0,
 -0.5, -0.3975, 0,
 -0.5, -0.4725, 0,
 -0.7, -0.1875, 0,
 -0.503333, -0.39375, 0,
 -0.533333, -0.28, 0,
 -0.7, -0.1875, 0,
 -0.506667, -0.1, 0,
 -0.503333, -0.2775, 0,
 -0.696667, 0.06, 0,
 -0.51, -0.0925, 0,
 -0.51, 0.4, 0,
 -0.696667, 0.065, 0,
 -0.693333, 0.1925, 0,
 -0.51, 0.4, 0,
 -0.51, 0.4, 0,
 -0.69, 0.28, 0,
 -0.693333, 0.195, 0,
 -0.69, 0.28, 0,
 -0.69, 0.3475, 0,
 -0.51, 0.4, 0,
 -0.51, 0.4, 0,
 -0.686667, 0.3475, 0,
 -0.683333, 0.4025, 0,
 -0.51, 0.4, 0,
 -0.683333, 0.4025, 0,
 -0.68, 0.4, 0,
 -0.676667, 0.44, 0,
 -0.51, 0.4, 0,
 -0.506667, 0.4525, 0,
 -0.68, 0.44, 0,
 -0.676667, 0.465, 0,
 -0.506667, 0.4525, 0,
 -0.503333, 0.4975, 0,
 -0.506667, 0.4525, 0,
 -0.676667, 0.465, 0,
 -0.676667, 0.465, 0,
 -0.666667, 0.51, 0,
 -0.503333, 0.4975, 0,
 -0.666667, 0.51, 0,
 -0.659667, 0.56, 0,
 -0.503333, 0.4975, 0,
 -0.656667, 0.56, 0,
 -0.503333, 0.499, 0,
 -0.657, 0.61, 0,
 -0.503333, 0.5025, 0,
 -0.490333, 0.59025, 0,
 -0.646667, 0.6, 0,
 -0.48, 0.6325, 0,
 -0.63, 0.6525, 0,
 -0.47, 0.6675, 0,
 -0.626667, 0.6575, 0,
 -0.603333, 0.7075, 0,
 -0.47, 0.6675, 0,
 -0.6, 0.7075, 0,
 -0.583333, 0.7375, 0,
 -0.47, 0.67, 0,
 -0.47, 0.6725, 0,
 -0.443333, 0.7325, 0,
 -0.58, 0.7375, 0,
 -0.58, 0.7375, 0,
 -0.443333, 0.7325, 0,
 -0.41, 0.785, 0,
 -0.58, 0.74, 0,
 -0.406667, 0.785, 0,
 -0.546667, 0.7825, 0,
 -0.406667, 0.785, 0,
 -0.543333, 0.7825, 0,
 -0.406667, 0.785, 0,
 -0.54, 0.785, 0,
 -0.5, 0.8275, 0,
 -0.386667, 0.8075, 0,
 -0.383333, 0.8075, 0,
 -0.496667, 0.8275, 0,
 -0.446667, 0.8675, 0,
 -0.383333, 0.81, 0,
 -0.35, 0.835, 0,
 -0.446667, 0.8675, 0,
 -0.443333, 0.8675, 0,
 -0.346667, 0.835, 0,
 -0.32, 0.8525, 0,
 -0.443333, 0.8675, 0,
 -0.363333, 0.9125, 0,
 -0.313333, 0.8525, 0,
 -0.36, 0.9125, 0,
 -0.246667, 0.95, 0,
 -0.313333, 0.8525, 0,
 -0.313333, 0.8525, 0,
 -0.213333, 0.8775, 0,
 -0.246667, 0.95, 0,
 -0.213333, 0.8775, 0,
 -0.18, 0.88, 0,
 -0.246667, 0.95, 0,
 -0.18, 0.88, 0,
 -0.246667, 0.95, 0,
 -0.126667, 0.88, 0,
 -0.126667, 0.88, 0,
 -0.133333, 0.9675, 0,
 -0.24, 0.95, 0,
 -0.126667, 0.8775, 0,
 -0.13, 0.9675, 0,
 -0.00666667, 0.9675, 0,
 -0.126667, 0.8775, 0,
 -0.00666667, 0.9675, 0,
 0.0833333, 0.9475, 0,
 -0.123333, 0.8775, 0,
 0.0866667, 0.9475, 0,
 0.15, 0.92, 0,
 0.15, 0.92, 0,
 0.23, 0.8575, 0,
 -0.123333, 0.8775, 0,
 0.163333, 0.91, 0,
 0.206667, 0.88, 0,
 0.226667, 0.86, 0,
 0.226667, 0.8575, 0,
 0.253333, 0.8275, 0,
 -0.1, 0.8725, 0,
 0.25, 0.8275, 0,
 0.27, 0.8, 0,
 -0.08, 0.8675, 0,
 -0.0566667, 0.86, 0,
 0, 0.8325, 0,
 0.266667, 0.7975, 0,
 0, 0.8325, 0,
 0.266667, 0.7975, 0,
 0.28, 0.77, 0,
 0.00666667, 0.8275, 0,
 0.0633333, 0.7675, 0,
 0.28, 0.77, 0,
 0.0633333, 0.7675, 0,
 0.28, 0.77, 0,
 0.286667, 0.7425, 0,
 0.0633333, 0.7675, 0,
 0.286667, 0.7425, 0,
 0.286667, 0.6775, 0,
 0.286667, 0.6775, 0,
 0.0633333, 0.7675, 0,
 0.26, 0.6, 0,
 0.0633333, 0.7625, 0,
 0.26, 0.6, 0,
 0.203333, 0.5225, 0,
 0.08, 0.7325, 0,
 0.09, 0.64, 0,
 0.203333, 0.5225, 0,
 0.09, 0.64, 0,
 0.0733333, 0.5725, 0,
 0.203333, 0.5225, 0,
 -0.41, -0.3, 0,
 -0.283333, -0.165, 0,
 -0.353333, -0.3475, 0,
 -0.353333, -0.3475, 0,
 -0.283333, -0.1675, 0,
 -0.29, -0.375, 0,
 -0.29, -0.375, 0,
 -0.28, -0.1675, 0,
 -0.2, -0.39, 0,
 -0.276667, -0.17, 0,
 -0.253333, -0.18, 0,
 -0.253333, -0.2375, 0,
 -0.233333, -0.2525, 0,
 -0.253333, -0.2075, 0,
 -0.253333, -0.245, 0,
 -0.25, -0.25, 0,
 -0.23, -0.2525, 0,
 -0.24, -0.2775, 0,
 -0.23, -0.255, 0,
 -0.206667, -0.2775, 0,
 -0.233333, -0.2975, 0,


  };

  unsigned int VBO, VAO;      // declare variables
  glGenBuffers(1, &VBO);      // generate vertex buffer
  glGenVertexArrays(1, &VAO); // generate vertex array object
  /* bind the Vertex Array Object first, then bind and set vertex 
       buffer(s), and then configure vertex attributes(s)*/
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // copy our vertex data into buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  glEnableVertexAttribArray(0);

  /* note that this is allowed, the call to glVertexAttribPointer 
       registered VBO as the vertex attribute's bound vertex buffer 
       object so afterwards we can safely unbind*/
  glBindBuffer(GL_ARRAY_BUFFER, 0);

  /* You can unbind the VAO afterwards so other VAO calls won't 
       accidentally modify this VAO, but this rarely happens. Modifying 
       other VAOs requires a call to glBindVertexArray anyways so we 
       generally don't unbind VAOs (nor VBOs) when it's not directly 
       necessary.*/
  glBindVertexArray(0);

  // uncomment this call to draw in wireframe polygons.

  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  //shader();

  // render loop
  // -----------
  //renderLoop(window);
  while (!glfwWindowShouldClose(window))
  {
    //input
    //.....
    processInput(window);

    // render
    // ------
    //glClearColor(0.5f, 0.5f, 0.5f, 1.0f); //grey rendering
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //green? rendering
    glClear(GL_COLOR_BUFFER_BIT);

    // draw our first triangle: using shader program
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    // seeing as we only have a single VAO there's no need to bind
    // it every time, but we'll do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 189);

    // glBindVertexArray(0); // no need to unbind it every time

    /* glfw: swap buffers and poll IO events (keys pressed/released, 
	 mouse moved etc.)
	 --------------------------------------------------------------*/
    //cria janela e processa tudo o que nela se passa
    glfwSwapBuffers(window);
    //changeBackgoundColor(window);

    glfwPollEvents();
  }

  // optional: de-allocate all resources once they've outlived their purpose:
  // ------------------------------------------------------------------------
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteProgram(shaderProgram);

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}