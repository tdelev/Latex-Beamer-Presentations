#include <iostream>
#include <cstring>
using namespace std;
class Person {
private:
	char name[50];
	int age;
	bool isMale;

public:
	Person(char *n, int a, bool m) {
		strcpy(name, n);
		age = a;
		isMale = m;
	}
	char * getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	bool gender() {
		return isMale;
	}
};

class Employee {
private:
	char employer[50];
	double wage;

public:
	Employee(char *e, double w) {
		strcpy(employer, e);
		wage = w;
	}

	char* getEmployer() {
		return employer;
	}
	double getWage() {
		return wage;
	}
};
class Teacher: public Person, public Employee {
private:
	int numCourses;

public:
	Teacher(char *n, int a, bool m, char *e, double w, int c) :
		Person(n, a, m), Employee(e, w) {
		numCourses = c;
	}
	int getCourses() {
		return numCourses;
	}
	;
};
int main() {
	Teacher t("Stojan Stojanov", 45, true, "Fakultet", 30000, 3);
	cout << "Nastavnik: " << t.getName() << "\nFakultet: " << t.getEmployer()
			<< "\nPlata: " << t.getWage() << "\nBroj na predmeti: "
			<< t.getCourses();
	return 0;
}
