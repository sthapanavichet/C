// Name: Sthapanavichet Long 
// Student ID: 1375802215
// email: slong17@myseneca.ca
#include <random>
#include "Player.h"
#include <iostream>
using namespace std;
Player::Player() { // default constructor
    name = "\0";
    money = 0;
    cards = nullptr;
    numCards = 0;
}

Player::Player(string _name) { // constructor 
    name = _name;
    money = 1000;
    cards = nullptr;
    numCards = 0;
}

string Player::GetName() {
    return name;
}

void Player::DrawCards(int num) {
    if(cards != nullptr) {
        delete []cards;
        cards = nullptr;
    }
    numCards = num;
    cards = new int[numCards];
    for(int i = 0; i < numCards; i++) {
        cards[i] = (rand()%10)+1; // random numebrs for each card
    }
}

void Player::StealCards(Player& player) {
    if(this->cards != player.cards) {
        delete []this->cards; // deallocate current player card
        this->cards = player.cards; // stealing other player card
        this->numCards = player.numCards;
        player.cards = nullptr; // setting the stolen player to nullptr for fail safe
    }
    else {
        cout << "Cannot steal from self";
    }
}

int Player::SumCards() {
    int sum = 0;
    for(int i = 0; i < numCards; i++) {
        sum += cards[i];
    }
    return sum;
}

bool Player::AddCash(int num) {
    money += num; // return false by default unless money is bigger than 0
    if(money > 0) return true;
    return false;
}

void Player::Report() {
    cout << name << " has $" << money << " left over." << endl; // ouutput
}

