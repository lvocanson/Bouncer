#pragma once

class TexturePtr
{
public:

	virtual void LoadFromFile(const char* path) = 0;
	virtual void Unload() = 0;

	template <typename T>
	T* As() { return reinterpret_cast<T*>(m_Ptr); }

protected:

	void* m_Ptr = nullptr;
};
