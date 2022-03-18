#include "stdafx.h"
#include "Form1.h"

Players data;
const std::wstring fname(L"Sportsmen.txt");

System::Void Form1::closeButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	this->Close();
}

System::Void Form1::loadButton_Click(System::Object^  sender, System::EventArgs^  e) 
{
	data.ReadFromFile(fname);
	SetUIData(data.GetPlayers());
}

void Form1::SetUIData(const std::vector<Player>& players)
{
	dataGridView1->Rows->Clear();
	dataGridView1->ReadOnly = false; //Before modifying, it is required.

	for (auto i = 0; i < players.size(); i++)
	{
		dataGridView1->Rows->Add();
		dataGridView1->Rows[i]->Cells[0]->Value = gcnew String(players[i].family.c_str());
		dataGridView1->Rows[i]->Cells[1]->Value = gcnew String(players[i].name.c_str());
		dataGridView1->Rows[i]->Cells[2]->Value = gcnew String(players[i].second__name.c_str());
		dataGridView1->Rows[i]->Cells[3]->Value = players[i].age.ToString();
		dataGridView1->Rows[i]->Cells[4]->Value = players[i].weight.ToString();
		dataGridView1->Rows[i]->Cells[5]->Value = players[i].height.ToString();
		dataGridView1->Rows[i]->Cells[6]->Value = players[i].number.ToString();
	}


}

std::vector<Player> Form1::GetUIData()
{
	std::vector<Player> players;

	int n = dataGridView1->Rows->Count;
	for (auto i = 0; i < n - 1 /*последняя строка пустая, поэтому n-1*/; i++)
	{
		Player p;
		
		try { p.family = msclr::interop::marshal_as<std::wstring>(dataGridView1->Rows[i]->Cells[0]->Value->ToString()); }catch (...) {}
		try { p.name = msclr::interop::marshal_as<std::wstring>(dataGridView1->Rows[i]->Cells[1]->Value->ToString()); }catch (...) {}
		try { p.second__name = msclr::interop::marshal_as<std::wstring>(dataGridView1->Rows[i]->Cells[2]->Value->ToString()); }catch (...) {}
		try { p.age = int::Parse(dataGridView1->Rows[i]->Cells[3]->Value->ToString()); }catch (...) {}
		try { p.weight = int::Parse(dataGridView1->Rows[i]->Cells[4]->Value->ToString()); }catch (...) {}
		try { p.height = int::Parse(dataGridView1->Rows[i]->Cells[5]->Value->ToString()); }catch (...) {}
		try { p.number = int::Parse(dataGridView1->Rows[i]->Cells[6]->Value->ToString()); }catch (...) {}

		players.push_back(p);
	}

	return players;

}

System::Void Form1::saveButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	try
	{
		data.SetPlayers(GetUIData());
		data.SaveToFile(fname);
	}
	catch (...)
	{
		MessageBox::Show(L"Ошибка при сохранении файла", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

System::Void Form1::searchButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	try
	{

		const std::vector<Player>& players = data.GetPlayers();
		std::wstring family = msclr::interop::marshal_as<std::wstring>(this->familyTextBox->Text);
		std::wstring name = msclr::interop::marshal_as<std::wstring>(this->nameTextBox->Text);
		std::wstring second__name = msclr::interop::marshal_as<std::wstring>(this->secondNameTextBox->Text);

		//очистить selection
		for (auto i = 0; i < dataGridView1->Rows->Count; i++)
		{
			dataGridView1->Rows[i]->Selected = false;
		}

		if (!family.empty() || !name.empty() || !second__name.empty()) // есть смысл искать, только если хоть где-то не пусто
		{

			bool found = false;
			for (auto i = 0; i < players.size(); i++)
			{
				Player p = players[i];

				if (!family.empty())
					if (p.family != family)
						continue;

				if (!name.empty())
					if (p.name != name)
						continue;

				if (!second__name.empty())
					if (p.second__name != second__name)
						continue;

				//если дошли до этого места, значит p - это то, что мы ищем
				dataGridView1->Rows[i]->Selected = true;
				found = true;
				//break;  

			}

			if (!found)
			{
				MessageBox::Show(L"Ничего не найдено", L"Поиск", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}



	}
	catch (...)
	{
		MessageBox::Show(L"Критическая ошибка", L"Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Stop);
	}
}

System::Void Form1::deleteButton_Click(System::Object^  sender, System::EventArgs^  e) {
	auto n = this->dataGridView1->SelectedRows->Count;
	if (n == 0)
	{
		MessageBox::Show(L"Строки не выбраны", L"Удалить", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else
	{
		try
		{
			data.SetPlayers(GetUIData());
			for (int i = dataGridView1->Rows->Count - 1; i >= 0; i--)
			{
				if (dataGridView1->Rows[i]->Selected)
					data.Erase(i);
			}
			SetUIData(data.GetPlayers());
		}
		catch (...)
		{
			MessageBox::Show(L"Ошибка при удалении", L"Удалить", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

System::Void Form1::sortButton_Click(System::Object^  sender, System::EventArgs^  e)
{
	int idx = sortComboBox->SelectedIndex;

	if (idx == -1 )
	{
		// если ничего не выбрано, то idx == -1
		// Players::SortBy::COUNT - количество типов в enum Players::SortBy
		MessageBox::Show(L"Не правильный тип сортировки", L"Сортировать", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else
	{
		data.SetPlayers(GetUIData());
		Players::SortBy sortType = (Players::SortBy)idx;
		data.Sort(sortType);
		SetUIData(data.GetPlayers());
	}
}

