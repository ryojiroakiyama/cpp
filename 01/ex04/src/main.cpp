#include <iostream>
#include <fstream>
#include "escape_sequence.hpp"

void	replace(std::string& src,
				const std::string& be_replaced,
				const std::string& to_replace)
{
	std::size_t		len_be = be_replaced.size();
	std::size_t		len_to = to_replace.size();
	std::size_t		point = src.find(be_replaced, 0);
	while (point != std::string::npos)
	{
		src.erase(point, len_be);
		src.insert(point, to_replace);
		point += len_to;
		point = src.find(be_replaced, point);
	}
}

/* infile : test.txt -> outfile : test.replace
std::string	file_name(std::string outfile)
{
	std::size_t	dot		= outfile.rfind('.'),
				slash	= outfile.rfind('/');
	if (dot != std::string::npos &&
		(slash == std::string::npos || slash < dot))
		outfile.erase(dot, outfile.size());
	outfile.append(".replace");
	return outfile;
}
*/

int	main(int argc, char *argv[])
{
	try
	{
		if (argc != 4 || !argv[1][0] || !argv[2][0] || !argv[3][0])
			throw "argumet error";
		std::string		infile(argv[1]),
						outfile(infile + static_cast<std::string>(".replace")),
						s1(argv[2]),
						s2(argv[3]);
		std::ifstream	instream(infile);
		std::ofstream	outstream(outfile);
		if (instream.fail() || outstream.fail())
			throw "fail to open file";
		for (std::string line; std::getline(instream, line);)
		{
			replace(line, s1, s2);
			outstream << line;
			if (!instream.eof())
				outstream << std::endl;
		}
	}
	catch(const char *message)
	{
		std::cerr	<< RED
					<< message
					<< RESET
					<< std::endl;
	}
}
