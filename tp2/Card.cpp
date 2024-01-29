#include <string>
#include <iostream>
#include "Card.hpp"

Card::Card(unsigned int value, std::string color)
    : _value {value}
    ,_color {color}
    {}

void Card::print() const{
    std::string carte;
    switch (_value){
    case 11:
        std::cout << "Valet" << " de " << _color << std::endl;
        break;
    case 12:
        std::cout << "Dame" << " de " << _color << std::endl;
        break;
    case 13:
        std::cout << "Roi" << " de " << _color << std::endl;
        break;
    case 14:
        std::cout << "As" << " de " << _color << std::endl;
        break;
    default:
        std::cout << _value << " de " << _color << std::endl;
        break;
    }
    
}

bool Card::operator==(Card other) const{
    return _value == other._value;
}

bool Card::operator<(Card other) const{
    return _value < other._value;
}

