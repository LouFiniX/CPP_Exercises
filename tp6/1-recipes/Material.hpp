#pragma once

#include <iostream>
#include <ostream>
#include <string>

class Material
{
private:
std::string _name;


public:
    Material(std::string name)
    : _name {std::move(name)}
    {
        std::cout << _name << " was created" << std::endl;
    }

    ~Material()
    {
        std::cout << _name << " was destroyed" << std::endl;
    }

    const std::string get_name() const{
        return _name;
    }

    // Affiche le nom d'un materiau.
    friend std::ostream& operator<<(std::ostream& stream, const Material& material) { 
        return stream << material._name << std::endl; 
        }
};
