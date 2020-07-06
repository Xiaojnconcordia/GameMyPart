#include "Resources.h"
Resources::Resources() {
	m_coal = 0;
	m_oil = 0;
	m_garbage = 0;
	m_uranium = 0;
	m_price = 0;
}
Resources::Resources(int c, int o, int g, int u, int p) : m_coal(c), m_oil(o), m_garbage(g), m_uranium(u), m_price(p)
{
	
}
//set method: change value
void Resources::setCoal(int c) {
	m_coal = c;
}
//set method: change value
void Resources::setOil(int o) {
	m_oil = o;
}
//set method: change value
void Resources::setGarbage(int g) {
	m_garbage = g;
}
//set method: change value
void Resources::setUranium(int u) {
	m_uranium = u;
}
//set method: change value
void Resources::setPrice(int p) {
	m_price = p;
}
//get method: get value
int Resources::getOil(void) {
	return m_oil;
}
//get method: get value
int Resources::getCoal(void) {
	return m_coal;
}
//get method: get value
int Resources::getGarbage(void) {
	return m_garbage;
}
//get method: get value
int Resources::getUranium(void) {
	return m_uranium;
}
//get method: get value
int Resources::getPrice(void) {
	return m_price;
}
//add method
void Resources::addCoal(int c){
	m_coal += c;
}

void Resources::addOil(int o){
	m_oil += o;
}
void Resources::addGarbage(int g){
	m_garbage += g;
}

void Resources::addUranium(int u){
	m_uranium += u;
}
// print the data of Resources
string Resources::toString() {
	string print =  "Cost: " + to_string(m_price) + " \t|| Coal: " + to_string(m_coal) + " || Oil: " + to_string(m_oil) + " || Garbage: " + to_string(m_garbage) + " || Uranium: " + to_string(m_uranium);
	return print;
}
