## Building with CMAKE - oneTBB

### Notes

- The cmake files of the oneTBB and oneDPL packages are commented in the `CMakeLists.txt` file. This seems to work; I am assuming the enviroment for the oneAPI is set properly by sourcing the `vars.sh` of oneTBB and oneDPL. You can also source only `setvars.sh` of the oneAPI instead of the previous two.
- The module paths in the `CMakeLists.txt` file is for the superuser setup. If you have normal user, these paths may be different.
- In the source code, the `exclusion` and `algorithm` packages are included first. Depending on your setup, the order of these two packages may need to change as well.
- In the source code `dpl::execution` is used instead of `std::execution`.

### Command Line CMAKE

This is command line CMAKE version. The build directory is assumed to be `build`

First do cmake:

    $ mkdir build
    $ cd build
    $ cmake ..
    
Then make in the `build` directory:

    $ make
    
Execute the short version:

    $ ./testtbb_short
    
and the long version:

    $ ./testtbb_long
    
### Using CLion

Start CLion from the terminal instead using Applications shortcut. I was not able to make Clion work when it started from the Applications, in the case of oneTBB. CLion works from Applications when TBB is installed in the system:

`$ clion &`

Open this directory as a project and build it as usual. You can run both short and long versions from the `Configurations` bar.




