#pragma once

#include <ogl\gl_core_4_4.h>
#include <glfw\glfw3.h>
#include "declconst.h"

/*
The window is a specialized render target as well as the 
manager for the openGL context. IN THIS CASE, we will strive
to put ONLY GLFW code in here.

OpenGL code not related to starting up should now be in Rendering stuff.
*/

class Window
{
	GLFWwindow *window;

public:
	void init(int width = _WINDOW_WIDTH_, int height = _WINDOW_HEIGHT_, const char *name = "OpenGL Context");
	void term(); // close out the context

	void step(); // update the context
};