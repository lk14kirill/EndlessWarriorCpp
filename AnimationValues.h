#pragma once
#include <iostream>
struct AnimationInfo
{
public:
	AnimationInfo(std::string name, int startIndex, int countImages);

	std::string name;
	int startIndex;
	int countImages;
};



