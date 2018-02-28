// RyanPractice2.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

const vector<string> rewardName = {"potion", "sword", "bow", "arrow"};
const vector<int> rewardRate = { 10, 30, 30, 30 };

vector<string> rewardPool;
vector<string> inventory;

void initRewardPool()
{
	cout << "Init Reward Pool" << endl;
	int size = rewardName.size();
	for (int i = 0; i < size; ++i)
	{
		rewardPool.insert(rewardPool.end(), rewardRate[i], rewardName[i]);
	}
	vector<string>::iterator str_ite;
	cout << "Pool:\n";
	for (str_ite = rewardPool.begin(); str_ite != rewardPool.end(); ++str_ite)
	{
		cout << *str_ite << " ";
	}
	cout << "\n" << endl;

	return;
}

string DrawReward()
{
	int index = rand() % rewardPool.size();
	return rewardPool[index];
}

int main()
{
	initRewardPool();
	srand(time(NULL));
	while (true)
	{
		string cmd;
		string drawResult;
		cout << "Enter 'draw' or 'exit' :" << endl;
		cin >> cmd;
		if (cmd == "draw")
		{
			drawResult = DrawReward();
			cout << "You Got " << drawResult << "\n" << endl;
			inventory.push_back(drawResult);
		}
		else if (cmd == "exit")
		{
			break;
		}
	}

	cout << "Your Inventory :\n";

	int invSize = inventory.size();
	for (int i = 0; i < invSize; ++i)
	{
		cout << inventory[i] << ",";
	}

	cout << "\n" << endl;

	system("pause");
    return 0;
}


