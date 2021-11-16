#include "Dog.hpp"
#include "Cat.hpp"
#include "escape_sequence.hpp"

int main()
{
	const int		num = 2;
	const Dog		dog;
	const Cat		cat;
	const Animal*	animals[num];

	std::cout	<< GREEN
				<< "[allocate Dog]"
				<< std::endl;
	for (int i = 0; i < num / 2; i++)
		animals[i] = new Dog(dog);

	std::cout	<< MAGENTA
				<< "[allocate Cat]"
				<< std::endl;
	for (int i = num / 2; i < num; i++)
		animals[i] = new Cat(cat);

	std::cout	<< CYAN
				<< "[delete]"
				<< std::endl;
	for (int i = 0; i < num; i++)
		delete animals[i];
	std::cout	<< RESET;
}
