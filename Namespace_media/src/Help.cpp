#include "Help.h"

using namespace MediaIndexer;


void MediaIndexerHelp::displayHelp() {
	std::cout << "Command Line Help"
			<< "\n";
	std::cout << "Media Scanner"
			<< "\n";
	std::cout << "Write ./Media -p 'Your Path for Scanning'"
			<< "\n";
	std::cout << "Your Search will begin automatically";
	std::cout << "Followed by Progress Bar"
			<< "\n";

	std::cout << "Press 1 for list"
			<< "\n";
	std::cout << "N=> 'Song Name'.'format'"
			<< "\n"
			<< "\n";

	std::cout << "Press 2 for viewing Song Detail"
			<< "\n";
	std::cout << "Enter the Song Number"
			<< "\n"
			<< "\n";

	std::cout << "Press 3 for Delete"
			<< "\n";
	std::cout << "Enter the Number of Song "
			<< "\n"
			<< "\n";
	std::cout << "Delete by Key [Key]"
			<< "\n"
			<< "\n";
}


