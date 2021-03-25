//1. make
//2. ./tp1.ex1/tp1.ex1

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

const int SIZE = 1000;
float vertices[SIZE];
unsigned int indices[SIZE];


// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//============================================


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

void readData()
{

  string coordinatesFile = "/home/ana/Documents/CG/tp2_ex4/Coordinates/coord.txt";
  string indicesFile = "/home/ana/Documents/CG/tp2_ex4/Coordinates/indices.txt";
  
  std::ifstream file(coordinatesFile);
  std::ifstream file2(indicesFile);

  if (file.is_open() && file2.is_open() )
  {
    for (int i = 0; i < SIZE; i++)
    {
      file >> vertices[i];
      file2 >> indices[i];
      //cout << indices[i] << " ";
    }

    file.close(); // CLose input file
    file2.close();
  }
  else
  { //Error message
    cerr << "Can't find input file " << coordinatesFile << endl;
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
  GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Letra 2D", NULL,
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

  //   float vertices[] = { 0.081520f,
  // 0.140103f,
  // 0.083558f,
  // 0.152839f,
  // 0.158454f,
  // 0.173935f,
  // 0.224179f,
  // 0.203786f,
  // 0.304425f,
  // 0.263489f,
  // 0.334231f,
  // 0.334336f,
  // 0.252966f,
  // 0.435831f,
  // 0.057064f,
  // 0.477623f,
  // -0.120242f,
  // 0.462631f,
  // -0.260863f,
  // 0.418186f,
  // -0.330155f,
  // 0.377853f,
  // -0.381105f,
  // 0.331152f,
  // -0.428998f,
  // 0.239342f,
  // -0.446321f,
  // 0.144348f,
  // -0.457784f,
  // -0.158677f,
  // -0.464663f,
  // -0.461703f,
  // -0.440207f,
  // -0.477623f,
  // -0.285319f,
  // -0.442598f,
  // -0.299840f,
  // -0.242925f,
  // -0.303661f,
  // -0.042455f,
  // -0.303406f,
  // 0.083451f,
  // -0.301623f,
  // 0.178313f,
  // -0.293216f,
  // 0.247568f,
  // -0.271053f,
  // 0.315231f,
  // -0.244050f,
  // 0.357952f,
  // -0.195647f,
  // 0.395897f,
  // -0.119223f,
  // 0.420176f,
  // -0.030570f,
  // 0.427738f,
  // 0.118204f,
  // 0.391120f,
  // 0.175267f,
  // 0.309925f,
  // 0.161001f,
  // 0.250354f,
  // 0.103938f,
  // 0.199540f,
  // -0.021144f,
  // 0.159075f,
  // -0.169153f,
  // 0.146471f,
  // -0.173229f,
  // 0.108261f,
  // -0.109033f,
  // 0.110119f,
  // -0.044836f,
  // 0.110384f,
  // 0.088653f,
  // 0.101893f,
  // 0.203799f,
  // 0.067929f,
  // 0.270544f,
  // 0.010083f,
  // 0.291433f,
  // -0.057315f,
  // 0.271053f,
  // -0.136123f,
  // 0.195647f,
  // -0.203786f,
  // 0.128903f,
  // -0.229923f,
  // 0.046874f,
  // -0.240934f,
  // -0.011718f,
  // -0.234301f,
  // -0.061140f,
  // -0.216523f,
  // -0.092729f,
  // -0.190784f,
  // -0.099862f,
  // -0.160269f,
  // -0.126356f,
  // -0.153901f,
  // -0.226217f,
  // -0.227136f,
  // -0.213480f,
  // -0.237618f,
  // -0.197685f,
  // -0.247303f,
  // -0.123044f,
  // -0.271582f,
  // -0.034646f,
  // -0.279144f,
  // 0.168134f,
  // -0.263224f,
  // 0.340345f,
  // -0.209093f,
  // 0.433074f,
  // -0.135327f,
  // 0.464663f,
  // -0.048824f,
  // 0.435621f,
  // 0.026933f,
  // 0.354611f,
  // 0.092341f,
  // 0.232586f,
  // 0.127764f
  // };

  //   unsigned int indices[] = { 8,
  // 6,
  // 7,
  // 9,
  // 27,
  // 8,
  // 27,
  // 6,
  // 8,
  // 27,
  // 28,
  // 6,
  // 28,
  // 5,
  // 6,
  // 9,
  // 26,
  // 27,
  // 9,
  // 25,
  // 26,
  // 10,
  // 25,
  // 9,
  // 10,
  // 24,
  // 25,
  // 29,
  // 5,
  // 28,
  // 11,
  // 24,
  // 10,
  // 11,
  // 23,
  // 24,
  // 29,
  // 4,
  // 5,
  // 12,
  // 23,
  // 11,
  // 12,
  // 22,
  // 23,
  // 30,
  // 4,
  // 29,
  // 30,
  // 3,
  // 4,
  // 31,
  // 3,
  // 30,
  // 12,
  // 21,
  // 22,
  // 13,
  // 21,
  // 12,
  // 31,
  // 2,
  // 3,
  // 32,
  // 2,
  // 31,
  // 13,
  // 20,
  // 21,
  // 32,
  // 1,
  // 2,
  // 33,
  // 1,
  // 32,
  // 33,
  // 0,
  // 1,
  // 34,
  // 0,
  // 33,
  // 14,
  // 20,
  // 13,
  // 61,
  // 0,
  // 36,
  // 0,
  // 34,
  // 35,
  // 60,
  // 61,
  // 37,
  // 38,
  // 60,
  // 37,
  // 38,
  // 59,
  // 60,
  // 14,
  // 19,
  // 20,
  // 39,
  // 59,
  // 38,
  // 39,
  // 58,
  // 59,
  // 40,
  // 58,
  // 39,
  // 14,
  // 18,
  // 19,
  // 40,
  // 57,
  // 58,
  // 41,
  // 57,
  // 40,
  // 41,
  // 56,
  // 57,
  // 42,
  // 56,
  // 41,
  // 50,
  // 48,
  // 49,
  // 15,
  // 18,
  // 14,
  // 50,
  // 47,
  // 48,
  // 50,
  // 46,
  // 47,
  // 43,
  // 56,
  // 42,
  // 43,
  // 55,
  // 56,
  // 50,
  // 45,
  // 46,
  // 51,
  // 52,
  // 45,
  // 44,
  // 55,
  // 43,
  // 50,
  // 51,
  // 45,
  // 52,
  // 44,
  // 45,
  // 52,
  // 55,
  // 44,
  // 15,
  // 17,
  // 18,
  // 53,
  // 55,
  // 52,
  // 53,
  // 54,
  // 55,
  // 15,
  // 16,
  // 17,
  // 61,
  // 36,
  // 37,
  // 36,
  // 0,
  // 35,

  //   };

  //Read Data for vertice and indexes coordinates and values
  readData();

  unsigned int VBO, VAO;      // declare variables
  glGenBuffers(1, &VBO);      // generate vertex buffer
  glGenVertexArrays(1, &VAO); // generate vertex array object
  /* bind the Vertex Array Object first, then bind and set vertex 
       buffer(s), and then configure vertex attributes(s)*/
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  // copy our vertex data into buffer
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
  //  glVertexAttribPointer(3, 7, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);

  //    Element buffer OBJECT
  unsigned int EBO;
  glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


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

  glBindVertexArray(VAO);

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window))
  {
    //input
    //.....
    processInput(window);

    // render
    // ------
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //green? rendering
    glClear(GL_COLOR_BUFFER_BIT);

    // draw our first triangle: using shader program
    glUseProgram(shaderProgram);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(float), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    /* glfw: swap buffers and poll IO events (keys pressed/released, 
	 mouse moved etc.)
	 --------------------------------------------------------------*/
    //cria janela e processa tudo o que nela se passa
    glfwSwapBuffers(window);

    glfwPollEvents();
  }

  // optional: de-allocate all resources once they've outlived their purpose:
  // ------------------------------------------------------------------------
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);

  glDeleteProgram(shaderProgram);

  // glfw: terminate, clearing all previously allocated GLFW resources.
  // ------------------------------------------------------------------
  glfwTerminate();
  return 0;
}
