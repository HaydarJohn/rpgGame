/*
Copyright (c) 2025 Haydar Can Karabacak
All rights reserved.
*/

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080


// TODO: Do this properly and add a correct way to end main loop.
void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window,GLFW_KEY_ESCAPE))
    {
        glfwSetWindowShouldClose(window,true);
    }
}

void resizeCallback(GLFWwindow* window,int width,int height)
{
    glViewport(0,0,width,height);
}




const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char* fragmentShaderSource = "#version 460 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    " FragColor = vec4(0.525f, 0.770f, 0.131f, 1.0f);\n"
    "}\0";


int main()
{
    // Initilize glfw

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE); // Neccessary for macs
#endif
    // window object create

    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"RPG",NULL,NULL);
    if(window == NULL)
    {
        // TODO: log error correctly and insted of null to get error give string array.
        std::cout<<"Error creatiing windiw " << std::hex<<glfwGetError(NULL) <<std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window,resizeCallback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        // TODO: log the error
        std::cout<<"Error glad "<<std::endl;
        return -1;
    }
    glViewport(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);


    // Main Loop

    float vertices[] = 
    {
        -0.5f , -0.5f , 0.0f ,
        0.5f , -0.5f , 0.0f ,
        0.0f, 0.5f , 0.0f
    };

    //// Vertex array object
    //unsigned int VAO;
    //glGenBuffers(1,&VAO);
//
    // Vertex buffer object 
    //unsigned int VBO;
    //glGenBuffers(1,&VBO);
    //glBindBuffer(GL_ARRAY_BUFFER,VBO);
    //glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);


    

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
    glCompileShader(vertexShader);



    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    
    if(!success)
    {
        glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
        std::cout<<"ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"<<infoLog<<std::endl;
    }

    

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    if(!success)
    {
        glGetShaderInfoLog(fragmentShader,512,NULL,infoLog);
        std::cout<<"ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"<<infoLog<<std::endl;
    }

    unsigned int shaderProgram;
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram,GL_LINK_STATUS,&success);
    if(!success)
    {
        glGetProgramInfoLog(shaderProgram,512,NULL,infoLog);
        std::cout<<"ERROR::PROGRAM::LINKING_FAILED\n"<<infoLog<<std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    
    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 
    std::cout << glGetError() << "-1"<<std::endl;

    //glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
    ////0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0
    //std::cout << glGetError() << "-1"<<std::endl;
    //glEnableVertexAttribArray(0);
    


    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,3);

    std::cout << glGetError() << std::endl;
    while (!glfwWindowShouldClose(window))
    {
        // input
        processInput(window);

        // rendering

        glClearColor(0.537f,0.812f,0.941f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // check even swap buffers
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    
    

    glfwTerminate();
    return 0;
}