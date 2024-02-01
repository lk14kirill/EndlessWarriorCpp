#pragma once
#include "Values.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "AnimationValues.h"

class EWTexture {
public:
	sf::Texture texture;
	std::string name;
};

class Animator
{
public:
	Animator(float switchTime);
	~Animator();

	void Update(float deltaTime,State state);

	void SetSwitchTime(float time);
	void AssignImagesForAnimation(std::string path, std::string type);
	void ChangeState(State state);
	EWTexture* currTexture;

private:
	int imageCount;
	int currentImage;
	int startIndex;
	
	AnimationInfo* GetProperAnimation(std::string name);
	void SetProperValues(std::string name);
	std::vector<AnimationInfo*> animations;
	std::vector<EWTexture*> textures;

	float totalTime;
	float switchTime;

};

