#pragma once

#include "declconst.h"

/**********

	In some form of factory object or organization,
	you should make Entities and then allocate new
	components for whatever features the entity should have.

	In this way, there is no difference between a camera,
	a player, terrain, or a light-- only that the game
	engine uses their data differently to determine
	their behaviors.

**********/

struct Entity
{
	Transform	 *transform;
	Material	 *material;
	Camera		 *camera;
	Geometry	 *geometry;
	Controller	 *controller;

	Entity()
		: transform (nullptr), material(nullptr),
		  controller(nullptr), geometry(nullptr),
		  camera	(nullptr)
	{ }

	~Entity()
	{
		if (transform)	 delete transform;
		if (camera)		 delete camera;
		if (material)	 delete material;
		if (controller)  delete controller;
		if (geometry)    delete geometry;
	}
};
