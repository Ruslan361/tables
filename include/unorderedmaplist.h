#pragma once
#include "tsinglelinkedlist.h"
#include "ttable.h"
#include "tpair.h"


template <typename TKey, typename TValue>
class TUnorderedMapList : public TTable<TKey, TValue>
{
private:
	TSingleLinkedList<TPair<TKey, TValue>> values;
public:
	TUnorderedMapVector()
	{
		values = TSingleLinkedList<TPair<TKey, TValue>>();
	};
	bool Search(const TKey& key, TValue& value) const override
	{
		for (auto it = values.begin(); it != values.end(); it++)
		{
			auto elem = *it;
			if (elem.key == key)
			{
				value = elem.value;
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
		values.Add(TPair<TKey, TValue>(key, value));
	}
	void Add(const TPair<TKey, TValue>& pair) override
	{
		this->Add(pair.key, pair.value);
	}
	void Remove(const TKey& key) override
	{
		for (auto it = values.begin(); it != values.end(); it++)
		{
			auto elem = *it;
			if (elem.key == key)
			{
				break;
			}
		}
		if (it != values.end())
			values.Remove(it);
	}
	~TUnorderedMapList() {

	}
};