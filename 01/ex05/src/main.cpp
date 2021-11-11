#include "Karen.hpp"
#include "escape_sequence.hpp"

void	test(Karen& karen, std::string level)
{
	std::cout	<< MAGENTA
				<< level
				<< RESET
				<< std::endl;
	karen.complain(level);
}

int	main()
{
	Karen		karen;
	test(karen, "aaaaaa");
	test(karen, "");
	test(karen, "DEBUG");
	test(karen, "INFO");
	test(karen, "WARNING");
	test(karen, "ERROR");
	return (0);
}
