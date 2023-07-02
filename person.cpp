#include<iostream>
#include<string>
#include<vector>
#include"person.h"

using namespace std;


Person::Person(string name, int erfahrung, Planet planet) : name{ name }, erfahrung{ erfahrung }, planet{ planet } {
	if (name.empty())
		throw runtime_error("fehler 1");
	if (erfahrung < 0 || erfahrung > 100)
		throw runtime_error("fehler 2");

}	
bool Person::make_expedition(Planet p) {
	if (this->planet == p) {
		if (erfahrung + 2 > 100) {
			return erfahrung - 2;
		}
		else return erfahrung;
	}
	else{
		if (erfahrung + 5 > 100) {
			return erfahrung - 5;
		}
		else return erfahrung;
	}
}
bool Person::is_experienced() const {
	if (erfahrung > 75)
		return true;
	else return false;
}
bool Person:: operator==(Person a)const {
	if (this->name == a.name && this->erfahrung == a.erfahrung && this->planet == a.planet)
		return true;
	else return false;
}
// [Name: Erfahrungswert, Planet]
ostream& Person:: print(ostream& o)const{
	o << "[" << name << ": " << erfahrung << ", " << Heimatplanet_name.at(static_cast<int>(planet)) << "]";
	return o;
}
ostream& operator<<(ostream& o, Person p1) {
	return p1.print(o);
}

