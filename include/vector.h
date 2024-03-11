#pragma once
#include <stdexcept>

template <typename T>
class Vector {
private:
	T* _array;
	size_t count;
public:
	Vector() {
		_array = nullptr;
		count = 0;
	}
	Vector(size_t count) {
		_array = new T[count];
		this->count = count;
	}
	Vector(const Vector<T>& _vector);
	size_t getSize() {
		return count;
	}
	T& at(size_t index) {
		if (index >= count)
			throw std::out_of_range(__FUNCTION__);
		return _array[index];
	}
	~Vector() {
		if (_array != nullptr)
			delete[] _array;
		count = 0;
	}
	void push_back(const T& element);
	T& getBack() {
		return _array[count - 1];
	}
	T& getFront() {
		return _array[0];
	}
	const bool operator==(const Vector<T>& _vector) const;
	void resize(size_t size);
	T& operator[] (size_t index) { return _array[index]; }
};

template <typename T>
const bool Vector<T>::operator==(const Vector<T>& _vector) const {
	if (count != _vector.count)
		return false;
	for (size_t i = 0; i < count; i++)
	{
		if (_array[i] != _vector._array[i])
			return false;
	}
	return true;
}

template <typename T>
void Vector<T>::push_back(const T& element) {
	resize(count + 1);
	getBack() = element;
}

template <typename T>
Vector<T>::Vector<T>(const Vector<T>& _vector) {
	this->count = _vector.count;
	this->_array = new T[count];
	std::copy(_vector._array, _vector._array + count, _array);
}

template <typename T>
void Vector<T>::resize(size_t size) {
	Vector<T> temp(*this);
	if (_array != nullptr) {
		delete[] _array;
	}
	_array = new T[size];
	size_t min = size < count ? size : count;
	memcpy(_array, temp._array, (min * sizeof(T)));
	count = size;
}
