#pragma once
#include "SFML/Graphics.hpp" 
#include "Values.h"

class Animator
{
public:
	Animator(float switchTime);
	~Animator();

	void Update(float deltaTime,State state);

	void SetSwitchTime(float time);
	void AssignImagesForAnimation(std::string path, std::string type, int imagesCount);
	EWTexture* currTexture;

private:
	int idleImageCount;
	int currentImage;
	std::vector<EWTexture*> textures;

	float totalTime;
	float switchTime;

};
