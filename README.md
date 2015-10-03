# GLSFW
Simple API/Framework for implementing an OpenGL deferred renderer. This is a WIP SKELETON intended for students to fill out. It is to help alleviate/solve some software engineering problems to allow focusing on writing openGL/GLSL.


This is going to be refactored in a few minutes and some further detail about the design of this will be uploaded >__>.


Instructions:

Window:
	Fill out Window to wrap essential GLFW functionality. It should not really be making any openGL calls.



Assets:
	Abstraction layer to represent data stored in VRAM on our side. Fill out the loading functions to pull data from files and store them inside. Review the header file for more detail.



Renderer:
	Manages the RenderPasses the application will step through during the draw phase. This should be modified to add additional renderPass creation functions as they are needed.


RenderPass:
	A render pass contains all of the data and logic to write from a shader to an FBO using game-object data. You may need to INHERIT from this class to modify what the PREPASS step does. The Prepass is any settings (glEnable, etc) and global shader uniforms (Camera data, time, etc). You'll also need a way to interpret the material struct on an object to know what shader uniforms to set.

Factory:
	A management object that stores all of the entities in the game. Each entity is constructed of one or more components- a few have been provided, but more could be added. Add additional 'make' functions as you see fit.


Components:
	Transform -> Y'know!
	Geometry  -> Stores a reference to the data necessary to draw the gameobject.
	Material  -> Stores surface data.
	Camera	  -> Data about our lens.
	Controller-> Fill out whatever you want to bring the camera to life.
