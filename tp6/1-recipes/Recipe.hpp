#pragma once

#include <iostream>
#include <ostream>
#include <vector>
#include <string>

class Recipe
{
private:
    std::vector<std::string> _materials;
    std::vector<std::string> _products;
    size_t _id;

public:

    Recipe(std::vector<std::string> materials, std::vector<std::string> products, size_t id)
    : _materials {std::move(materials)},
    _products {std::move(products)},
    _id {id}
    {
    }

    const std::vector<std::string>& get_materials() const{
        return _materials;
    }

    const std::vector<std::string>& get_product() const{
        return _products;
    }

    // Affiche l'identifiant et la formule d'une recette.
    friend std::ostream& operator<<(std::ostream& stream, const Recipe& recipe)
    { 
        stream << "(" << recipe._id << ") ";
        for (const auto& material:recipe._materials){
            stream << " " << material;
        }
        stream << " =>";
        for (const auto& product:recipe._products){
            stream << " " << product;
        }
        return stream << std::endl;
    }
};
