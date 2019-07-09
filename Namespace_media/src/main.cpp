/*
 * main.cpp
 *
 *  Created on: 22-Apr-2019
 *      Author: kpit
 */
#include "Help.h"
#include "Searching.h"
#include "Song.h"
using namespace MediaIndexer;

int main(int argc, char* argv[]) {
	int choice;
	int opt;
	std::string path;
	Searching searching;
	DisplayContainer display_;
	int idToSearch;
	int countOfsongs;
	struct stat stat_;

	if (argv[optind] == NULL) {
		std::cout << "Mandatory argument(s) missing"
				<< "\n";
		std::cout << "Try './Media -h' for more information."
				<< "\n";

		exit(1);
	}

	while ((opt = getopt(argc, argv, "hp:")) != -1) {
		switch (opt) {
		case 'h':

			MediaIndexerHelp help;
			help.displayHelp();
			break;
		case 'p':
			stat(optarg, &stat_);
			if (S_ISDIR(stat_.st_mode)) {
				try {
					searching.SearchFile(optarg);
				} catch (int returnedErrorNo) {
					// strerror() to get a human-readable string for the error number.
					std::cout << "Error is " << strerror(returnedErrorNo) << "\n";
				}
				countOfsongs =
						searching.getDisplay().availableSongsCountInContainer();

				std::cout << "\n"
						<< "Number of Songs Found: " << countOfsongs << "\n";

				if (countOfsongs > 0) {
					while (true) {
						std::cout << "If you want to show all of the songs press 1"
								<< "\n";
						std::cout << "If you want to search a song by id ,press 2"
								<< "\n";
						std::cout << "If you want to delete a song by id ,press 3"
								<< "\n";
						std::cout << "for exit press 0"
								<< "\n";
						std::cin >> choice;

						switch (choice) {
						case 0:
							exit(0);
						case 1:
							searching.getDisplay().displayMedia();
							break;
						case 2:

							std::cout << "Enter Song number to be search...!: ";
							std::cin >> idToSearch;
							if (idToSearch > countOfsongs)
								std::cout << "Please enter in Range(Invalid Entry)"
								<< "\n";
							else
								searching.getDisplay().searchMediaById(idToSearch);
							break;

						case 3:
							std::cout << "Enter a song number to do you want to delete ";
							std::cin >> idToSearch;

							if ((idToSearch > countOfsongs) || (idToSearch < 0))
								std::cout << "Please enter in Range(Invalid Entry)"
								<< "\n";
							else {
								searching.getDisplay().deleteMediaFromContainer(idToSearch);
								std::cout << "Your Updated List "
										<< "\n";
								searching.getDisplay().displayMedia();
							}
						}
					}
				}
				break;

			} else
				std::cout << "Enter Valid Path...!"
				<< "\n";

		case '?':

			break;
		}
	}

	return 0;
}

