#include "Debug.h"
void Debug::Log(string message, DebugMessageType messageType) 
{
	cout << DefineMessageType(messageType) << message << endl;
}
string Debug::DefineMessageType(DebugMessageType messageType)
{
	switch(messageType)
	{
	case DebugMessageType::ERROR:
		return "ERROR:";
	case DebugMessageType::INFO:
		return "INFO:";
	}
	return "UnknownMessage:";
}

