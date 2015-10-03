#pragma once
#include <string>
#include <glm\glm.hpp>
/*
	Declarations and constants for use throughout this project.
*/

class Entity;

struct Transform;
struct Material;
struct Camera;
struct Geometry;
struct Controller;

#ifndef _WINDOW_WIDTH_
#define _WINDOW_WIDTH_  800.0f
#endif

#ifndef _WINDOW_HEIGHT_
#define _WINDOW_HEIGHT_ 600.0f
#endif


const char *UniformNames[] = 
{
 "Projection",
 "View",
 "Model",
 "Time",
 "DiffuseMap",
 "SpecularMap",
 "NormalMap",
 "GlossMap",
 "AmbientMap",
 "SpecularFactor",
 "DiffuseTint",
 "SpecularTint",
 "ambientTint",
 
};

// Types of uniforms we will try and support specifically
enum class UNIFORM { NONE, INT, FLO, VEC3, VEC4, MAT4, TEXTURE };

/*
	Enums for use by the asset management system.
	Each one corresponds to a handle, with the exception SIZE,
	that's just data needed for rendering.
*/
enum class ASSET { NONE, FBO, IBO, VBO, VAO, RBO, SIZE, SHADER, TEXTURE };

// What textures do we render when we make an FBO? Add more if you want/need.
// bit32 is for normal/position, bit8 is for color, depth is for RenderBufferObject (instead of texture)
enum class FBO_PASS_TYPE { NONE, BIT8, BIT32, DEPTH };

/*
	Asset Reference Object:

	The purpose is to provide a type secure way of managing
	references to assets managed by the Asset management object.
	The asset management object mainly just stores all of the openGL
	handles that it gives to us.

	This object is passed into the asset management object to give us
	access to the handles being stored inside.
*/
template<ASSET T>
struct Asset
{
	const ASSET type;
	std::string name;

	Asset() : type(T), name("") { }

	std::pair<T, std::string> key() { return std::pair(type, name); }

	Asset &operator=(const std::string &n) { name = n; }
};



/*
Simple vertex struct to serve as a basis for asset loading.

When loading FBX and OBJ, IF YOU USE THIS STRUCT AS IS,
you will need to parse the data from these file formats
to fill out the vertex data properly.
*/

struct Vertex
{
	glm::vec4 position;
	glm::vec4 normal;
	glm::vec4 tangent;
	glm::vec2 texCoord;
};