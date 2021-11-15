#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "escape_sequence.hpp"

int main()
{
	{
		std::cout	<< GREEN;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout	<< MAGENTA;
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		meta->makeSound();
		j->makeSound();
		i->makeSound();
		std::cout	<< CYAN;
		delete meta;
		delete j;
		delete i;
	}
	{
		std::cout	<< GREEN;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* j = new WrongCat();
		std::cout	<< MAGENTA;
		std::cout << meta->getType() << " " << std::endl;
		std::cout << j->getType() << " " << std::endl;
		meta->makeSound();
		j->makeSound();
		std::cout	<< CYAN;
		delete meta;
		delete j;
		std::cout	<< RESET;
	}
	return 0;
}
