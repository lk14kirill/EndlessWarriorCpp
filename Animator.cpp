#include "Animator.h"
#include <filesystem>
#include "Debug.h"

using namespace std;
namespace fs = std::filesystem;

Animator::Animator(float switchTime,bool playRandomlySameAnimations)
{
	this->playRandomlySameAnimations = playRandomlySameAnimations;
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

void Animator::Update(float deltaTime)
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
	
	int imageIndex = 0;
	int animIndex = 0;

	string fileName= path + to_string(animIndex) + type + to_string(imageIndex) + fileExtension;;
	while (fs::exists(fileName))
	{
		int startIndex = textures.size();
		LoadImagesToList(path, type, animIndex,startIndex, imageIndex);
		animIndex++;
		fileName = path + to_string(animIndex) + type + to_string(imageIndex) + fileExtension;
	}
}
void Animator::PlayAnim(std::string name)
{
	SetProperValues(name);
}
void Animator::LoadImagesToList(std::string path, std::string type, int animIndex,int startIndex, int imageIndex)
{
	string fileName = path + to_string(animIndex) + type + to_string(imageIndex) + fileExtension;
	while (fs::exists(fileName))
	{
		EWTexture* text = new EWTexture();
		text->name = type + to_string(imageIndex);
		text->texture.loadFromFile(path + to_string(animIndex) + type + to_string(imageIndex) + ".png");
		textures.push_back(text);

		imageIndex++;
		fileName = path + to_string(animIndex) + type + to_string(imageIndex) + ".png";
		imageCount++;
	}
	if (type == "idle")
		animations.push_back(new AnimationInfo("idle"+to_string(animIndex), startIndex, imageIndex));
	if (type == "attack")
		animations.push_back(new AnimationInfo("attack" + to_string(animIndex), startIndex, imageIndex));
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

bool Animator::DoesAnimatiosExists(std::string name)
{
	for (AnimationInfo* anim : animations)
		if (anim->name == name) return true;
	return false;
}
void Animator::SetProperValues(std::string name)
{	
	AnimationInfo* anim= GetProperAnimation(name + "0");
	if(playRandomlySameAnimations)
	{
		int animIndex= rand();
		while(!DoesAnimatiosExists(name+to_string(animIndex)))
		{
			animIndex = rand() % animations.size() - 1; //offset by 1 because % will never give 0
		}
		anim = GetProperAnimation(name + to_string(animIndex));
		Debug::Log(anim->name, DebugMessageType::INFO);
	}
	currentImage = anim->startIndex;
	startIndex = anim->startIndex;
	imageCount = anim->countImages;
}




