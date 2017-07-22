#include <string>
#include <vector>
#include <iostream>
#include "Kennel.h"
#include "Kennel.cpp"
using namespace std;

int main()
{
    Kennel kennel;

    kennel.AddCat("Garfield");
    kennel.AddDog("Odie");
    kennel.AddDog("Pluto");
    kennel.AddCat("Felix");
    kennel.AddCat("Sylvester");
    kennel.AddCat("Scratchy");
    kennel.AddDog("Scooby Doo");
    kennel.AddCat("Puss in Boots");
    kennel.AddDog("Goofy");
    kennel.AddDog("Old Yeller");

    kennel.RollCall();

    /* output will be:
     *
     * Garfield says Meow
     * Odie says Woof
     * Pluto says Woof
     * Felix says Meow
     * Sylvester says Meow
     * Scratchy says Meow
     * Scooby Doo says Woof
     * Puss in Boots says Meow
     * Goofy says Woof
     * Old Yeller says Woof
     *
     */
}
