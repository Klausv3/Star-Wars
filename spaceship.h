#ifndef SPACESHIP_H
#include<iostream>
#include<string>
#include<vector>
#include"person.h"

using namespace std;

class Spaceship{
	string bezeichnung;
	vector<Person>crewliste;
	Planet splanet;
public:
	Spaceship(string bezeichnung, vector<Person>crewliste, Planet splanet = Planet::Corellia);
	bool hire(const Person&);
	ostream& print(ostream& a)const;
};
ostream& operator<<(ostream& a, Spaceship s1);




#endif
