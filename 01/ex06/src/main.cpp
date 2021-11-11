#include "Karen.hpp"
#include "escape_sequence.hpp"

enum e_level
{
	E_DEBUG,
	E_INFO,
	E_WARNING,
	E_ERROR
};

#define DEBUG	"DEBUG"
#define INFO	"INFO"
#define WARNING	"WARNING"
#define ERROR	"ERROR"

int		get_level(std::string level)
{
	if (level == DEBUG)		return E_DEBUG;
	if (level == INFO)		return E_INFO;
	if (level == WARNING)	return E_WARNING;
	if (level == ERROR)		return E_ERROR;
							return -1;
}

void	put_level(std::string level)
{
	std::cout	<< MAGENTA
				<< "[ " <<  level << " ]"
				<< RESET
				<< std::endl;
}

int		main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	Karen		karen;
	switch (get_level(argv[1]))
	{
		case E_DEBUG:
			put_level(DEBUG);
			karen.complain(DEBUG);
		case E_INFO:
			put_level(INFO);
			karen.complain(INFO);
		case E_WARNING:
			put_level(WARNING);
			karen.complain(WARNING);
		case E_ERROR:
			put_level(ERROR);
			karen.complain(ERROR);
			break;
		default:
			put_level("Probably complaining about insignificant problems");
			break;
	}
	return (0);
}
