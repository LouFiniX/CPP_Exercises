#include <string>
#include <iostream>
#include "Card.hpp"

Card::Card(unsigned int value, std::string color)
    : _value {value}
    ,_color {color}
    {}

void Card::print(){
    std::cout << _value << " de " << _color << std::endl;
}