//
// Created by Tyler on 2019-02-25.
//
#include <iostream>
#include <string>

#ifndef PROJECT345_HOUSE_H
#define PROJECT345_HOUSE_H

class House{

public:
	//default constructor
    House ();
	//set colour
    House(std::string &color);

    void printInfo();
	std::string getColor() { return m_color; }

private:
    std::string m_color;



};

#endif //PROJECT345_HOUSE_H
