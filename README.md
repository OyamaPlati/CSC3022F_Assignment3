# CSC3022F Assignment 3

### ConnectedComponent.h

This file is used to declare the ConnectedComponent class

### ConnectedComponent.cpp

This file is used to implement the ConnectedComponent class

### PGMImageProcessor.h

This file is used to declare the PGMImageProcessor class

### PGMImageProcessor.cpp

This file is used to implement the PGMImageProcessor class

### Driver.cpp

This file containds the main method which is used to process user input run PGMImageProcessor

****************************************************************************************

Compile the project

****************************************************************************************
> make
****************************************************************************************

Run the project

****************************************************************************************
> ./Driver.exe _arguments_
****************************************************************************************
or

****************************************************************************************
> make run argument=_arguments_
****************************************************************************************

where _arguments_ formart is as follows

-t _int_ _int_ e.g (-s min max) ; min default = 3, max = unlimited

-s _int_ set the threshold for component detection (default = 128, limit to [0 ... 255])

-p print out all the component data as well as the total component number and the sizes of the smallest and largest components

-w _outPGMFile_ write out all retained components to new PGM file _outPGMFile_

