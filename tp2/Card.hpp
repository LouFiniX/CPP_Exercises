#pragma once
#include <string>

class Card{
    private:

    unsigned int _value;
    std::string _color;

    public:
    
    Card(unsigned int value, std::string color);
    void print() const;
    bool operator==(Card other) const;
    bool operator<(Card other) const;
    friend std::ostream& operator<<(std::ostream& stream, Card card);



};