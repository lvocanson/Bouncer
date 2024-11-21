#pragma once
#include <cstdarg>
#include <cstdio>

class Logger
{
public:

	static Logger* Instance() { return s_Instance; }
	static void SetInstance(Logger* log) { s_Instance = log; }

	enum Category : char
	{
		Info,
		Warn,
		Error,
		Debug
	};

	virtual void Log(Category, const char* text) = 0;

private:

	static inline Logger* s_Instance = nullptr;
};
