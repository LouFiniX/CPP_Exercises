//
// Created by LouFi on 11/03/2024.
//

#include "Trap.hpp"
#include "Random.hpp"
#include "Character.hpp"

Trap::Trap(int width, int heigt)
: Item {width, heigt}
{
}

void Trap::update() {
}

char Trap::get_representation() const {
    return 'x';
}

void Trap::interact_with(Entity &other) {
    const auto* character = dynamic_cast<Character*>(&other);
    if (character != nullptr){
        _should_destroyed = true;
    }
}
