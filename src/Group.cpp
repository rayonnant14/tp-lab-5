#include "Header.h"
Group::Group(string _title)
{
	title = _title;
}
void Group::addStudent(Student* student) 
{
	student->group = this;
	students.push_back(student);
	num++;
}
void Group::choiseHead(Student* student)
{
	head = student;
}
Student* Group::search(int _id, string _fio) 
{
	for (Student* i : students) {
		if (((i->id) == _id) && ((i->fio) == _fio))
			return i;
	}
	return nullptr;
}

double Group::groupAverage() 
{
	double average = 0;
	for (Student* i : students)
	{
		i->average();
		average += i->averageMark;
	}
	average = average / num;

	return average;
}
void Group::elimination(Student* student) 
{
	for (int i = 0; i < num; i++) {
		if (student == students[i]) {
			students.erase(students.begin() + i);
			break;
		}
	}
	student->group = nullptr;
	num--;
}