#pragma once

class Renderer
{
public:
	Renderer();
	~Renderer();

	void renderScene();

	static Renderer* activeRenderer;

	static void setActiveRenderer(Renderer* renderer);

	static void renderSceneCallbackWrapper();
};

