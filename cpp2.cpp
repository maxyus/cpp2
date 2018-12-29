#include "pch.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;
void Next_month(int& lastmonthindex, const vector<int>& days, vector<vector<string>>& taskforday) 
{
	lastmonthindex++;
	if (lastmonthindex > 11) lastmonthindex = 0;
	vector<vector<string>> NewMonth = taskforday;
	int oldvec = taskforday.size();
	int newvec = days[lastmonthindex];
	taskforday.resize(newvec);
	const int e = newvec - 1;
	if (oldvec > newvec) 
	{
		for (newvec; oldvec > newvec; newvec++) 
		{
			taskforday[e].insert(end(taskforday[e]), begin(NewMonth[newvec]), end(NewMonth[newvec]));
		}
	}
	NewMonth.clear();
}
void Task_display(int day, const vector<vector<string>>& taskforday) 
{
	cout << taskforday[day - 1].size();
	for (auto i : taskforday[day - 1]) 
	{
		cout << " " << i;
	}
	cout << "\n";
}
void Remove(int day, vector<vector<string>>& taskforday, string& task) 
{
	for (int i = 0; i < taskforday[day - 1].size(); i++) 
	{
		if (taskforday[day - 1][i] == task) 
		{
			taskforday[day - 1].erase(taskforday[day - 1].begin() + i);
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int operationCount;
	cout << "Введите количество операций \n";
	cin >> operationCount;
	vector<int> daysOfMonths = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int count_days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<vector<string>> task_for_day;
	int index_of_month = 0;
	task_for_day.resize(daysOfMonths[index_of_month], {});
	for (int i = 0; operationCount > i; i++) 
	{
		string comand;
		int day;
		string task;
		string task1;
		cin >> comand;
		if (comand == "NEXT") 
		{
			Next_month(index_of_month, daysOfMonths, task_for_day);
		}
		else if (comand == "DUMP") 
		{
			cin >> day;
			if (day > count_days[index_of_month])
			{
				cout << "Такого дня нет в этом месяце \n";
			}
			else
			{
				Task_display(day, task_for_day);
			}
		}
		else if (comand == "ADD") 
		{
			cin >> day >> task;
			if (day > count_days[index_of_month])
			{
				cout << "Такого дня нет в этом месяце \n";
			}
			else
			{
				task_for_day[day - 1].push_back(task);
			}
		}
		else if (comand == "REMOVE") 
		{
			cin >> day >> task1;
			if (day > count_days[index_of_month])
			{
				cout << "Такого дня нет в этом месяце \n";
			}
			else
			{
				Remove(day, task_for_day, task1);
			}
		}
	}
	return 0;
}