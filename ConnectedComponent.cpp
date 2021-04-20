#include "ConnectedComponent.h"
#include <iostream>
#include <algorithm>

namespace pltoya001 {
	ConnectedComponent::ConnectedComponent (int pixels, int id, std::vector<std::pair<int, int>> & coords)): pixels(pixels), id(id), coords(coords) { }

	ConnectedComponent::ConnectedComponent (const ConnectedComponent & rhs): pixels(rhs.pixels), id(rhs.id), coords(rhs.coords) {
		// Copy Constructor
	}

	ConnectedComponent::ConnectedComponent (ConnectedComponent && rhs): pixels(rhs.pixels), id(rhs.id) {
 		// Move Constructor
		this->coords = std::move (rhs.coords);
	}

	ConnectedComponent::ConnectedComponent & operator = (const ConnectedComponent & rhs) {
		// Guard self assignment
    		if (this == &rhs) {
        		return *this;
		}

		// assume *this manages a reusable resource
    		if (id != rhs.id) {         // resource in *this cannot be reused
        		                    // release resource in *this
        	                            // preserve invariants in case next line throws
        				    // allocate resource in *this
    		}

		return *this;
	}

	ConnectedComponent::ConnectedComponent & operator = (ConnectedComponent && rhs) {
		// Guard self assignment
    		if (this == &rhs) {
        		return *this;
		}

		// Do something

		return *this;
	}

	ConnectedComponent::~ConnectedComponent () {
		// Destructor
	}

	int ConnectedComponent::getPixels () { return this->pixels; }

	void ConnectedComponent::setPixels (int pixels) {
		this->pixels = pixels;
	}

	int ConnectedComponent::getId () { return this->id; }

	void ConnectedComponent::setId (int id) {
		this->id = id;
	}

	std::vector<std::pair<int, int>> & ConnectedComponent::getCoords () { return this->coords; }

	void setCoords (std::vector<std::pair<int, int>> & coords) {
		this->coords = coords;
	}
}
