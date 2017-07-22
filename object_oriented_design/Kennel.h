#ifndef KENNEL_H
#define KENNEL_H

#include <string>
#include "Animals.h"

class Kennel
{
    std::vector<Animal*> v;
public:
    Kennel();
    ~Kennel();
    void AddCat(const std::string & name);
    void AddDog(const std::string & name);
    void RollCall();
};

#endif
