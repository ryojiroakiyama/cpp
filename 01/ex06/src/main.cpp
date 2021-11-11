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

int		main(int argc, char *argv[])
{
	if (argc != 2)
		return (0);
	Karen		karen;
	switch (get_level(argv[1]))
	{
		case E_DEBUG:
			std::cout << "[ " << DEBUG << " ]" << std::endl;
			karen.complain(DEBUG);
			std::cout << std::endl;
		case E_INFO:
			std::cout << "[ " << INFO << " ]" << std::endl;
			karen.complain(INFO);
			std::cout << std::endl;
		case E_WARNING:
			std::cout << "[ " << WARNING << " ]" << std::endl;
			karen.complain(WARNING);
			std::cout << std::endl;
		case E_ERROR:
			std::cout << "[ " << ERROR << " ]" << std::endl;
			karen.complain(ERROR);
			std::cout << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			std::cout << std::endl;
			break;
	}
	return (0);
}
