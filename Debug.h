#pragma once
#include <string>
#include <iostream>
#include "values.h"
using namespace std;
class Debug
{
public:
	static void Log(string message, DebugMessageType);
private:
	static string DefineMessageType(DebugMessageType);
};
	
