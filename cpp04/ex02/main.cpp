#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int size = 4;
    Animal* animals[size];

	//CAN'T
	//animals[0] = new Animal();

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();

    std::cout << "\n--- Testing deep copy ---\n";
    Dog d1;
    d1.getBrain()->setIdea("Eat", 0);
    Dog d2 = d1;
    d2.getBrain()->setIdea("Sleep" , 0);

    std::cout << "d1 brain idea[0]: " << d1.getBrain()->getIdea(0) << std::endl; // Eat
    std::cout << "d2 brain idea[0]: " << d2.getBrain()->getIdea(0) << std::endl; // Sleep

    std::cout << "\n--- Animals make sounds ---\n";
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting animals ---\n";
    for (int i = 0; i < size; i++)
        delete animals[i];

    return 0;
}


//pointer veya referans olduğu zaman const fonksiyonlar çağrılabilir
