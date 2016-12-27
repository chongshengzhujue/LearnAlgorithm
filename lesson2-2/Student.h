#ifndef _STUDENTS_H_
#define _STUDENTS_H_

#include <iostream>
#include <algorithm>

struct Students
{
	std::string name;
	int score;

	bool operator< (const Students& otherStu)
	{
		return otherStu.score != score ? score < otherStu.score : name < otherStu.name;
	}

	friend std::ostream& operator<<(std::ostream &os, const Students &student)
	{
		return std::cout << "Students: " << student.name.c_str() << "  " << student.score << std::endl;
	}
};

#endif