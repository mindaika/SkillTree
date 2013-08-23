#pragma once
#include "Skill.h"
class SkillManager
{
public:
	SkillManager(Skill* thing) : m_thing( thing ) {	}
	~SkillManager()	{ delete m_thing; }
	void SkillSet(Skill* object) { m_thing = object; }
	Skill* instance() const { return m_thing; }
	void Kill() 
	{
		if (!(m_thing == nullptr))
		delete m_thing;
		m_thing = nullptr;
	}	
private:
	Skill* m_thing;
};

