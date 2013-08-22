#include "Skill.h"


Skill::Skill(void)
{
	Name = "Default skill";
	Description = "Default descrption";
	Level = -1;
}

Skill::Skill(std::string name, std::string description, int level)
{
	Name = name;
	Description = description;
	Level = level;
}

Skill::~Skill(void)
{

}
	
std::string Skill::GetName()
{
	return Name;
}
	
std::string Skill::GetDescription()
{
	return Description;
}
	
int Skill::GetLevel()
{
	return Level;
}
	
void Skill::Display(std::ostream& outputStream)
{
	outputStream << Name
		<< " -- " << Description
		<< " [Lvl: " << Level
		<< "]" << std::endl;
}