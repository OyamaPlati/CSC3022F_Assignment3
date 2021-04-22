#include "ConnectedComponent.h"
#include <iostream>
#include <algorithm>

namespace pltoya001 {
	/* Default Constructor */
	ConnectedComponent::ConnectedComponent (int pixels, int id, std::vector<std::pair<int, int>> & coords)): pixels(pixels), id(id), coords(coords) { }

	/* Copy Constructor */
	ConnectedComponent::ConnectedComponent (const ConnectedComponent & rhs): pixels(rhs.pixels), id(rhs.id), coords(rhs.coords) {}

	/* Move Constructor */
	ConnectedComponent::ConnectedComponent (ConnectedComponent && rhs): pixels(rhs.pixels), id(rhs.id) {
		this->coords = std::move (rhs.coords);
	}

	/* Copy Assignment Operator */
	ConnectedComponent & ConnectedComponent::operator = (const ConnectedComponent & rhs) {
		// Guard self assignment
    		if (this == &rhs) {
        		return *this;
		}

		pixels = rhs.pixels;
		id = rhs.id;
		coords = rhs.coords;

		return *this;
	}

	/* Move Assignment Operator */
	ConnectedComponent & ConnectedComponent::operator = (ConnectedComponent && rhs) {
		// Guard self assignment
    		if (this == &rhs) {
        		return *this;
		}

		pixels = rhs.pixels;
		id = rhs.id;
		this->coords = std::move (coords);
		*this = std::move (rhs);

		return *this;
	}

	/* Destructor */
	ConnectedComponent::~ConnectedComponent () {
		std::cout << "Destructor called. ConnectedComponent object deleted." << std::endl;
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
