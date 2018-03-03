#pragma once
#ifndef CHEST_H
#define CHEST_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class ChestBase
{
public:
	virtual bool CheckCost(map<int, int> const wallet) = 0;
	virtual bool TakeCost(map<int, int> &wallet) = 0;
	string Draw();
	ChestBase(vector<string>, vector<int>);
private:
	vector<string> _rewardPool;
	vector<string> _rewardName;
	vector<int> _rewardRate;
};

ChestBase::ChestBase(vector<string> rewardName, vector<int> rewardRate)
{
	cout << "Init Reward Pool:\n" << endl;
	int size = rewardName.size();
	for (int i = 0; i < size; ++i)
	{
		_rewardPool.insert(_rewardPool.end(), rewardRate[i], rewardName[i]);
	}
	vector<string>::iterator str_ite;
	for (str_ite = _rewardPool.begin(); str_ite != _rewardPool.end(); ++str_ite)
	{
		cout << *str_ite << " ";
	}
	cout << "\n" << endl;

	return;
}

string ChestBase::Draw()
{
	int index = rand() % _rewardPool.size();
	return _rewardPool[index];
}

class DiamonChest : public ChestBase
{
public:
	bool CheckCost(map<int, int> const wallet)
	{
		return true;
	};
	bool TakeCost(map<int, int> &wallet)
	{
		map<int, int>::iterator mapIte = wallet.find(0);
		if (mapIte == wallet.end())
		{
			return false;
		}
		if (mapIte->second < 100)
		{
			return false;
		}
		mapIte->second -= 100;
		return true;
	}

	DiamonChest(vector<string> rewardName, vector<int> rewardRate) : ChestBase(rewardName, rewardRate)
	{
	}
};

class TimeChest : public ChestBase
{
public:
	bool CheckCost(map<int, int> const wallet)
	{
		return true;
	};

	bool TakeCost(map<int, int> &wallet)
	{
		return true;
	};

	TimeChest(vector<string> rewardName, vector<int> rewardRate) : ChestBase(rewardName, rewardRate)
	{}
};

#endif // !CHEST_H
