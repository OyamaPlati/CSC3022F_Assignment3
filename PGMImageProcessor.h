#ifndef PGMImageProcessor_h
#define PGMImageProcessor_h

#include "ConnectedComponent.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <memory>
#include <bits/stdc++.h>

#define MAX_LINE_LENGTH 1000

namespace pltoya001 {

	class PGMImageProcessor {
		private:
			std::string inFileName;
			// Set the minimum and maximum valid components size
			int minValidSize;
			int maxValidSize;
			// Set the threshold for component detection
			unsigned char threshold;
			// Write out all retained components (as foreground/background pixels)
			// to a new PGM file
			std::string outFileName;
		public:
			PGMImageProcessor (const std::string inFileName, int minValidSize, int maxValidSize, unsigned char threshold, const std::string outFileName); // Default Constructor
                	PGMImageProcessor (const PGMImageProcessor & rhs); // Copy Constructor
                	PGMImageProcessor (PGMImageProcessor && rhs); // Move Constructor
                	// Copy and Move Assignment Operators
                	PGMImageProcessor & operator = (const PGMImageProcessor & rhs);
                	PGMImageProcessor & operator = (PGMImageProcessor && rhs);
                	~PGMImageProcessor (); // Destructor

			const std::string & getInFileName();
			void setInFileName(const std::string & inFileName);
			int getMinValidSize ();
			void setMinValidSize (int minValidSize);
			int getMaxValidSize ();
			void setMaxValidSize (int maxValidSize);
			unsigned char getThreshold ();
			void setThreshold (unsigned char threshold);
			const std::string & getOutFileName ();
			void setOutFileName (const std::string & outFileName);

			/* Process the input image to extract all the connected components,
		   	 based on the supplied threshold (0...255) and excluding any components
		   	 of less than the minValidSize. The final number of components that
		   	 you store in your container (after discarding undersized one)
		   	 must be returned.
			*/
			int extractComponents(unsigned char threshold, int minValidSize);

			/* Iterate - with an iterator - though your container of connected
		   	 components and filter out (remove) all the components which do not
		   	 obey the size criteria pass as arguments. The number remaining
		   	 after this operation should be returned.
			*/
			int filterComponentsBySize(int minSize, int maxSize);

			/*  Create a new PGM file which contains all current components
       		   	 (255=component pixel, 0 otherwise) and write this to outFileName as a
		   	 valid PGM. the return value indicates success of operation
 			*/
			bool writeComponents(const std::string & outFileName);

			// Return number of components
			int getComponentCount(void);

			// Return number of pixels in largest component
			int getLargestSize(void);

			// Return number of pixels in smallest component
			int getSmallestSize(void);

			/* Print the data for a component to std::cout
		   	 see ConnectedComponent class;
		   	 print out to std::cout: component ID, number of pixels
			*/
			void printComponentData(const ConnectedComponent & theComponent);

			// Check if a cell is to be visited or not
			bool isValid(bool ** vis, int row, int col);
			// Perform the breadth first search traversal
			void traverse(int **grid, bool **vis, int row, int col);
	};
}
#endif
