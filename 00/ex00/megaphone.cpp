#include <iostream>

int main(int argc, char *argv[])
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			size_t j = 0;
			while (argv[i][j])
			{
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
				j++;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
