#ifndef KENNEL_CPP
#define KENNEL_CPP

#include "Kennel.h"
#include <vector>

Kennel::Kennel()
{
}
Kennel::~Kennel()
{
}

void Kennel::AddCat(const std::string &name)
{
	Animal *cat = new Cat(name);
	v.push_back(cat);
}

void Kennel::AddDog(const std::string &name)
{
	Animal *dog = new Dog(name);
	v.push_back(dog);
}

void Kennel::RollCall()
{
	std::vector<Animal*>::iterator it;
	for(it=v.begin(); it!=v.end(); it++)
	{
		std::cout<<(*it)->get_name();
		(*it)->sound();
	}	
}

#endif
