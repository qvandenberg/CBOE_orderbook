## CBOE Orderbook project

This is an orderbook maintenance system that tracks incremental updates for an exchange venue. It prints the 10-most traded stock quantities in the CLI output.
The project is compiled with CMake and only makes use of the STL.

## Directory structure:
<ul>
<li> `\applications - main programs`</li>
<li>`\build/bin - executables`</li>
<li>`\src - implementation (.cpp) files</li>
<li>`\include` - header (.hpp) files`</li>
</ul>
## Compilation procedure
Modify the build.sh file to add the appropriate CMake generator. I chose "Unix Makefiles" as I work on OS X. On a Linux system, a Ninja generator is likely more suitable.

## Execution of main program
Execute main script for running the main program (`applications/main.cpp`):

`./build/bin/main`

The terminal output should be:<br>
OIH   	5000<br>
SPY   	2000<br>
DRYS  	1209<br>
ZVZZT 	577<br>
AAPL  	495<br>
PTR   	400<br>
UYG   	400<br>
FXP   	320<br>
DIA   	229<br>
BAC   	210<br>

Additional executables can be created in the `/applications` folder. Please remember to then update the `/applications/CMakeLists.txt`
