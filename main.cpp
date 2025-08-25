/*
Copyright (c) 2025 Haydar Can Karabacak
All rights reserved.
*/

#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<iostream>
#include<fstream>

// #define WINDOW_WIDTH 1920
// #define WINDOW_HEIGHT 1080


// // TODO: Do this properly and add a correct way to end main loop.
// void processInput(GLFWwindow* window)
// {
//     if(glfwGetKey(window,GLFW_KEY_ESCAPE))
//     {
//         glfwSetWindowShouldClose(window,true);
//     }
// }

// void resizeCallback(GLFWwindow* window,int width,int height)
// {
//     glViewport(0,0,width,height);
// }




// const char *vertexShaderSource = "#version 330 core\n"
//     "layout (location = 0) in vec3 aPos;\n"
//     "void main()\n"
//     "{\n"
//     " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//     "}\0";

// const char* fragmentShaderSource = "#version 460 core\n"
//     "out vec4 FragColor;\n"
//     "void main()\n"
//     "{\n"
//     " FragColor = vec4(0.525f, 0.770f, 0.131f, 1.0f);\n"
//     "}\0";


// int main()
// {
//     // Initilize glfw

//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
//     glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
// #ifdef __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE); // Neccessary for macs
// #endif
//     // window object create

//     GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH,WINDOW_HEIGHT,"RPG",NULL,NULL);
//     if(window == NULL)
//     {
//         // TODO: log error correctly and insted of null to get error give string array.
//         std::cout<<"Error creatiing windiw " << std::hex<<glfwGetError(NULL) <<std::endl;
//         glfwTerminate();
//         return -1;
//     }

//     glfwMakeContextCurrent(window);
//     glfwSetFramebufferSizeCallback(window,resizeCallback);

//     if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         // TODO: log the error
//         std::cout<<"Error glad "<<std::endl;
//         return -1;
//     }
//     glViewport(0,0,WINDOW_WIDTH,WINDOW_HEIGHT);


//     // Main Loop

//     float vertices[] = 
//     {
//         -0.5f , -0.5f , 0.0f ,
//         0.5f , -0.5f , 0.0f ,
//         0.0f, 0.5f , 0.0f
//     };

//     //// Vertex array object
//     //unsigned int VAO;
//     //glGenBuffers(1,&VAO);
// //
//     // Vertex buffer object 
//     //unsigned int VBO;
//     //glGenBuffers(1,&VBO);
//     //glBindBuffer(GL_ARRAY_BUFFER,VBO);
//     //glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);


    

//     unsigned int vertexShader;
//     vertexShader = glCreateShader(GL_VERTEX_SHADER);
//     glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
//     glCompileShader(vertexShader);



//     int success;
//     char infoLog[512];
//     glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    
//     if(!success)
//     {
//         glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
//         std::cout<<"ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"<<infoLog<<std::endl;
//     }

    

//     unsigned int fragmentShader;
//     fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
//     glCompileShader(fragmentShader);

//     glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
//     if(!success)
//     {
//         glGetShaderInfoLog(fragmentShader,512,NULL,infoLog);
//         std::cout<<"ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n"<<infoLog<<std::endl;
//     }

//     unsigned int shaderProgram;
//     shaderProgram = glCreateProgram();
//     glAttachShader(shaderProgram,vertexShader);
//     glAttachShader(shaderProgram,fragmentShader);
//     glLinkProgram(shaderProgram);

//     glGetProgramiv(shaderProgram,GL_LINK_STATUS,&success);
//     if(!success)
//     {
//         glGetProgramInfoLog(shaderProgram,512,NULL,infoLog);
//         std::cout<<"ERROR::PROGRAM::LINKING_FAILED\n"<<infoLog<<std::endl;
//     }

//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);


//     unsigned int VBO, VAO;
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);
//     // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
// glBindVertexArray(VAO);
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);
    
//     // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//     glBindBuffer(GL_ARRAY_BUFFER, 0); 
    
//     // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//     // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//     glBindVertexArray(0); 
//     std::cout << glGetError() << "-1"<<std::endl;

//     //glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
//     ////0,3,GL_FLOAT,GL_FALSE,3*sizeof(float),(void*)0
//     //std::cout << glGetError() << "-1"<<std::endl;
//     //glEnableVertexAttribArray(0);
    


   

//     std::cout << glGetError() << std::endl;
//     while (!glfwWindowShouldClose(window))
//     {
//         // input
//         processInput(window);

//         // rendering

//         glClearColor(0.537f,0.812f,0.941f,1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//  glUseProgram(shaderProgram);
//     glBindVertexArray(VAO);
//     glDrawArrays(GL_TRIANGLES,0,3);

//         // check even swap buffers
//         glfwPollEvents();
//         glfwSwapBuffers(window);
//     }
    
    

//     glfwTerminate();
//     return 0;
// }

void resizeCallback(GLFWwindow* window,int width, int height);  
void processInput(GLFWwindow* window);


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
    
    
    const char *vertexShaderSource = "#version 460 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main()\n"
        "{\n"
        " gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
        "}\0";


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


    const char* fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main()"
        "{"
        "FragColor = vec4(0.412f, 0.941f, 0.0f, 1.0f);"
        "}";


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


