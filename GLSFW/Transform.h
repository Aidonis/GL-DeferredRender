#pragma once
#include <glm\glm.hpp>


/*
	Transform that describes the a position and orientation.

	Very simple and rudimentary! GetGlobal should multiply
	through the parent's locals until we have this transform's
	global position/rotation.
*/

struct Transform
{
	glm::mat4 local;
	Transform *e_parent; // e_ is for external.

	Transform() : e_parent(nullptr), local(1) { }

	glm::mat4 getGlobal();
};