## CBOE Orderbook project - Quincy van den Berg

This project is part of my application. It is structured as a CMake project that uses the STL as its only dependency.

Directory structure:

`\applications - main programs`
`\build/bin - executables`
`\extern - external libraries (as header-only)`
`\src - implementation (.cpp) and header (.hpp) files`
`\test - testing scripts`

## Compilation procedure
Manually, follow below steps. (put this in .sh file)
Create and navigate to the root build folder:

`mkdir build; cd build`

Execute cmake commands:

`cmake .. -G <Generator>`

For `<Generator>`, select a suitable CMake generator for your system (e.g. Xcode, Ninja, Unix Makefiles, etc.). For a complete list and further options see: 
Navigate to the root folder and compile:

`cd ..; cmake --make build`

Execute main for running the main program:

`./build/bin/main`

Run tests:

`./main_test`

Additional executables can be created in the `/applications` folder. Please remember to then update the `/applications/CMakeLists.txt`
