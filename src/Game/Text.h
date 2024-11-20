#pragma once
#include "GameElement.h"
#include "Utils/MyColor.h"
#include <string>

class Text : public GameElement
{
public:

	template <typename T> requires std::convertible_to<T, std::string>
	void SetText(T text) { m_Text = text; }
	const std::string& GetText() const { return m_Text; }

	void SetColor(MyColor color) { m_Color = color; }
	MyColor GetColor() const { return m_Color; }

protected:

	std::string m_Text;
	MyColor m_Color = 0xFFFFFFFF;
};
