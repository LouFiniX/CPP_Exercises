#include <iostream>
#include <vector>
#include <sstream>
#include "Person.hpp"

int main(int argc, char const *argv[])
{
    std::vector<Person> P;
    int nb_person;

    std::cout << "Combien de personne ?" << std::endl;
    std::cin >> nb_person;

    for (int i = 0; i < nb_person; i++){
        std::string first_name;
        std::string surname;

        std::cout << "Prenom: ";
        std::cin >> first_name;
        std::cout << "Nom: ";
        std::cin >> surname;
        P.emplace_back(Person {first_name, surname});
    }


    std::stringstream builder;
    builder << "Les personne sont";
    for (auto p:P){
        builder << " " << p.get_first_name() << " " << p.get_surname();
    }
    std::cout << builder.str() << std::endl;

    return 0;
}
