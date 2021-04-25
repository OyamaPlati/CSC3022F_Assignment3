#include "PGMImageProcessor.h"

namespace pltoya001 {
	/*std::string inFileName;
        // Set the minimum and maximum valid components size
        int minValidSize;
        int maxValidSize;
        // Set the threshold for component detection
        unsigned char threshold;
        // Write out all retained components (as foreground/background pixels)
        // to a new PGM file
        std::string outFileName; */

        PGMImageProcessor::PGMImageProcessor (const std::string inFileName, int minValidSize, int maxValidSize, unsigned char threshold, const std::string outFileName) : inFileName(inFileName), minValidSize(minValidSize), maxValidSize(maxValidSize), threshold(threshold), outFileName(outFileName) {
 		// Default Constructor
        }

     	PGMImageProcessor::PGMImageProcessor (const PGMImageProcessor & rhs) : inFileName(inFileName), minValidSize(minValidSize), maxValidSize(maxValidSize), threshold(threshold), outFileName(outFileName) {
 			// Copy Constructor
	}

	PGMImageProcessor::PGMImageProcessor (PGMImageProcessor && rhs) : inFileName(inFileName), minValidSize(minValidSize), maxValidSize(maxValidSize), threshold(threshold), outFileName(outFileName) {
		 // Move Constructor
	}

        // Copy and Move Assignment Operators
        PGMImageProcessor & PGMImageProcessor::operator = (const PGMImageProcessor & rhs) {
		if (this == &rhs) { return *this; }

		inFileName = rhs.inFileName;
		minValidSize = rhs.minValidSize;
		maxValidSize = rhs.maxValidSize;
		outFileName = rhs.outFileName;

		return *this;
	}

	PGMImageProcessor & PGMImageProcessor::operator = (PGMImageProcessor && rhs) {
		if (this == &rhs) { return *this; }

		inFileName = rhs.inFileName;
		minValidSize = rhs.minValidSize;
		maxValidSize = rhs.maxValidSize;
		outFileName = rhs.outFileName;
		*this = std::move (rhs);

		return *this;
	}

	PGMImageProcessor::~PGMImageProcessor () {
		// Destructor
		std::cout << "Destructor called. PGMImageProcessor object deleted." << std::endl;
	}

        const std::string & PGMImageProcessor::getInFileName() {
		return inFileName;
	}

        void PGMImageProcessor::setInFileName(const std::string & inFileName) {
		this->inFileName = inFileName;
	}

        int PGMImageProcessor::getMinValidSize () { return minValidSize; }
        void PGMImageProcessor::setMinValidSize (int minValidSize) {
		this->minValidSize = minValidSize;
	}

        int PGMImageProcessor::getMaxValidSize () { return maxValidSize; }
        void PGMImageProcessor::setMaxValidSize (int maxValidSize) {
		this->maxValidSize = maxValidSize;
	}

        unsigned char PGMImageProcessor::getThreshold () { return threshold; }
        void PGMImageProcessor::setThreshold (unsigned char threshold) {
		this->threshold = threshold;
	}

        const std::string & PGMImageProcessor::getOutFileName () { return outFileName; }
        void PGMImageProcessor::setOutFileName (const std::string & outFileName) {
		this->outFileName = outFileName;
	}

	/*const std::queue<std::unique_ptr<ConnectedComponent>> & PGMImageProcessor::getContainer () {
		return container;
	}
	void PGMImageProcessor::setContainer (const std::queue<std::unique_ptr<ConnectedComponent>> & container) {
		this->container = container;
	}*/

        /* Process the input image to extract all the connected components,
           based on the supplied threshold (0...255) and excluding any components
           of less than the minValidSize. The final number of components that
           you store in your container (after discarding undersized one)
           must be returned.
        */
        int PGMImageProcessor::extractComponents(unsigned char threshold, int minValidSize) {

		return 0;
	}

        /* Iterate - with an iterator - though your container of connected
           components and filter out (remove) all the components which do not
           obey the size criteria pass as arguments. The number remaining
           after this operation should be returned.
        */
        int PGMImageProcessor::filterComponentsBySize(int minSize, int maxSize) { return 0; }

        /*  Create a new PGM file which contains all current components
            (255=component pixel, 0 otherwise) and write this to outFileName as a
            valid PGM. the return value indicates success of operation
        */
        bool PGMImageProcessor::writeComponents(const std::string & outFileName) { return false; }

        // Return number of components
        int PGMImageProcessor::getComponentCount(void) { return 0; }

        // Return number of pixels in largest component
        int PGMImageProcessor::getLargestSize(void) { return 0; }

        // Return number of pixels in smallest component
        int PGMImageProcessor::getSmallestSize(void) { return 0; }

        /* Print the data for a component to std::cout
           see ConnectedComponent class;
           print out to std::cout: component ID, number of pixels
        */
        void PGMImageProcessor::printComponentData(const ConnectedComponent & theComponent) { }

	// Produce the binary image
	int ** PGMImageProcessor::binary (int** inputImage, int height, int width) {
		// Threshold the input image and create the binary image
                int ** result = new int * [height];
                for (int row = 0; row < height; ++row) {
                        result [row] = new int [width];
                        for (int col = 0; col < width; ++col) {
                                if (inputImage[row][col] < threshold) {
                                        result[row][col] = 0; // black
                                }
                                else {
                                        result[row][col] = 255; // white
                                }
                        }
                }

		return result;
	}

	// Check if a cell is to be visited or not
	bool PGMImageProcessor::isValid(int** inputImage, int i, int j, int height, int width, bool** vis) {
		return (i >= 0) && (i < height) && (j >= 0) && (j < width) && (inputImage[i][j] && !vis[i][j]);
	}

	// Perform the breadth first search traversal
	void PGMImageProcessor::bfs(int** inputImage, bool** vis, int si, int sj, int height, int width) {
		// Direction vectors
		int row[] = { -1, 0, 1, 0 };
		int col[] = { 0, 1, 0, -1 };

		// Simple BFS first step, we enqueue
    		// source and mark it as visited
    		std::queue<std::pair<int, int>> q;
    		q.push(std::make_pair(si, sj));
    		vis[si][sj] = true;

    		// Next step of BFS. We take out
    		// items one by one from queue and
    		// enqueue their univisited adjacent
    		while (!q.empty()) {

        		int i = q.front().first;
        		int j = q.front().second;
        		q.pop();

        		// Go through all 4 adjacent
        		for (int k = 0; k < 4; k++) {
            			if (isValid(inputImage, i + row[k], j + col[k], height, width, vis)) {
             				vis[i + row[k]][j + col[k]] = true;
             				q.push(std::make_pair(i + row[k], j + col[k]));
            			}
        		}
    		}
	}

	// This function returns the number connected components in an image
	int PGMImageProcessor::countConnectedComponents(int** inputImage) { return 0; }

}
