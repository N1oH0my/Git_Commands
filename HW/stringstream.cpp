#include <iostream>
#include <map>
#include <set>
#include <hash_map>
#include <hash_set>
#include <vector>
#include <list>
#include <algorithm>
//-------------------//
#include <fstream>
#include <string>
#include<sstream>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::list;
using std::map;
using std::set;


int main() {
	
	//cout << "----------------------------List---------------------------------\n";
	//list<int> L;
	//L.push_back(3);
	//L.push_back(1);
	//L.push_back(2);
	//L.pop_back();
	////L.pop_front();
	//L.erase(++L.begin());
	//list<int>::iterator Li = L.begin();
	//while (Li != L.end())
	//{
	//	cout << *Li << endl;	++Li;
	//}
	//cout << "----------------------------Vector---------------------------------\n";
	//vector<int> V;
	//V.push_back(2);
	//V.push_back(20);
	//V.push_back(70);
	//auto Vi = std::find(V.begin(), V.end(), 20);
	//if (Vi != V.end())
	//{
	//	cout << "Yes\n";
	//}
	//Vi = V.begin();
	//while (Vi != V.end())
	//{
	//	cout << *Vi << endl;	++Vi;
	//}
	//cout << "----------------------------Map---------------------------------\n";
	//map<int, std::string> M;
	//M.emplace(std::make_pair(3, "Triple"));
	//M.emplace(std::make_pair(3, "Triple2"));
	//if (M.find(2) == M.end())
	//	M.emplace(std::make_pair(2, "Double"));
	//auto Mi = M.begin();
	//while (Mi != M.end())
	//{
	//	cout << Mi->first << ' ' << Mi->second << endl;	++Mi;
	//}
	//cout << "----------------------------Hash_Map---------------------------------\n";
	//std::hash_map<int, std::string> HM;
	////HM.at(3); // info index 3
	////HM.at(10);
	//HM.emplace(std::make_pair(1, "single1"));
	//HM.emplace(std::make_pair(1, "single2"));
	//HM.emplace(std::make_pair(3, "3333"));
	//auto HMi = HM.begin();
	//while (HMi != HM.end())
	//{
	//	cout << HMi->first << ' ' << HMi->second << endl;	++HMi;
	//}

	//cout << "----------------------------Set---------------------------------\n";
	//set<int> S;
	//S.emplace(3);
	//S.insert(4);
	//set<int>::iterator Si = S.begin();
	//while (Si != S.end())
	//{
	//	cout << *Si << endl;	++Si;
	//}
	//cout << "----------------------------Hash_Set---------------------------------\n";
	//std::hash_set<int> HS;
	//HS.emplace(3);
	//HS.emplace(3);
	//HS.insert(4);
	//
	//std::hash_set<int>::iterator HSi = HS.begin();
	//while (HSi != HS.end())
	//{
	//	cout << *HSi << endl;	++HSi;
	//}
	cout<< "----------------------------------------------------------------------------------\n";
	std::fstream f = std::fstream("data.txt");
	std::string line;
	list<int> list_strs;
	int max = 0; int num_of_line = 1;
	while (std::getline(f, line))
	{
		std::stringstream ss(line);
		std::string word;
		set<char> S;

		int counter = 0;
		while (ss >> word) {
			int size_of_word = word.length();
			for (size_t i = 0; i < size_of_word; ++i)
				S.insert(word[i]);
			if (S.size() != size_of_word)
				++counter;
		}
		if (counter >max)
		{
			max = counter;
			list_strs.clear();
			list_strs.push_back(num_of_line);
		}
		else if(counter == max && max!=0)
		{
			list_strs.push_back(num_of_line);
		}
		++num_of_line;
	}
	for (auto i = list_strs.begin(); i != list_strs.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;
	cin.get();
	return 0;
}