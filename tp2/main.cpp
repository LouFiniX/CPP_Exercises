#include <iostream>
#include "Card.hpp"
#include "Player.hpp"

#define NB_TOUR 16

int main(int argc, char const *argv[]){
    const Card c1 { 8, "Pique" };
    std::cout << c1;

    const Card c2 { 8, "Carreau" };
    std::cout << (c2 == c1) << std::endl; // -> 1
    const Card c3 { 10, "Carreau" };
    std::cout << (c2 == c3) << std::endl; // -> 0 

    std::cout << (c1 < c2) << std::endl; // -> 0
    std::cout << (c1 < c3) << std::endl; // -> 1
    std::cout << (c3 < c1) << std::endl; // -> 0

    Player p1 { "Gerald" };
    Player p2 { "Julien" };
    Player::deal_all_cards(p1, p2);

    for (auto i = 0; i < 16; ++i)
    {
        p1[i].print();
        std::cout << std::endl;
        p2[i].print();
        std::cout << std::endl;
    }

    while(!Player::play(p1, p2)){
    }
    std::cout << "Score de p1 " << p1.get_score() << std::endl;
    std::cout << "Score de p2 " << p2.get_score() << std::endl;

    return 0;
}
