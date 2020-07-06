#pragma once

#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
//using namespace std;
using std::string;
using std::map;
using std::set;
using std::vector;


class Graph;
class AdjList;
class CityNode {
public:
	CityNode(); //default constructor
	CityNode(int theID);
	//creates a CityNode with its ID theID
	
	CityNode(const CityNode &cn); //copy constructor
	CityNode* operator=(const CityNode *cn);
	
	int getID() { return ID; }
	string getName() { return name; }
	int getDistance() { return distance; }
	vector<string> getOwners() { return owners; }
	CityNode* getNext() { return next; }
	int getPrice(int i) {
		return price[i];
	}

	void addOwner(string name) {
		owners.push_back(name);
	}

	void setName(string theName) {
		name = theName;
	}
	//sets city's name theName

	void setDistance(int theDistance) {
		distance = theDistance;
	}
	const int price[3] = { 10, 15, 20 };

	void setOwners(string owner1) {
		owners.push_back(owner1);
	}
	
	~CityNode(); //destructor

	//must have forward declaration "class Graph;" to let the following work
	//the follow contain "Graph", which has not been declared yet without forward declaration
	friend class Graph;
	friend class AdjList;
	friend void addEdge(Graph*, string, string, int, const map<string, int>);
	friend void printGraph(Graph* graph);
	friend bool isConnected(Graph* graph);
	friend void removeEdge2(Graph* graph, int cityID);


private:
	string name;
	int ID;
	string region;	
	int distance; //distance away from a base city
	vector<string> owners;
	CityNode *next;

};

class AdjList {
public:
	AdjList(); //default constructor
	AdjList(const AdjList &al); //copy constructor
	AdjList& operator = (const AdjList &al);
	
	CityNode* getHead() { return head; }
	CityNode* getBase() { return base; }

	~AdjList(); //destructor


	//must have forward declaration "class Graph;" to let the following work
	friend class Graph;
	friend void createBaseCity(Graph *graph, const map<string, int> myMap);
	friend void addEdge(Graph *graph, string srcName, string destName, int distance, const map<string, int> myMap);
	friend void printGraph(Graph* graph);
	friend bool isConnected(Graph* graph);
	friend void removeEdge(Graph* graph, int cityID);
	friend void removeEdge2(Graph* graph, int cityID);

private:

	CityNode* base;
	//point to NULL at beginning, and will point to a base node in graph
	//This base node is a city, indicating what city is a base city of its adjacent cities

	CityNode* head;
	//pointer to head node of a node list
	//this node list stores all the adjacent cities of base city. 

};

class Graph {
public:
	Graph(); //default constructor
	Graph(int theSize);
	//creates a graph
	//in this graph, arr is pointing to a dynamic array of size theSize
	//each elements of arr is an AdjList
	//in each AdjList(arr[0], arr[1],...,arr[theSize-1]), its base and head point to NULL

	Graph(const Graph &g); //copy constructor
	//copy constructor

	~Graph(); //destructor
	
	int getSize() { return size; }
	int numOfCities(); //return the number of cities in the graph
	AdjList* getArr() { return arr; };
	Graph& operator = (const Graph& g);

	set<int> findAdjCities(int baseID) const;
	
	vector<int> shortestPath(int startID);
	//return a vector that stores all the shortest path distances to all cities from city #startID

	int lowestPathPrice(int cityID, string pName);
	//If player pName wants to buy city #cityID
	//returns the money player should pay for path between city #cityID and the player's nearest city

	friend void printGraph(Graph* graph);
	friend void addEdge(Graph *graph, string srcName, string destName, int distance, const map<string, int> myMap);
	friend void createBaseCity(Graph *graph, const map<string, int> myMap);
	friend bool isConnected(Graph* graph);
	friend void removeEdge(Graph* graph, int cityID);
	friend void removeEdge2(Graph* graph, int cityID);

private:
	int size;
	AdjList* arr;

};

class mapLoader {
public:
	//void Load(Graph* copy, int numOfplayer);
	//load map from text file 
	//returns number of players
};

void createBaseCity(Graph*, map<string, int>);
//creates a bunch of city nodes according to given city names
//each name correspond a city ID
//let the base in each arr element point to a city according to its ID
//e.g., base in arr[0] points to node city with ID 0, base in arr[1] points to city with ID 1...



void addEdge(Graph *graph, string srcName, string destName, int distance, const map<string, int> myMap);
//connects a city node with name scrName to another node with name destName

void printGraph(Graph*);
//prints each city with its adjacent cities in the graph


void findConnected(Graph* graph, set<int>& visited, int beginCityID);
//start from city #beginCityID, 
//find all connected cities in the graph 
//and store their IDs in visited

bool isConnected(Graph* graph);
//return true if the graph is a connected graph, false otherwise. 

bool isConnected2(Graph* graph, int beginCityID);
//start from city #beginCityID, return true if the graph is a connected graph 

void removeEdge(Graph*, int cityID);
//remove cityName's all adjacent cities list. 
//For example, city with ID cityID has adjacent city 1, 2 and 4
//after this function, it will not have any city in the list.


void removeEdge2(Graph*, int cityID);
// remove cityName in some other city's adjacent city list
// For example, some other city has adjacent cities : 1, 2, cityID, 4
// after this function, this other city only has city 1, 2, 4 as its adjacent cities.

void removeArea(Graph*, int areaNo);
// remove all cities in area areaNo



