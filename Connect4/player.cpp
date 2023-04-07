#include "player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player(const string Name, const string Token)
    : name(Name), token(Token) {}

// Getters
const string Player::getName() { return name; }
const string Player::getToken() { return token; }



