// wall.cpp
// Implementation file for the wall class
// Contains the actual code for all member functions

#include "wall.h"
#include <cstdlib>  // For rand() function

// Constructor implementation
wall::wall(std::string playerName) {
    name = playerName;
    position = 0;  // Start at ground level
}

// Accessor for climber's name
std::string wall::getname() const {
    return name;
}

// Accessor for current position
int wall::getposition() const {
    return position;
}

// Climb function - move up 1-3 feet
void wall::climb() {
    int climbAmount = (rand() % 3) + 1;  // Random number 1-3
    position += climbAmount;
    
    // Prevent climbing above top of wall (since the constant is 20 feet)
    if (position > 20) {
        position = 20;
    }
}

// Drop function - move down 1-3 feet
void wall::drop() {
    int dropAmount = (rand() % 3) + 1;  // Random number 1-3
    position -= dropAmount;
    
    // Prevent falling below ground level (0 feet)
    if (position < 0) {
        position = 0;
    }
}
