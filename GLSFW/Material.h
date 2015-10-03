#pragma once
#include <glm\glm.hpp>
#include "declconst.h"

/*
	All the data necessary to shade a phong material.

	Note the TYPE enum. All of the data for a material
	COULD be the same as for PHONG or a LIGHT. The only
	difference between the information is how they are rendered.
	A light's color can be sampled from a texture just the same
	as you would for a normal object!

	Anyway, there are a few different types of lights here (add more if you want!)

	Point depends upon transform for a position (and uses attenuation or falloff)
	Directional depends upon transform for a direction
	Ambient doesn't need either!
	Volume needs transform for position and geometry for the area it is lighting- possibly attenuation used also.
	Spotlight not included, but you could.
*/

struct Material
{
	enum TYPE { NONE, SURFACE, LIGHT_AMBIENT, LIGHT_DIRECTIONAL, LIGHT_VOLUME, LIGHT_POINT, LIGHT_SPOT } type;
	// These values should be multiplied by the texture sampled to provide a tinting color
	// If no texture is present,
	glm::vec4 ambientTint;
	glm::vec4 specularTint;
	glm::vec4 diffuseTint;

	bool useVertexColor;
	bool wireframe;
	float specPowScalar;			// surfaces
	float attenuation;				// point light
	float penumbraAngle, coneAngle;	// Spotlight

	// Texture map versions
	Asset<ASSET::TEXTURE> diffuseMap;		// For surface color
	Asset<ASSET::TEXTURE> specularMap;		// For specular color
	Asset<ASSET::TEXTURE> ambientMap;		// For ambient color
	
	Asset<ASSET::TEXTURE> glossMap;			// For specular power
	Asset<ASSET::TEXTURE> normalMap;		// For surface normals

	Material() : type(NONE), ambientTint(1), specularTint(1),
				 diffuseTint(1), specPowScalar(1.0f), attenuation(1.0f),
				wireframe(false), useVertexColor(false)
	{ }
};