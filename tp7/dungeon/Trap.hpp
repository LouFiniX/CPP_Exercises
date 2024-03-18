//
// Created by LouFi on 11/03/2024.
//

#pragma once

#include "Item.hpp"

class Trap : public Item{
private:
    bool _should_destroyed = false;
public:
    Trap(int width, int heigt);
    char get_representation() const override;
    void update() override;
    void interact_with(Entity &other) override;
};

