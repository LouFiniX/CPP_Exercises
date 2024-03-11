//
// Created by LouFi on 11/03/2024.
//

#pragma once

#include <iostream>
#include "Entity.hpp"

class Character : public Entity{
private:
    char _repr = '0';
public:
    Character(int x , int y);
    ~Character(){
        std::cout << "Character has destroyed" << std::endl;
    }
    char get_representation() const override;
    void interact_with(Entity &other) override;
    bool should_destroy() override;

};


