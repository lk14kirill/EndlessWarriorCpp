#include "Animator.h"
using namespace std;

Animator::Animator(float switchTime)
{
	textures = std::vector<EWTexture*>();
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage = 0;
}

Animator::~Animator()
{
	for(EWTexture* text : textures)
	{
		delete text;
	}
	textures.clear();
}

void Animator::Update(float deltaTime, State state)
{
	totalTime += deltaTime;
	if(totalTime>= switchTime)
	{
		totalTime -= switchTime;
		currentImage++;
		if (currentImage >= idleImageCount)
			currentImage = 0;
	}
	currTexture = textures.at(currentImage);
}

void Animator::SetSwitchTime(float time)
{
	switchTime = time;
}

void Animator::AssignImagesForAnimation(string path, string type, int imagesCount)
{
	if (type == "idle")
		idleImageCount = imagesCount;

  for(int i = 0;i < imagesCount;i++)
  {
	  EWTexture* text = new EWTexture();
	  text->name = type + to_string(i);
	  text->texture.loadFromFile(path + type + to_string(i)+".png");
	  textures.push_back(text);
  }
}
