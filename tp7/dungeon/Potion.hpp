//
// Created by LouFi on 11/03/2024.
//

#pragma once

#include "Entity.hpp"
#include "Item.hpp"

class Potion : public Item{
private:
public:
    Potion(int width, int heigt);
    char get_representation() const override;
    void update() override;
};


