#pragma once
#include "GameElement.h"
#include "Utils/MyColor.h"
#include "Utils/Rect.h"

class Sprite : public GameElement
{
public:

	virtual void LoadImage(const char* path) = 0;
	virtual void* GetData() = 0;

	void SetSize(Vec2 size) { m_Size = size; }
	Vec2 GetSize() const { return m_Size; }
	Rect GetRect() const { return {m_Position, m_Size}; }

	// Call this once per frame
	void ApplyVelocity(float dt) { m_Position += m_Velocity * dt; }
	void SetVelocity(Vec2 vel) { m_Velocity = vel; }
	Vec2 GetVelocity() const { return m_Velocity; }

	void SetTint(MyColor tint) { m_Tint = tint; }
	MyColor GetTint() const { return m_Tint; }

protected:

	Vec2 m_Size{0, 0};
	Vec2 m_Velocity{0, 0};
	MyColor m_Tint{0xFFFFFFFF};
};
