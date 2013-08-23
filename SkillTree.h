#ifndef _SKILL_TREE
#define _SKILL_TREE
#include "Skill.h"
#include "Tree.h"
#include "SkillManage.h"
#include <memory>
class SkillTree : public Tree<Skill>
{
private:
	// Title of the object; used to idenify instances of SkillTree objects
	std::string Title;
	static char* SearchKey;
	static SkillManager PointedSkill;
protected:
	// Assistant methods

	static void DisplayAssistant(Skill&);
	void FindSkillAssistant(Skill&);

public:
	// Default constructor; typically not used
	SkillTree(void);

	// General constructor; creates SkillTree object with specified name
	SkillTree(std::string);

	// Destructor
	~SkillTree(void);

	// Adds a new Skill object with (name, description, and level) to a SkillTree object as a 
	// new root in a tree if there are no existing roots, or as a child of the existing root,
	// if roots already exist in the tree
	// @pre: none
	// @post: A new Skill object is added to the tree
	// @returns: True on successful addition to the SkillTree
	bool AddSkill(std::string, std::string, int);

	// Adds a new Skill object with (name, description, and level) to a SkillTree as a child of 
	// (,,,parent)
	// @pre: none
	// @post: A new Skill object is added to the SkillTree as a child of the specified root
	// @returns: True on successful addition to the SkillTree
	bool AddSkill(std::string, std::string, int, std::string);

	// Finds a Skill object by name in the SkillTree
	// @pre: The Name of a Skill object
	// @post: none
	// @returns: A pointer to the Skill object, or NULL if object is not found
	Skill* FindSkill(char*);

	// Displays the SkillTree on the ostream object requested
	// @pre: An ostream object
	// @post: SkillTree is printed to ostream object
	// @returns: None
	void Display(std::ostream&);

	static void GetEntry(Skill&);
	
};

#endif