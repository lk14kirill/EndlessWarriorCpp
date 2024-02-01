#include "Animator.h"
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

Animator::Animator(float switchTime)
{
	textures = vector<EWTexture*>();
	animations = vector<AnimationInfo*>();
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage = 0;
	startIndex = 0;
}
Animator::~Animator()
{
	for(EWTexture* texture : textures)
	{
		delete texture;
	}
	for (AnimationInfo* anim : animations)
	{
		delete anim;
	}
	animations.clear();
	textures.clear();
}

void Animator::Update(float deltaTime, State state)
{
	totalTime += deltaTime;
	if(totalTime>= switchTime)
	{
		totalTime -= switchTime;
		currentImage++;
		if (currentImage >= startIndex +imageCount)
			currentImage = startIndex;
	}
	currTexture = textures.at(currentImage);
}

void Animator::SetSwitchTime(float time)
{
	switchTime = time;
}

void Animator::AssignImagesForAnimation(string path, string type)
{
	int startIndex = textures.size(); 
	int i = 0;

	string fileName = path + type + to_string(i)+ ".png";
	while (fs::exists(fileName))
	{
		EWTexture* text = new EWTexture();
		text->name = type + to_string(i);
		text->texture.loadFromFile(path + type + to_string(i) + ".png");
		textures.push_back(text);

		i++;
		fileName = path + type + to_string(i) + ".png";
		imageCount++;
	}
  if (type == "idle")
	  animations.push_back(new AnimationInfo("idle", startIndex, i));
}

void Animator::ChangeState(State state)
{
	switch(state)
	{
	case State::idle:
		SetProperValues("idle");
			break;
	case State::attack:
		SetProperValues("attack");
		break;
	case State::moving:
		SetProperValues("moving");
		break;
	}
}
AnimationInfo* Animator::GetProperAnimation(std::string name)
{
	for (AnimationInfo* anim : animations)
		if (anim->name == name) return anim;
	return animations[0];
}

void Animator::SetProperValues(std::string name)
{
	AnimationInfo* anim = GetProperAnimation(name);
	currentImage = anim->startIndex;
	startIndex = anim->startIndex;
	imageCount = anim->countImages;
}



