#pragma once
#include "List.h"

template<typename T>
class ObjectPool
{
public:
	ObjectPool<T>(int size);
	~ObjectPool<T>();



	void Release(T* element);
	void Clear();
	T* Get();

	int CountActive();
	int CountInactive();
	int CountAll();

private:
	List<T*> m_enabled;
	List<T*> m_disabled;

};



template<typename T>
inline ObjectPool<T>::ObjectPool(int size)
{
	for (int i = 0; i < size; i++)
	{
		m_enabled.pushFront(new T());
	}
}

template<typename T>
inline ObjectPool<T>::~ObjectPool()
{

}

template<typename T>
inline int ObjectPool<T>::CountActive()
{
	return m_enabled.getLength();
}
