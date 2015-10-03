#pragma once
#include "declconst.h"
#include <vector>

class RenderPass
{
	Asset<ASSET::SHADER> shader;
	Asset<ASSET::FBO>	 FBO;
	int width, height;
	bool toScreen;
	Entity *camera;			  // Should keep track of a camera

public:
	RenderPass(Asset<ASSET::SHADER> shader, Asset<ASSET::FBO> FBO, int a_w = _WINDOW_WIDTH_, int a_h = _WINDOW_HEIGHT_, bool screen = false)
		: shader(shader), FBO(FBO), width(a_w), height(a_h), toScreen(screen) {}

	virtual void prepass();   // Overload to add special GL settings
							  // or use additional values to do stuff
							  // Should also add a 'clear' in here.

							  // Making sure global uniforms are setup
							  // correctly should go in there too!
							  // glViewport and binding should happen here!

	void setUniform(const char *name, UNIFORM type, int c, void *value);
	void setCamera(Entity *e) { camera = e; }
	void drawEntity(Entity *e);	

	// use the prepass and draw all the entities
	void draw(std::vector<Entity*> entities)
	{
		prepass();
		for each(Entity *e in entities)
			drawEntity(e);
	}
};