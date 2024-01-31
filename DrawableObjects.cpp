#include "DrawableObjects.h"
#include "IDrawable.h"
#include "SFML/Graphics.hpp"

using namespace std;

void DrawableObjects::Add(Actor* drawable)
{
	drawables.push_back(drawable);
}
void DrawableObjects::Remove(Actor* drawable)
{
	for(int i=0;i<drawables.size();i++)
	{
		if (drawables[i]->GetObject() == drawable->GetObject())
		{
			
			drawables.erase(drawables.begin() + i);
		}
	}
}
vector<Actor*> DrawableObjects::GetDrawables()
{
	return drawables;
}
DrawableObjects::~DrawableObjects()
{
	drawables.clear();
}
DrawableObjects::DrawableObjects()
{
	drawables = vector<Actor*>();
}
void DrawableObjects::Draw(sf::RenderWindow* window)
{
	for(Actor* drawable : drawables)
	{
		(*window).draw(*(drawable->GetDrawableGO()));
	}
}