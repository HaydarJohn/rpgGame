/*
Copyright (c) 2025 Haydar Can Karabacak
All rights reserved.
*/

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<fstream>
#include <sstream>


void resizeCallback(GLFWwindow* window,int width, int height);  
void processInput(GLFWwindow* window);
const char* fileToString(std::string filePath);


int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    #ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
    #endif
    GLFWwindow* window = glfwCreateWindow(1920,1080,"RPG Game",NULL,NULL);

    if(window == NULL)
    {
        std::cout<<"Error Creating GLFW window!"<<std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout<<"Failed glad,"<<std::endl;
        return -1;
    }

    // register resizeCallback to glfw
    glfwSetFramebufferSizeCallback(window, resizeCallback);


    
    
    // Start of triangle code.
    
    //for debugging purpose
    int success;
    char infoLog[512];
    
    
    const char *vertexShaderSource = fileToString("shaders/triangle.vert");

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    
    if(!success)
    {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
    infoLog << std::endl;
    }


    const char* fragmentShaderSource = fileToString("shaders/triangle.frag");


    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);

    if(!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
        infoLog << std::endl;
    }

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);


    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" <<
        infoLog << std::endl;
    }


    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    // start of vertex data

    float vertices[]
    {
        -0.5f,-0.5f,0.0f,
        0.5f,-0.5f,0.0f,
        0.0f,0.5f,0.0f
    };

    /*  Warning: Educational
        So i get same error by not getting any triangles. this time what i had
        is i accidently wrote glGenBuffers for VAO instead of glGenVertexArrays.
        but steps are for creating triangle
        1- create shaders , compile and link shaders
        2- create vertex array and bind it (bind it where i dont know???)
        3- create vertex buffer and bind it and attach data
        4- specify what is in the vertex buffer with vertexattribpointer
        5- enable our vertex array ???? not sure
        6- tell in main loop to use our shader
        7- bind our vertex array again ????? whaaat
        8- tell our graphics card to draw everything now.
    */
    unsigned int VAO,VBO;
    glGenBuffers(1,&VBO);
    glGenVertexArrays(1,&VAO);

    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);



   
    



    // Engine Loop
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);
        
        // start of render code
        glClearColor(0.537f,0.812f,0.941f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        // our render code
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);     // Idk we keep binding same array.
        glDrawArrays(GL_TRIANGLES, 0, 3);


        // end of render code 
        glfwPollEvents();
        glfwSwapBuffers(window);

    }
    
    glfwTerminate();
    return 0;

}


void resizeCallback(GLFWwindow* window,int width, int height)
{
    glViewport(0,0,width,height);
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window,GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window,true);
    }
}



/*
    TODO: Read fileToString function and understand why this works ?
            and i warn you dont touch it.
            Ai`s no use the dont understand it works either.
*/
const char* fileToString(std::string fileName)
{
   std::ifstream file(fileName, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cerr << "Failed to open file: " << fileName << std::endl;
        return nullptr;
    }

    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    // allocate +1 for null terminator
    char* buffer = new char[size + 1];
    if (!file.read(buffer, size)) {
        std::cerr << "Failed to read file: " << fileName << std::endl;
        delete[] buffer;
        return nullptr;
    }

    buffer[size] = '\0'; // null terminate!
    return buffer;
    
}


