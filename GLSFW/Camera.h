#pragma once
#include "declconst.h"

/*
	The only information about a camera that is typically
	relevant or unique to cameras is the projection matrix.

	If we think of the camera as an object within our game,
	the 'view' matrix is simply the global matrix of the
	transform component.

	In other words- this object doesn't represent an entire camera,
	just the data that is /unique/ to cameras. We might say this
	is just the lens!
*/

struct Camera { };

struct Perspective : public Camera
{
	float FOV, aspect, near, far;
	Perspective() : FOV(90), aspect(_WINDOW_WIDTH_ / _WINDOW_HEIGHT_), near(0), far(100) {}
};


struct Orthographic : public Camera
{
	float left, right, top, bottom;
	Orthographic() : left(0), right(_WINDOW_WIDTH_), top(0), bottom(_WINDOW_HEIGHT_) {}
};


