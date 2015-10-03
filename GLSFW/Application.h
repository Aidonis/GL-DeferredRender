#pragma once
#include "Window.h"
#include "Factory.h"
#include "Renderer.h"
#include "Assets.h"
#include "Processes.h"

class Application
{
	Window *w;
	Assets *a;
	Factory *f;
	Renderer *r;

public:

	void draw()
	{
		for each(RenderPass *rp in r->getPasses())
			rp->draw(f->getEntities());
	}


	void step()
	{
		for each(Entity *e in f->getEntities())
		{
			/*
				UPDATE GAME OBJET DATA THAT NEEDS TO BE UPDATED!			
			*/


		}
	}


	void init()
	{
		w = new Window;
		f = new Factory;
		r = new Renderer;
		a = new Assets;

		w->init();
	}


	void term()
	{
		a->term();
		w->term();
		
		delete w;
		delete f;
		delete r;
		delete a;
	}
};