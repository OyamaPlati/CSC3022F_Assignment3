#include "PGMImageProcessor.h"
#include <iostream>
#include <algorithm>

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
        	//PGMImageProcessor (const PGMImageProcessor & rhs); // Copy Constructor
        }

	PGMImageProcessor::PGMImageProcessor (PGMImageProcessor && rhs) {
		 // Move Constructor
	}

        // Copy and Move Assignment Operators
        PGMImageProcessor & PGMImageProcessor::operator = (const PGMImageProcessor & rhs) {
		return *this;
	}

	PGMImageProcessor & PGMImageProcessor::operator = (PGMImageProcessor && rhs) {
		return *this;
	}

	PGMImageProcessor::~PGMImageProcessor () {
		// Destructor
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

        /* Process the input image to extract all the connected components,
           based on the supplied threshold (0...255) and excluding any components
           of less than the minValidSize. The final number of components that
           you store in your container (after discarding undersized one)
           must be returned.
        */
        int PGMImageProcessor::extractComponents(unsigned char threshold, int minValidSize) { return 0; }

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
}
