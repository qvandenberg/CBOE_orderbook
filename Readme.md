## CBOE Orderbook project - Quincy van den Berg

This project is part of my application. It is structured as a CMake project that uses the STL as its only dependency.

Directory structure:

`\applications - main programs`
`\build/bin - executables`
`\src - implementation (.cpp) files
`\include` - header (.hpp) files`

## Compilation procedure
Modify the build.sh file to add the appropriate CMake generator. I chose "Unix Makefiles" as I work on OS X. On a Linux system, it is most likely "Ninja".

## Execution of main program
Execute main script for running the main program (`applications/main.cpp`):

`./build/bin/main`

The terminal output should be:
OIH   	5000
SPY   	2000
DRYS  	1209
ZVZZT 	577
AAPL  	495
PTR   	400
UYG   	400
FXP   	320
DIA   	229
BAC   	210

Additional executables can be created in the `/applications` folder. Please remember to then update the `/applications/CMakeLists.txt`
