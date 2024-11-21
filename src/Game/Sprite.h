#pragma once
#include "GameElement.h"
#include "Utils/MyColor.h"
#include "Utils/Rect.h"

class TexturePtr;

class Sprite : public GameElement
{
public:

	void SetTexture(TexturePtr* tex) { m_Texture = tex; }
	TexturePtr* GetTexture() const { return m_Texture; }

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

	TexturePtr* m_Texture;
	Vec2 m_Size{0, 0};
	Vec2 m_Velocity{0, 0};
	MyColor m_Tint{0xFFFFFFFF};
};
