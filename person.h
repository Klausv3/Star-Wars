#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#include<vector>

using namespace std;

enum class Planet{Kashyyyk, Coruscant, Corellia, Vulcan};
const vector<string> Heimatplanet_name{"Kashyyyk", "Coruscant", "Corellia", "Vulcan"};

class Person {
	string name;
	int erfahrung;
	Planet planet;
public:
	Person(string name, int erfahrung, Planet planet = Planet::Kashyyyk);
	bool make_expedition(Planet p);
	bool is_experienced() const;
	bool operator==(Person)const;
	ostream&  print(ostream& o)const;
};
ostream& operator<<(ostream& o, Person p1);


#endif
