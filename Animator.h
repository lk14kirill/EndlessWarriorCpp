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
	Animator(float switchTime,bool playRandomlySameAnimations);
	~Animator();

	void Update(float deltaTime);

	void SetSwitchTime(float time);
	void AssignImagesForAnimation(std::string path, std::string type);
	void PlayAnim(std::string name);
	void ChangeState(State state);
	EWTexture* currTexture;

	bool playRandomlySameAnimations = false;
private:
	int imageCount;
	int currentImage;
	int startIndex;
	
	AnimationInfo* GetProperAnimation(std::string name);
	bool DoesAnimatiosExists(std::string name);
	void SetProperValues(std::string name);
	void LoadImagesToList(std::string path, std::string type, int animIndex,int startIndex, int imageIndex);
	std::vector<AnimationInfo*> animations;
	std::vector<EWTexture*> textures;

	std::string fileExtension = ".png";

	float totalTime;
	float switchTime;

};

