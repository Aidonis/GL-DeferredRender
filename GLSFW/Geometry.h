#pragma once

#include "declconst.h"

/*
IDK y'all, you don't need much more information to render geometry.
You could collapse this into the material if you wanted that structure
to look even worse.

YOLO
*/

struct Geometry
{
	Asset<ASSET::VAO> VAO;
	Asset<ASSET::SIZE> size; // *3
};

// glDrawElements(..., t.get<ASSETT::VAO>(name), t.get<ASSETT::SIZE>(name), )