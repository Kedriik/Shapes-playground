#version 430// core

// Input vertex data, different for all executions of this shader.
layout(location = 0) in vec4 vertexPosition_modelspace;

layout( std430, binding=1) buffer PerFrameBuffer
{
    mat4 ModelMatrix;
    mat4 ProjectionMatrix;
    mat4 ViewMatrix;
    vec4 additionalStorage;  
};

void main()
{
	gl_Position =  vertexPosition_modelspace;
}

