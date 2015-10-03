#pragma once

#include "declconst.h"
#include <iostream>
#include <unordered_map>

/*
	Asset management object.

	This /could/ be a static class or a singleton,
	but we'll mainly focus on wrapping up all of the GL handles
	in a single location.

	For type-safety, we will require a TYPE (from an enum in the declconst)
	and a name (string), so that we can refer to assets in a human readable way.
*/

class Assets
{
	std::unordered_map<std::pair<ASSET, std::string>, unsigned> m_glhandles;

public:
	// map[std::pair(ASSET::SHADER, name)]  = <GLHANDLE>
	void loadShader(const char *name, const char *v_path, const char *f_path);

	// map[std::pair(ASSET::TEXTURE, name)] = <GLHANDLE>
	void loadTexture(const char *name, const char *path);

	/*
	map[std::pair(ASSET::IBO ,name)] = <GLHANDLE>;
	map[std::pair(ASSET::VBO ,name)] = <GLHANDLE>;
	map[std::pair(ASSET::VAO ,name)] = <GLHANDLE>;
	map[std::pair(ASSET::SIZE,name)] = <number of triangles>;
	*/
	void loadGeometry(const char *name, Vertex *verts, unsigned vSize, unsigned *tris, unsigned tSize);

	// These may make one or more calls to loadGeometry/loadTexture!
	void loadFBX(const char *name, const char *path);
	void loadOBJ(const char *name, const char *path);

	// store an FBO handle,
	// but also provide enough detail to generate the textures that this FBO renders to
	// Each texture or RBO should be generated in the asset management library!!!
	void makeFrameBuffer(const char *name, float width, float height, size_t nTargets,
						 const char **targetNames, const FBO_PASS_TYPE *targetTypes);



	// Templated get function- get some type of a given name
	// eg. assetManager.get<ASSET::FBO>("SpecularPass")
	template<ASSET::TYPE T>
	unsigned get(const std::string &name)
	{
		auto key = std::pair(T, name);
		
		if (name.empty() || m_glhandles.count(key) == 0)
		{
			#ifdef _DEBUG
			std::cerr << "Warning: Asset \"" << name << "\" not found, \"Default\" used." << std::endl;
			#endif
			return m_glhandles[std::pair(T, "Default")];
		}
		return m_glhandles[key];
	}


	void init();	// Create some default geometry, textures, and shaders to ensure stuff works.
	void term();	// Clean up any assets stored in the map from the video card.
					// this needs to be explicitly called before the openGL context is uninitialized				
};


