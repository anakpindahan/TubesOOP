#ifndef SKILL_H
#define SKILL_H

#include <iostream>

#define MaxSkillElements 5

using namespace std;

class Skill{
    private:
        string namaSkill;
        string *skillElements;
        int basePower;
        int masteryLevel;

    public:
        Skill();
        Skill(string, string&, int, int);
        Skill& operator=(const Skill&);
        ~Skill();
        
        string getNamaSkill();
        string& getSkillElements();
        int getBasePower();
        int getMasteryLevel();
        void setNamaSkill(string);
        void addSkillElements(string);
        void setBasePower(int);
        void addMasteryLevel(int);
        
        
};

#endif
