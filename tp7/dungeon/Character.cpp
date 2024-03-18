//
// Created by LouFi on 11/03/2024.
//

#include "Character.hpp"
#include "Entity.hpp"
#include "Trap.hpp"
#include "Potion.hpp"

Character::Character(int x, int y)
    : Entity(x, y)
    {}

char Character::get_representation() const {
    return _repr;
}

void Character::interact_with(Entity &other) {
    const auto* trap = dynamic_cast<Trap*>(&other);
    if (trap != nullptr){
        switch (_repr) {
            case '0': _repr = 'o';
                break;
            case 'o': _repr = ' ';
                break;
            default:
                break;
        }
    }
    const auto* potion = dynamic_cast<Potion*>(&other);
    if (potion != nullptr){
        switch (_repr) {
            case 'o': _repr = '0';
                break;
            default:
                break;
        }
    }
}

bool Character::should_destroy() {
    return _repr == ' ';
}
