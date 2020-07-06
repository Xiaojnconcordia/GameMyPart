//
// Created by Tyler on 2019-02-25.
//

#include "House.h"

House::House (){}

House::House(std::string &color): m_color(color){
};

void House::printInfo(){
    std::cout<<"All "<< m_color<<" houses loaded."<<std::endl;
}

