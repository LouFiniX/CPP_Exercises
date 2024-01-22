#include <iostream>
#include "Person.hpp"

int main(int argc, char const *argv[])
{
    Person p;
    p.first_name = "Palluche";
    p.surname = "La Falluche";
    
    std::cout << "La personne s'appelle " << p.first_name << " " << p.surname << std::endl;
    return 0;
}
