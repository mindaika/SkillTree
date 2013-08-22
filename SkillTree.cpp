#include "SkillTree.h"
#include <functional>
char* SkillTree::SearchKey = { 0 };
Skill SkillTree::SkillPointer;


SkillTree::SkillTree(void) : Title("Default title")
{	
	int* Leaker = new int;
}


SkillTree::SkillTree(std::string title) : Title(title)
{
}


SkillTree::~SkillTree(void)
{
}

bool SkillTree::AddSkill(std::string name, std::string description, int level)
{
	// Huh. Auto pointers work exactly as described. AMAZING.
	std::auto_ptr<Skill> NewSkill( new Skill(name, description, level) );
	return Add(*NewSkill);
}
	
bool SkillTree::AddSkill(std::string name, std::string description, int level, std::string parentName)
{
	std::auto_ptr<Skill> NewSkill( new Skill(name, description, level) );
	return(AddChild(*NewSkill, parentName));
}
	
Skill* SkillTree::FindSkill(char* name)
{
	SearchKey = name;
	InorderTraverse(GetEntry);
	return &SkillPointer;
}

void SkillTree::GetEntry(Skill& skillObject)
{
	if (!(strcmp(skillObject.GetName().c_str(),"Reading"))) {
		SkillPointer = skillObject;
	}
}

void SkillTree::FindSkillAssistant(Skill& target)
{
}

void SkillTree::Display(std::ostream& printTarget)
{
	
	printTarget << "Skill Tree: " << Title << std::endl;
	if ( IsEmpty() ) {
		printTarget << "  Empty" << std::endl;
	} else {
		PreorderTraverse(DisplayAssistant);		
	}
}

void SkillTree::DisplayAssistant(Skill& target)
{
	std::cout << target.GetName() 
		<< " -- " << target.GetDescription()
		<< " [Lvl: " << target.GetLevel()
		<< "]" << std::endl;
}
