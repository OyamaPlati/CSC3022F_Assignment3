#ifndef ConnectedComponet_h
#define ConnectedComponent_h

#include <vector>
#include <utility>
#include <string>

namespace pltoya001 {
	class ConnectedComponent {
        	private:
			// The number of pixels in the component
			int pixels;
			// A unique integer identifier for a component (you can just assign integers
			// starting at 0)
			int id;
			// Store the pixels in that component ((x,y) pairs)
			std::vector<std::pair<int, int>> coords;

        	public:
			// Default Costructor
			ConnectedComponent (int pixels, int id, std::vector<std::pair<int, int>> & coords);
			ConnectedComponent (const ConnectedComponent & rhs); // Copy Constructor
			ConnectedComponent (ConnectedComponent && rhs); // Move Constructor
			// Copy and Move Assignment Operators
			ConnectedComponent & operator = (const ConnectedComponent & rhs);
			ConnectedComponent & operator = (ConnectedComponent && rhs);
			~ConnectedComponent (); // Destructor

			// Getters and Setters
			int getPixels ();
			void setPixels (int pixels);
			int getId ();
			void setId (int id);
			std::vector<std::pair<int, int>> & getCoords ();
			void setCoords (std::vector<std::pair<int, int>> & coords);
	};

}

#endif
