#include "PGMImageProcessor.h"

struct Info {
	std::string inFile;
	int min;
	int max;
	int threshold;
	std::string outFile;
};

int usage (std::string arg, int flag) {
	if (flag == 0) {
		std::cout << "threshold for connected component out of range." << std::endl;
		std::cout << "Range = [0 -> 255]" << std::endl;
		return 0;
	}

	if (flag == 1) {
		std::cout << "Wrong file type." << std::endl;
		return 1;
	}

	if (flag == 3) { return 3; }

	std::cout << "File does not exist : " << arg << std::endl;
	return 2;
}

int main (int argc, char ** argv) {
	std::cout << "In main." << std::endl;

	struct Info argument;

        for (int jj = 0; jj < argc; ++jj) {
                if (jj == 1) {
                        argument.inFile = argv[jj];
                }

                if (strcmp(*(argv + jj), "-t") == 0) {
                        argument.min = std::stoi(argv[jj+1]);
                        argument.max = std::stoi(argv[jj+2]);
                }

                if (strcmp(*(argv + jj), "-s") == 0) {
			if (std::stoi(argv[jj+1]) < 0 || std::stoi(argv[jj+1]) > 255) { return usage(argument.inFile, 0); }
                        argument.threshold = std::stoi(argv[jj+1]);
                }

		if (strcmp(*(argv + jj), "-p") == 0) {}

                if (strcmp(*(argv + jj), "-w") == 0) {
			argument.outFile = argv[jj];
                }
        }

	std::ifstream inputStream (argument.inFile, std::ios::in | std::ios::binary);
        if (inputStream.fail()) return usage(argument.inFile, 2);

        std::string buffer;
        int rows, cols, maxvalue;

        inputStream >> buffer;
        if(buffer != "P5"){
                std::cerr << "The format is incorrect" << std::endl;
                return usage (argument.inFile, 1);
        }

        inputStream >> buffer;
        char temp[MAX_LINE_LENGTH];
        while(buffer[0] == '#'){
                inputStream.getline(temp, MAX_LINE_LENGTH, '\n');
                inputStream >> buffer;
        }

        rows = std::stoi(buffer);
        inputStream >> cols;
        inputStream >> maxvalue;

        int ** rawimage = new int * [rows];
        int failtracker = 0;
        for (int row = 0; row < rows; ++row) {
                rawimage[row] = new int [cols];
                for (int col = 0; col < cols; ++col) {
                        unsigned char pixel;
                        pixel = inputStream.get();

                        if (pixel < 0 || pixel > maxvalue) {
                                std::cout << "Failed on pixel: " << failtracker << std::endl;
                                std::cout << "Pixel value: " << pixel << std::endl;
                                return usage(argument.inFile, 3);
                        }

                        rawimage[row][col] = static_cast<int>(pixel);
                        ++failtracker;
                }
        }


        inputStream.close ();

	return 0;
}
