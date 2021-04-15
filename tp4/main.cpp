//1. make
//2. ./tp1.ex1/tp1.ex1

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/io.hpp>


using namespace std;

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



//------------------------------------------------------------
// Input vertex data, different for all executions of this shader.
// Output data color, will be interpolated for each fragment.
const char *vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 vertexColor;\n"
"out vec3 fragmentColor;\n"
"uniform mat4 MVP;\n"
"void main()\n"
"{\n"
" gl_Position = MVP * vec4(aPos, 1.0);\n"
" fragmentColor = vertexColor;\n"
"}\0";

// declare and define fshader, position in color vector declaration
// are RGBA from [0,1] simply in and out
const char *fragmentShaderSource = "#version 330 core\n"
    "in vec3 fragmentColor;\n;"
    "out vec3 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = fragmentColor;\n"
    "}\n\0";



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
  GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Cubo", NULL,
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
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
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
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // link shaders : puts together the vertex and the fragment shaders
    // into a "shader program object"
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for shader linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    // delete shaders, we don't need them anymore
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

//------------------------------------------------------------
    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    // set up vertex data with depth
// ----------------------------------------
  // Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive
    // vertices give a triangle. A cube has 6 faces with 2 triangles each, so this
    // makes 6*2=12 triangles, and 12*3 vertices
    // ------------------------------------------------------------------
    static const float vertices[] = {
		-1.0f,-1.0f,-1.0f,    // left,down,rear - T1
		-1.0f,-1.0f, 1.0f,    // left,down,front
		-1.0f, 1.0f, 1.0f,    // left,up,front
		 1.0f, 1.0f,-1.0f,    // right,up,rear - T2
		-1.0f,-1.0f,-1.0f,    // left,down,rear
		-1.0f, 1.0f,-1.0f,    // left,up,rear
		 1.0f,-1.0f, 1.0f,    // right,down,front - T3
		-1.0f,-1.0f,-1.0f,    // left,down,rear
		 1.0f,-1.0f,-1.0f,    // right,down,rear
		 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f,-1.0f,
		 1.0f,-1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		 1.0f,-1.0f, 1.0f
	};

	// One color for each vertex. They were generated randomly.
	static const float colors[] = { 
		0.583f,  0.771f,  0.014f,
		0.609f,  0.115f,  0.436f,
		0.327f,  0.483f,  0.844f,
		0.822f,  0.569f,  0.201f,
		0.435f,  0.602f,  0.223f,
		0.310f,  0.747f,  0.185f,
		0.597f,  0.770f,  0.761f,
		0.559f,  0.436f,  0.730f,
		0.359f,  0.583f,  0.152f,
		0.483f,  0.596f,  0.789f,
		0.559f,  0.861f,  0.639f,
		0.195f,  0.548f,  0.859f,
		0.014f,  0.184f,  0.576f,
		0.771f,  0.328f,  0.970f,
		0.406f,  0.615f,  0.116f,
		0.676f,  0.977f,  0.133f,
		0.971f,  0.572f,  0.833f,
		0.140f,  0.616f,  0.489f,
		0.997f,  0.513f,  0.064f,
		0.945f,  0.719f,  0.592f,
		0.543f,  0.021f,  0.978f,
		0.279f,  0.317f,  0.505f,
		0.167f,  0.620f,  0.077f,
		0.347f,  0.857f,  0.137f,
		0.055f,  0.953f,  0.042f,
		0.714f,  0.505f,  0.345f,
		0.783f,  0.290f,  0.734f,
		0.722f,  0.645f,  0.174f,
		0.302f,  0.455f,  0.848f,
		0.225f,  0.587f,  0.040f,
		0.517f,  0.713f,  0.338f,
		0.053f,  0.959f,  0.120f,
		0.393f,  0.621f,  0.362f,
		0.673f,  0.211f,  0.457f,
		0.820f,  0.883f,  0.371f,
		0.982f,  0.099f,  0.879f,
	};

  //Read Data for vertice and indexes coordinates and values
  //readData();


//------------------------------------------------------------
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    /* bind the Vertex Array Object first, then bind and set vertex 
       buffer(s), and then configure vertex attributes(s)*/
    glBindVertexArray(VAO);
    
    // copy our vertex data into buffer
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);


 

    // uncomment this call to draw in wireframe polygons.
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

//------------------------------------------------------------
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//    Element buffer OBJECT
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ARRAY_BUFFER, EBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colors), colors, GL_STATIC_DRAW);

  


    //scaling
    glm::vec4 v = glm::vec4(1.0f,0.0f,0.0f,1.0f);
    glm::mat4 su = glm::mat4(1.0f);
    std::cout <<"S before = " << std::endl << " " << su << std::endl;
    v = su*v;
    std::cout <<"v  = " << std::endl << " " << v << std::endl;
    su = glm::scale(su, glm::vec3(0.5f,0.5f,0.5f));

    std::cout <<"S after = " << std::endl << " " << su << std::endl;

    glm::mat4  sU = glm::mat4(0.25, 0.0, 0.0, 0.0,
                              0.0, 0.25, 0.0, 0.0,
                              0.0, 0.0, 0.25, 0.0,
                              0.0, 0.0, 0.0, 1.0);
    

    glm::mat4  sN = glm::mat4(0.25, 0.0, 0.0, 0.0,
                              0.0, 0.5, 0.0, 0.0,
                              0.0, 0.0, 0.5, 0.0,
                              0.0, 0.0, 0.0, 1.0);
    //translation
    glm::vec4 vt = glm::vec4(1.0f,0.0f,0.0f,1.0f);
    glm::mat4 T = glm::mat4(1.0f);
    std::cout <<"t before = " << std::endl << " " << T << std::endl;
    T = glm::translate(T, glm::vec3(1.5f,1.5f,0.0f));
    vt = T *vt;
    std::cout <<"vt  = " << std::endl << " " << vt << std::endl;
    std::cout <<"t after = " << std::endl << " " << T << std::endl;
    
    //o mat4 usa a transporta
    glm::mat4  myT = glm::mat4(1.0, 0.0, 0.0, 0.0,
                              0.0, 1.0, 0.0, 0.0,
                              0.0, 0.0, 1.0, 0.0,
                              -0.5, 0.5, 0.0, 1.0);
    std::cout <<"myT  = " << std::endl << " " << myT << std::endl;
    
    // Get a handle for our "MVP" uniform
      unsigned int MatrixID = glGetUniformLocation(shaderProgram, "MVP");

      // Projection matrix : 45ï¿½ Field of View, 4:3 ratio,
      // display range : 0.1 unit <-> 100 units
      glm::mat4 Projection = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
      // View camera matrix
      glm::mat4 View = glm::lookAt(
                      glm::vec3(4,3,-3), // Camera is at (4,3,-3), in World Space
                      glm::vec3(0,0,0), // and looks at the origin
                      glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
          );
      // Model matrix : an identity matrix (model will be at the origin)
      glm::mat4 Model = glm::mat4(1.0f);
      // Our ModelViewProjection : multiplication of our 3 matrices
      // Remember, matrix multiplication is the other way around
      glm::mat4 MVP   = Projection * View * Model; 
      
      //SCALING uniform
     // MVP = MVP*sU;

      //SCALING  non uniform
      //MVP = MVP*sN;

      //TRANSLATION
      MVP = MVP*myT;
    
      //SCALING uniform
      MVP = MVP*sU;

  // render loop
  // -----------
  while (!glfwWindowShouldClose(window))
  {
    //input
    //.....
    processInput(window);

    // render
    // ------

     // Dark blue background
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shaderProgram);
    glBindVertexArray(VBO);



   // Send our transformation to the currently bound shader, 
      // in the "MVP" uniform
      glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

    //------------------------------------------------------------
	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(
		0,            // attribute. No particular reason for 0, but
		              // must match the layout in the shader.
		3,            // size
		GL_FLOAT,     // type
		GL_FALSE,     // normalized?
		0,            // stride
		(void*)0      // array buffer offset
	);

	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, EBO);
	glVertexAttribPointer(
		1,            // attribute. No particular reason for 1, but
		              // must match the layout in the shader.
		3,            // size
		GL_FLOAT,     // type
		GL_FALSE,     // normalized?
		0,            // stride
		(void*)0      // array buffer offset
	);

        // Enable depth test
          glEnable(GL_DEPTH_TEST);  
          // Accept fragment if it closer to the camera than the former one
          glDepthFunc(GL_LESS); 

          // also clear the depth buffer now!
         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
          
       
        // seeing as we only have a single VAO there's no need to bind
        // it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 36);
        // glBindVertexArray(0); // no need to unbind it every time 


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
