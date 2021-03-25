#ifndef SKILL_H
#define SKILL_H

#include <iostream>
#include <cstring>
#define MaxSkillElements 5

using namespace std;

class Skill{
    private:
        string namaSkill;
        string *skillElements;
        int basePower;
        int masteryLevel;
        int numSkill;

    public:
        Skill();
        Skill(string, int, int);
        Skill(const Skill&);
        Skill& operator=(const Skill&);
        ~Skill();
        
        string getNamaSkill() const;
        string& getSkillElements();
        int getBasePower();
        int getMasteryLevel();
        void setNamaSkill(string);
        void addSkillElements(string);
        void setBasePower(int);
        void addMasteryLevel(int);
        bool operator<(const Skill&) const;
        bool operator>(const Skill&) const;
        bool operator==(const Skill&) const;
        bool canUsedBy(string);
        friend ostream& operator<<(ostream&, const Skill&);
};

#endif
