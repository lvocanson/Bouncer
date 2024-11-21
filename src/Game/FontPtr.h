#pragma once

class FontPtr
{
public:

	virtual void LoadFromFile(const char* path) = 0;
	virtual void Unload() = 0;
	virtual void SetSize(float size) { m_Size = size; }
	float GetSize() const { return m_Size; }

	template <typename T>
	T* As() { return reinterpret_cast<T*>(m_Ptr); }

protected:

	void* m_Ptr = nullptr;
	float m_Size = 0;
};
