#pragma once
#pragma once
#include <vector>
#include "declconst.h"
#include "RenderPass.h"

/*
A container and creation point for all of the entities in the game.

This object should be extended with as many factory creation methods you want.
*/

class Renderer
{
	std::vector<RenderPass*> passes;

public:
	const std::vector<RenderPass*> getPasses() const { return passes; }


	RenderPass *addPass(Asset<ASSET::SHADER> shader, Asset<ASSET::FBO> FBO, Entity *camera = nullptr)
	{
		RenderPass *rp = new RenderPass(shader,FBO);

		rp->setCamera(camera);		

		passes.push_back(rp);
		return rp;
	}


	~Renderer()
	{
		for each(RenderPass *e in passes)
			delete e;
	}
};