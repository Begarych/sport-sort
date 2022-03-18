#pragma once

#include"Player.h"
#include <vector>

class Players
{
public:

	enum SortBy
	{
		Name=0,
		Family,
		SecondName,
		Age,
		Weight,
		Height,
		Number
	};

	void ReadFromFile(const std::wstring& fname);
	void SaveToFile( const std::wstring& fname);

	void Erase(int i);

	void Sort(SortBy sort);

	const std::vector<Player>& GetPlayers();
	void SetPlayers(const std::vector<Player>& p);	
private:
	std::vector<Player> players;

};
