#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp" 

int main()
{
	const int size = 4;
	Animal* animals[size];

	for (int i = 0; i < size/2; i++)
		animals[i] = new Dog();
	for (int i = size/2; i < size; i++)
		animals[i] = new Cat();

	Dog d1;
	d1.getBrain()->setIdea("Eat" ,0 );
	Dog d2 = d1; 
	d2.getBrain()->setIdea("Sleep", 0);
	std::cout << d1.getBrain()->getIdea(0) << std::endl;
	std::cout << d2.getBrain()->getIdea(0) << std::endl; 

	for (int i = 0; i < size; i++)
		delete animals[i];

	return 0;
}

//pointer veya referans olduğu zaman const fonksiyonlar çağrılabilir
