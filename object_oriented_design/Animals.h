#ifndef ANIMALS_H
#define ANIMALS_H

#include<string>

class Animal
{
protected:
	std::string name;
public:
	Animal()
	{
	}
	~Animal()
	{
	}	
	virtual std::string get_name()
	{
	}
	virtual void sound()
	{
	}
};

class Cat : public Animal
{
public:
	Cat(std::string newname)
	{
		name = newname;
	}
	std::string get_name()
	{
		return name;
	}
	void sound()
	{
		std::cout << " says Meow" << "\n";
	}
};

class Dog : public Animal
{
public:
	Dog(std::string newname)
	{
		name = newname;
	}
	std::string get_name()
	{
		return name;
	}
	void sound()
	{
		std::cout << " says Woof" << "\n";
	}
};

#endif
