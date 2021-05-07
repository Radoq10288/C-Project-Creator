@echo off

if not exist "Makefile" (
	echo No 'Makefile' is found!
	echo.

) else (
	rem Clear the screen
	cls

	echo.
	echo ---------------Clean directory------------------
	rem Clean the current directory
	mingw32-make clean-build-files

	echo.
	echo.
	echo -----------------Build Files--------------------
	rem Build project
	mingw32-make

	echo.
	echo.
	echo -----------------Run Program--------------------
	echo.

	rem Change to directory to bin
	cd bin

	rem Run the program
	cpc.exe

	echo.
	echo.

	rem Return to previous directory.
	cd ..

)


