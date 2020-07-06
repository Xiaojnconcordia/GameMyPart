#ifndef POWERPLANT_H_
#define POWERPLANT_H_

#include <string>
#include <iostream>
#include <vector>
using namespace std;

class PowerPlant {

public:
//convert string to int
	enum Type{
		coal = 0, oil, garbage, uranium, hybrid, eco, step3, unknown
	};

private:
	int number;
	int need;
	Type type;
	int supplyCity;
	
public:
	PowerPlant();
	PowerPlant(int n, int s, Type t, int c);
	//set & get methods
	void setNumber(int n);
	int getNeed();
	int getNumber();
	int getSupplyCity();
	PowerPlant::Type getType();
	string getTypeName();
	//print step
	string toString();
	
	//shuffle method: change the order of cards
	static void shuffle(vector<PowerPlant>&);
	//rearrange the power plants in ascending order in the market
	static void setMarketOrder(vector<PowerPlant>&);
};


#endif