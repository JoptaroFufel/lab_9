#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <ctime>

namespace myNamespace {
	class Prods {
	private:
		int id;
		std::string name;
		double cost;
	public:
		Prods() :id(rand() % 100), name("Blank "), cost(0.0) { }
		Prods(std::string t_name, double t_cost, int id = 0) :id(rand() % 100) {
			if (t_cost < 0) cost = 0.;
			else cost = t_cost;
			name = t_name;
		}
		~Prods() { }
		bool operator< (const Prods& moto) { return cost < moto.cost; }
		bool operator== (const Prods& moto) { return cost == moto.cost && name == moto.name; }
		friend std::ostream& operator<< (std::ostream& out, const Prods& Motorbike)
		{
			out << Motorbike.id << ' ' << Motorbike.name << ' ' << Motorbike.cost << '\n'; return out;
		}

		std::string get_name() { return name; }
		double get_milleage() { return cost; }

	};
}
