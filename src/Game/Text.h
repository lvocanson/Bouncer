#pragma once
#include "GameElement.h"
#include "Utils/MyColor.h"
#include <string>

class Text : public GameElement
{
public:

	// Do a copy
	void SetText(std::string text) { m_Text = text; }
	const std::string& GetText() const { return m_Text; }

	void SetColor(MyColor color) { m_Color = color; }
	MyColor GetColor() const { return m_Color; }

protected:

	std::string m_Text;
	MyColor m_Color = 0xFFFFFFFF;
};
