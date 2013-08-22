#ifndef _SKILL
#define _SKILL
#include <iostream>
#include <string>
class Skill
{
private:
	// Descriptive name of the Skill
	std::string Name;

	// A text description of the Skill object, detailing the function of the Skill
	std::string Description;

	// An integer level of the Skill, used to determine ordering
	int Level;

public:
	
	// Default constructor; typically not used
	Skill(void);

	// General constructor, used to create a skill with a Name, Description and Level
	Skill(std::string, std::string, int);

	// Destructor
	~Skill(void);

	// Returns the name of a Skill object
	std::string GetName();

	// Returns the text description of a Skill object
	std::string GetDescription();

	// Returns the level of a Skill object
	int GetLevel();

	// Takes in an ostream object and prints output to that stream; 
	// I only know of one "ostream" object though, but I guess maybe you 
	// might want to display stuff to cerr or something? Who am I to judge?
	void Display(std::ostream&);
};
#endif