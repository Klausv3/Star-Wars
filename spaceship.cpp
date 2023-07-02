#include<iostream>
#include<string>
#include<vector>
#include"spaceship.h"

Spaceship::Spaceship(string bezeichnung, vector<Person>crewliste, Planet splanet) :bezeichnung{ bezeichnung }, crewliste{ crewliste }, splanet{ splanet } {
	
	int count{ 0 };
	if (crewliste.empty())
		throw runtime_error("no");
	else {
		for (size_t i{ 0 }; i < crewliste.size(); ++i) {
			count = 0;
			for (size_t j{ 0 }; j < crewliste.size(); ++j) {
				if (crewliste.at(j) == crewliste.at(i))
					count++;
			}
			if(count > 1)
				throw runtime_error("error 2");
		}
	}
	if (bezeichnung.empty())
		throw runtime_error("3");
}
bool Spaceship::hire(const Person& b) {
	int count{ 0 };
	for (const auto& a : crewliste)
		if (b == a)
			count++;
	
	if (count > 0)
		return false;
	else
		crewliste.push_back(b);
}
/*[Name, Crew: {Crewliste}, Planet]
erfolgen, z.B.: [Millennium Falcon, Crew: {[Han Solo: 100, Corellia], [Chewbacca: 99, Kashyyyk]}, Corellia]*/
ostream& Spaceship:: print(ostream& a)const{
	a << "[" << bezeichnung << ", Crew: {";
	for (size_t i{ 0 }; i < crewliste.size(); ++i) {
		a << crewliste.at(i);
		if (i < crewliste.size() - 1)
			a << ", ";
	}
	a << "}, " << Heimatplanet_name.at(static_cast<int>(splanet))<< "]";
	return a;

};
ostream& operator<<(ostream& a, Spaceship s1) {
	return s1.print(a);
}
