#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <iostream>

using namespace std;

class Student {
	int fnum;
	char name[41];
	double mark;
public:
	Student()
	{

	}
	Student(const Student &old)
	{
		fnum = old.fnum;
		strcpy_s(name, old.name);
		mark = old.mark;
	}
	int GetFnum() {
		return fnum;
	}
	void SetFnum(int fnum)
	{
		this->fnum = fnum;
	}
	char* GetName()
	{
		return name;
	}
	void SetName(char* name) {
		strcpy_s(this->name, name);
	}
	double GetMark()
	{
		return this->mark;
	}
	void SetMark(double mark)
	{
		this->mark = mark;
	}
	void Print() {
		cout << this->name << endl;
		cout << this->fnum << endl;
		cout << this->mark << endl;
	}
};

class Group {
	Student students[30];
	int countOfStudents;
public:
	Group()
	{
		this->countOfStudents = 0;
	}

	void AddStudent(Student *student)
	{
		if (countOfStudents < 30)
		{
			students[countOfStudents] = *student;
			countOfStudents++;
		}
	}

	double CalculateAverageMark()
	{
		double sum = 0;
		for (size_t i = 0; i < countOfStudents; i++)
		{
			sum += students[i].GetMark();
		}
		return sum / countOfStudents;
	}

	Student* GetStudentWithLowestMark()
	{
		int index = 0;
		double min = students[0].GetMark();
		for (int i = 1; i < countOfStudents; i++)
		{
			if (students[i].GetMark() < min)
			{
				index = i;
				min = students[i].GetMark();
			}
		}
		return &students[index];
	}

	Student* GetStudentWithHighestMark()
	{
		int index = 0;
		double max = students[0].GetMark();
		for (int i = 1; i < countOfStudents; i++)
		{
			if (students[i].GetMark() > max)
			{
				index = i;
				max = students[i].GetMark();
			}
		}
		return &students[index];
	}

	Student* GetStudentByFnum(int fnum)
	{
		for (int i = 0; i < countOfStudents; i++)
		{
			if (students[i].GetFnum() == fnum)
			{
				return &students[i];
			}
		}
		return NULL;
	}

	void SortStudentsByFnum()
	{
		Student swap;
		for (int i = 0; i < countOfStudents - 1; i++)
			for (int j = 0; j < countOfStudents - i - 1; j++)
				if (students[j].GetFnum() > students[j+1].GetFnum())
				{
					swap = students[j];
					students[j] = students[j + 1];
					students[j + 1] = swap;
				}
	}

	void SortStudentsByMark()
	{
		Student swap;
		for (int i = 0; i < countOfStudents - 1; i++)
			for (int j = 0; j < countOfStudents - i - 1; j++)
				if (students[j].GetMark() < students[j + 1].GetMark())
				{
					swap = students[j];
					students[j] = students[j + 1];
					students[j + 1] = swap;
				}
	}

	void Print()
	{
		for (int i = 0; i < countOfStudents; i++)
		{
			students[i].Print();
		}
	}
};

int main()
{
	Group _41A;
	Student KP;
	KP.SetFnum(370805);
	KP.SetMark(6);
	char name[] = "Kiril";
	KP.SetName(name);
	_41A.AddStudent(&KP);

	Student AO;
	AO.SetFnum(370777);
	AO.SetMark(5);
	char name2[] = "Alex";
	AO.SetName(name2);
	_41A.AddStudent(&AO);

	Student GP;
	GP.SetFnum(370888);
	GP.SetMark(5.5);
	char name3[] = "Joro";
	GP.SetName(name3);
	_41A.AddStudent(&GP);

	cout << "Uspeh: " << _41A.CalculateAverageMark() << endl;
	_41A.GetStudentWithHighestMark()->Print();
	_41A.SortStudentsByFnum();
	_41A.Print();
}