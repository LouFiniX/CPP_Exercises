//
// Created by LouFi on 11/03/2024.
//

#pragma once
#include "Entity.hpp"

class Item : public Entity{
public:
    Item(int width, int heigt)
    :Entity {random_value(0, width), random_value(0, heigt)}
    {
    }
    void update() override{};

};


