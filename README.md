# C Project Creator (cpc)

## About
A simple command line tool to create and setup a basic C project.
<br /><br />


## How to use

### Creating C project

**To build executable file**<br />
Creates a C project setup that builds an executable C program.
```
# Format:
$>cpc <Project-Name> <Filename>

# Sample:
$>cpc "My Project" cfile
```

```
# Sample structure of output.
My Project
├─ <bin>
├─ <src>
│   └─ cfile.c
├─ debug_build.bat
└─ makefile
```
<br />

**To build library**
```
# Format:
$>cpc <Project-Name> <Filename> <library-type>
```
<br />

* GCC static library<br />
Creates a C project setup that builds a gcc static library (\*.a).
	```
	# Sample:
	$>cpc "My Project" cfile gcc-static-lib
	```

* GCC dynamic library<br />
Creates a C project setup that builds a gcc dynamic library (\*.so).
	```
	# Sample:
	$>cpc "My Project" cfile gcc-dyn-lib
	```

* Windows static library<br />
Creates a C project setup that builds a win32 static library (\*.lib).
	```
	# Sample:
	$>cpc "My Project" cfile win32-static-lib
	```

* Windows dynamic library<br />
Creates a C project setup that builds a win32 dynamic library (\*.dll).
	```
	# Sample:
	$>cpc "My Project" cfile win32-dyn-lib
	```
<br />


### Creating individual file

```
# Format:
$>cpc new <File-type> <Filename>
```
<br />

* Creates a C file<br />
	```
	# Sample:
	$>cpc new -c cfile
	```

* Creates a C header file<br />
	```
	# Sample:
	$>cpc new -h chfile
	```
<br /><br />


## Notes

- For definition of arguments used, see [doc.txt](doc.txt).
- For instructions to build it with MinGW, see [doc.txt](doc.txt).
<br /><br />


## Status

- Now, it can create and setup C project that builds executable program<br />
and GCC library. And it also create individual C and C header file.<br />

- New features is in development.<br /><br />


