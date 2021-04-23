#include "PGMImageProcessor.h"

struct Info {
	std::string inFile;
	int min;
	int max;
	int threshold;
	std::string outFile;
};

int main (int argc, char ** argv) {
	std::cout << "In main." << std::endl;

	struct Info argument;

        //  Command line input
        for (int jj = 0; jj < argc; ++jj) {
                if (jj == 1) {
                        argument.inFile = argv[jj];
                }

                if (strcmp(*(argv + jj), "-t") == 0) {
                        argument.min = std::stoi(argv[jj+1]);
                        argument.max = std::stoi(argv[jj+2]);
                }

                if (strcmp(*(argv + jj), "-s") == 0) {
                        argument.threshold = std::stoi(argv[jj+1]);
                }

		if (strcmp(*(argv + jj), "-p") == 0) {
			// Do Something
		}

                if (strcmp(*(argv + jj), "-w") == 0) {
			argument.outFile = argv[jj];
                }
        }

	


	return 0;
}
