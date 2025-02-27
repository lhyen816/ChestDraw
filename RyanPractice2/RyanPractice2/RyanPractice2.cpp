// RyanPractice2.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#include <map>
#include "Chest.h"

using namespace std;

const vector<string> rewardName = {"potion", "sword", "bow", "arrow"};
const vector<int> rewardRate = { 10, 30, 30, 30 };

vector<string> _inventory;

vector<ChestBase*> _allChest;

map<int, int> _wallet = { {0, 100}, {1, 1000} };

void InitChestPool()
{
	cout << "Start to InitChestPool" << endl;
	TimeChest *timeChest = new TimeChest(rewardName, rewardRate);
	_allChest.push_back(timeChest);

	// TODO : Add more ChestType
	DiamonChest *diamondChest = new DiamonChest(rewardName, rewardRate);
	_allChest.push_back(diamondChest);
}

int main()
{
	//vector<ChestBase*> allChest;
	InitChestPool();

	srand(time(NULL));

	/*cout << "Start to InitChestPool" << endl;
	TimeChest timeChest(rewardName, rewardRate);
	allChest.push_back(&timeChest);

	// TODO : Add more ChestType
	DiamonChest diamondChest(rewardName, rewardRate);
	allChest.push_back(&diamondChest);*/

	while (true)
	{
		string cmd;
		string drawResult;
		cout << "Enter '0'~'1' to Draw OR Enter '99' to exit :" << endl;
		cin >> cmd;
		bool exitFlag = false;
		unsigned int cmdInt = atoi(cmd.c_str());
		switch (cmdInt)
		{
		case 0:
		case 1:
			if (_allChest.size() > cmdInt)
			{
				if (_allChest[cmdInt]->TakeCost(_wallet))
				{
					string drawResult = _allChest[cmdInt]->Draw();
					cout << "You Got " << drawResult << "\n" << endl;
					_inventory.push_back(drawResult);
					break;
				}
				else
				{
					cout << "Take Cost Failed..." << endl;
				}
			}
			cout << "You Got Nothing! Try Again" << endl;
			break;
		case 99:
			exitFlag = true;
			break;
		default:
			cout << "Wrong Param...\n" << endl;
			break;
		}

		if (exitFlag)
		{
			break;
		}
	}

	cout << "Your Inventory :\n";

	int invSize = _inventory.size();
	for (int i = 0; i < invSize; ++i)
	{
		cout << _inventory[i] << ",";
	}

	cout << "\n" << endl;

	system("pause");
    return 0;
}


