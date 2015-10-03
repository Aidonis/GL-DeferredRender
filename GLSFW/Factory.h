#pragma once
#include <vector>
#include "declconst.h"
#include "entity.h"

/*
	A container and creation point for all of the entities in the game.

	This object should be extended with as many factory creation methods you want.
*/

class Factory
{
	std::vector<Entity*> entities;

public:
	const std::vector<Entity*> getEntities() const { return entities; }

	/*
		Factory methods should make entities and add them to the above vector,
		as well as optionally provide a reference to the created entity
		for convenience (keeping track of cameras mainly).

		Fill out parameters that are meaningful to you!

		PUT THEM IN A SOURCE FILE FFS
	*/
	Entity *makeGrid(/*...*/);
	Entity *makeCube(/*...*/);
	Entity *makeLight(/*...*/);
	Entity *makeCamera(/*...*/)
	{
		/* EXAMPLE:
		Entity *e    = new Entity;
		e->camera	 = new Perspective;
		e->transform = new Transform;

		etc....
		*/
	}

	// In reality, we would only have one makeEntity and would
	// use a parser to take in formatted data to determine what
	// entity to create.


	~Factory()
	{
		for each(Entity *e in entities)
			delete e;
	}
};