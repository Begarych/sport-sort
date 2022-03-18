#include "stdafx.h"



#include "Players.h"


#include <fstream>
#include <string> 
#include <windows.h> 
#include <codecvt> // codecvt_utf8_utf16
#include <algorithm>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace System::Windows::Forms;



void Players::ReadFromFile(const wstring& fname) 
{

	try
	{
		wifstream f(fname);
		if (f.fail())
		{
			MessageBox::Show(L"Файл не найден", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			players.clear();
			f.imbue(locale(f.getloc(), new codecvt_utf8_utf16<wchar_t>()));
			while(!f.eof()){
				Player p;
				// прекращаем чтение файла в случае любой ошибки (break)
				if (!(f >> p.family)) break;
				if (!(f >> p.name)) break;
				if (!(f >> p.second__name)) break;
				if (!(f >> p.age)) break;
				if (!(f >> p.weight)) break;
				if (!(f >> p.height)) break;
				if (!(f >> p.number)) break;
				players.push_back(p);

			}
		}

	}
	catch(...)
	{

		MessageBox::Show(L"Информация в файл введена неверно", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}

}

void Players::SaveToFile(const wstring& fname)
{
	try
	{
		wofstream f(fname);
		if (f.fail())
		{
			MessageBox::Show(L"Файл не найден", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else
		{
			f.imbue(locale(f.getloc(), new codecvt_utf8_utf16<wchar_t>()));
			for (int i = 0; i < players.size(); i++) {
				Player& p = players[i];
				f << p.family.c_str() << L"  ";
				f << p.name.c_str() << L"  ";
				f << p.second__name.c_str() << L"  ";
				f << p.age << L"  ";
				f << p.weight << "  ";
				f << p.height << "  ";
				f << p.number << "\n";
				//if ( i < players.size()-1) 
				//	f << L"\n"; // после последней строки "\n" не нужен, иначе при чтении  
			}
		}

	}
	catch (...)
	{

		MessageBox::Show(L"Ошибка записи в файл", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);

	}


}
  
void Players::Erase(int i)
{
	players.erase( players.begin()+i);
}

const std::vector<Player>& Players::GetPlayers()
{
	return players;
}

void Players::SetPlayers(const std::vector<Player>& p)
{
	players = p;
}

void Players::Sort(SortBy sort)
{
	switch (sort)
	{
	case SortBy::Name :
		std::sort(players.begin(), players.end(), [](const Player& p1, const Player& p2)->bool {return p1.name < p2.name; });
		break;
	case SortBy::Family:
		std::sort(players.begin(), players.end(), [](Player& p1, Player& p2)->bool {return p1.family < p2.family; });
		break;
	case SortBy::SecondName:
		std::sort(players.begin(), players.end(), [](Player& p1, Player& p2)->bool {return p1.second__name < p2.second__name; });
		break;
	case SortBy::Age:
		std::sort(players.begin(), players.end(), [](Player& p1, Player& p2)->bool {return p1.age < p2.age; });
		break;
	case SortBy::Height:
		std::sort(players.begin(), players.end(), [](Player& p1, Player& p2)->bool {return p1.height < p2.height; });
		break;
	case SortBy::Weight:
		std::sort(players.begin(), players.end(), [](Player& p1, Player& p2)->bool {return p1.weight < p2.weight; });
		break;
	case SortBy::Number:
		std::sort(players.begin(), players.end(), [](Player p1, Player p2)->bool {return p1.number < p2.number; });
		break;
	}
}
