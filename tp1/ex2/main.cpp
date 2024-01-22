#include <iostream>
#include "Person.hpp"

int main(int argc, char const *argv[])
{
    Person p {"Palluche", "La Falluche"};
    
    std::cout << "La personne s'appelle " << p.get_first_name() << " " << p.get_surname() << std::endl;
    return 0;
}
