#pragma once
#include "vector.h"
#include "ttable.h"
#include "tpair.h"


template <typename TKey, typename TValue>
class TUnorderedMapVector : public TTable<TKey, TValue>
{
private:
	Vector<TPair<TKey, TValue>> values;
public:
	TUnorderedMapVector(size_t size) 
	{
		values = Vector<TPair<TKey, TValue>>();
		values.setCopacity(size);
	};
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
			throw std::invalid_argument("you can not add value because key is exist in TUnorderedMapVector");
		}
		values.push_back(TPair<TKey, TValue> (key, value));
	}
	void Add(const TPair<TKey, TValue>& pair) override
	{
		this->Add(pair.key, pair.value);
	}
	void Remove(const TKey& key) override
	{
		size_t size = values.getSize();
		size_t i;
		for (i = 0; i < size; i++)
		{
			if (values[i].key == key)
			{
				//value = values[i].value;
				break;
			}
		}
		values.Remove(i);
	}
	~TUnorderedMapVector() {

	}
};