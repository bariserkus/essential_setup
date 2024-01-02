## Adding a Custom Directory to Include Library Path

`LIBRARY_PATH` is used by `gcc` or `g++` before compilation to search directories containing static and shared libraries that need to be linked to your program.

`LD_LIBRARY_PATH` is used by your program to search directories containing shared libraries after it has been successfully compiled and linked.

Your libraries can be static or shared. If it is static then the code is copied over into your program and you don't need to search for the library after your program is compiled and linked. If your library is shared then it needs to be dynamically linked to your program and that's when LD_LIBRARY_PATH comes into play.

Add this to `.bashrc` file and source it:

`export LIBRARY_PATH=$LIBRARY_PATH:/your/custom/path/`
`export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/your/custom/path/`

Check if the directory is added correctly:

`echo $LIBRARY_PATH`
`echo $LD_LIBRARY_PATH`

Similarly, add custom include path for C and C++:

`export C_INCLUDE_PATH=$C_INCLUDE_PATH:/your/custom/path/`
`export CPLUS_INCLUDE_PATH=$CPLUS_INCLUDE_PATH:/your/custom/path/`


## Compilation and Linking C/C++ Libraries

There are two types of libraries we can use:

* Static Libraries
* Dynamic Libraries

These are explained separately below.

Format of Linux libraries are:

`lib<lib_name>.a` or `lib<lib_name>.so` where `<lib_name>` is the library name.

## Static Libraries - Generation

Static libraries are linked statically to the application program. Therefore the executable includes the library functions. Static library should be in the path of the system during linking. Since the library is added to the executable file, the executable does not need the library during execution.

Static libraries has extension of `.a`. For example if the name of the library is `myfunc` then the static library name is `libmyfunc.a`

Lets assume that we have `myfunc1.c` and `myfunc2.c` as two library files. Also assume that we have `myapp.c` for application source code and `myfunc.h` as the header file for both of these library functions and for the application code.

We can to compile the libraries separately:

```
$ gcc -c myfunc1.c -o myfunc1.o
$ gcc -c myfunc2.c -o myfunc2.o
```
`-c` option is for compiling without linking.

These will generate the object files: `myfunc1.o` and `myfunc2.o`.

We need to archive these two object files into one static library file:

`$ ar -crs libmyfunc.a myfunc1.o myfunc2.o`

we can see the contents of the library:

`$ ar -t libmyfunc.a

## Static Libraries - Linking

Now that we have the library file, we will compile the application and link it with the library. First we compile the application source code:

`gcc -c myapp.c -o myapp.o`

Then we link:

`gcc myapp.o -o myappexe -L . -lmyfunc`

where `-L` gives the location of the library. In this case the `.` tell `gcc` to look for the library in the current directory.

This will generate the executable `myappexe`

Alternatively we can compile and link together:

`gcc -static myapp.c -L . -lmyfunc -o myappexe`

where `-static` enforces static linking.

Then we can run the executable:

`$ ./myappexe`



## Dynamic Libraries - Generation

Dynamic libraries are linked dynamically to the application program. Therefore, the executable does not include the library functions, but calls the functions dynamically during execution. Therefore, the dynamic library should be in the path of the system for the application to find the library during execution.

Dynamic libraries has extension of `.so`, which stands for *shared object*. For example if the name of the library is `myfunc` then the shared library name is `libmyfunc.so`

Lets assume that we have `myfunc1.c` and `myfunc2.c` as two library files. Also assume that we have `myapp.c` for application source code and `myfunc.h` as the header file for both of these library functions and for the application code.

We can to compile the libraries separately:

```
$ gcc -c -fPIC myfunc1.c -o myfunc1.o
$ gcc -c -fPIC myfunc2.c -o myfunc2.o
```
`-c` option is for compiling without linking and `-fPIC` means *Position Independent Code*.

These will generate the object files: `myfunc1.o` and `myfunc2.o`.

We need to generate the dynamic library out of these two libraries:

`$ gcc myfunc1.o myfunc2.o -shared -o libmyfunc.so`

where `-shared` means that we want shared object to be generated.

For Linux to recognize the shared library file, we will place it to `/usr/lib`:

`$ sudo cp libmyfunc.so /usr/lib`

and we have to run `ldconfig`:

`$ sudo ldconfig`

## Dynamic Libraries - Linking

Now that we have the library file, we will compile the application and link it with the library. First we compile the application source code:

`gcc -c myapp.c -o myapp.o`

Then we link:

`gcc myapp.o -o myappexe -lmyfunc`

This will generate the executable `myappexe`

Alternatively we can compile and link together:

`gcc myapp.c -lmyfunc -o myappexe`

Then we can run the executable:

`$ ./myappexe`
