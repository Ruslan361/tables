#pragma once
#include "vector.h"

template <typename TKey, typename TValue>
struct TPair
{
	TKey key;
	TValue value;
};

template <typename TKey, typename TValue>
class TTable
{
public:
	virtual void Add(const TKey& key, const TValue& value) = 0;
	virtual void Add(const TPair<TKey, TValue>& pair) = 0;
	virtual void Remove(const TKey& key) = 0;
	virtual bool Search(const TKey& key, TValue& value) const = 0;
	virtual ~TTable() = 0;
};

template <typename TKey, typename TValue>
class TUnorderedMapVector : public TTable<TKey, TValue>
{
	Vector<TPair<TKey, TValue>> values;
	TUnorderedMapVector(size_t size) = default;
	bool Search(const TKey& key, TValue& value) const override
	{
		size_t size = values.getSize();
		for (size_t i = 0; i < size; i++)
		{
			if (values[i].key == key)
			{
				value = values[i].value;
				return true;
			}
		}
		return false;
	}
	void Add(const TKey& key, const TValue& value) override
	{
		TValue search_value;
		if (Search(key, search_value))
		{
			throw std::invalid_argument("you can not add value because key is exist in TUnorderedMapVector")
		}
		values.push_back(value)
	}
	void Add(const TPair<TKey, TValue>& pair) override
	{
		this->Add(pair.key, pair.value);
	}
	virtual void Remove(const TKey& key)
	{
		size_t size = values.getSize();
		for (size_t i = 0; i < size; i++)
		{
			if (values[i].key == key)
			{
				value = values[i].value;
				return true;
			}
		}
	}
};