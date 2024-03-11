//
// Created by LouFi on 11/03/2024.
//

#include "Potion.hpp"

Potion::Potion(int width, int heigt)
: Item(width, heigt)
{
}

char Potion::get_representation() const {
    return '$';
}

void Potion::update() {
}
