#pragma once
#include <iostream>
#include <string>
using namespace std;
const string RED_TOKEN = "\033[1;31mO\033[0m";
const string BLUE_TOKEN = "\033[1;34mO\033[0m";

const string RED_PLAYER = "\033[1;31m1\033[0m";
const string BLUE_PLAYER = "\033[1;34m2\033[0m";

class Player {
private:
  string name;
  string token;

public:
  // Constructor
  Player(const string Name, const string Token);

  // Getters
  const string getName();
  const string getToken();

  // Take a turn
  int takeTurn();
};