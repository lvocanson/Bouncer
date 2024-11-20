#pragma once
#include "Utils/Vec2.h"

class GameElement
{
public:

	virtual ~GameElement() = default;

	void SetPosition(Vec2 pos) { m_Position = pos; }
	void Move(Vec2 delta) { m_Position += delta; }
	Vec2 GetPosition() const { return m_Position; }

	bool IsVisible() const { return m_IsVisible; }
	void SetVisible(bool visible) { m_IsVisible = visible; }

protected:

	Vec2 m_Position{0, 0};
	bool m_IsVisible = true;
};
