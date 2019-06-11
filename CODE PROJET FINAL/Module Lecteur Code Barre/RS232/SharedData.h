#pragma once

#include <vector>
#include <Windows.h>

template <typename T>
class SharedData
{
	std::vector<T> data;
	HANDLE mutex;

public:
	SharedData();
	~SharedData();

	void Add(T value);
	T Get();
	size_t Size();
};

template <typename T>
SharedData<T>::SharedData()
{
	mutex = CreateMutex(NULL, FALSE, NULL);
}

template <typename T>
SharedData<T>::~SharedData()
{
	CloseHandle(mutex);
}

template <typename T>
void SharedData<T>::Add(T value)
{
	WaitForSingleObject(mutex, INFINITE);
	data.push_back(value);
	ReleaseMutex(mutex);
}

template <typename T>
T SharedData<T>::Get()
{
	WaitForSingleObject(mutex, INFINITE);

	if (data.size() == 0)
	{
		ReleaseMutex(mutex);
		throw "Vector is empty";
	}

	T value = data.front();
	data.erase(data.begin());
	ReleaseMutex(mutex);

	return value;
}

template <typename T>
size_t SharedData<T>::Size()
{
	size_t size;

	WaitForSingleObject(mutex, INFINITE);
	size = data.size();
	ReleaseMutex(mutex);

	return size;
}