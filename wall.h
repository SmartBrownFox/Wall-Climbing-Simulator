// wall.h
// Header file for the wall class
// Defines the interface for climbers in the wall climbing competition

#ifndef WALL_H
#define WALL_H

#include <string>

class wall {
private:
	std::string name;    // Name of the climber
	int position;        // Current position on the wall (0-20 feet)

public:
	// For ensuring that the wall actually stays constant due to funky reasons in my code, I challenge u to figure out!
	// Lines 18-21 are genuinely unneeded, but I think there's a certain case that might cause this branch errors. Get rid of it if needed :3
  wall(const wall &) = default;
  wall(wall &&) = default;
  wall &operator=(const wall &) = default;
  wall &operator=(wall &&) = default;
  
  // Constructor - accepts player name, initializes position to 0
  wall(std::string playerName);

  // Accessor functions
  std::string getname() const; // Returns climber's name
  int getposition() const;     // Returns current position

  // Member functions for climbing mechanics
  void climb(); // Moves climber up 1-3 feet (max 20)
  void drop();  // Moves climber down 1-3 feet (min 0)
};

#endif
