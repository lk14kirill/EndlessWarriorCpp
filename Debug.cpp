#include "Debug.h"
void Debug::Log(string  message, DebugMessageType messageType) 
{
	cout << DefineColor(messageType) << DefineMessageType(messageType) << message << endl;
}
string Debug::DefineMessageType(DebugMessageType messageType)
{
	switch(messageType)
	{
	case DebugMessageType::ERROR:
		return "ERROR:";
	case DebugMessageType::INFO:
		return "INFO:";
	case DebugMessageType::FUN:
		return "FUN:";
	}
	return "UnknownMessage:";
}
string Debug::DefineColor(DebugMessageType messageType)
{
	switch (messageType)
	{
	case DebugMessageType::ERROR:
		return BOLDRED;
	case DebugMessageType::INFO:
		return GREEN;
	case DebugMessageType::FUN:
		return BOLDMAGENTA;
	}
	return RESET;
}

