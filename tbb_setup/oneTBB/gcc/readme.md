### Notes

- Assuming that enviroment for the oneAPI is set properly by sourcing the `vars.sh` of oneTBB and oneDPL or `setvars.sh` of the oneAPI.
- In the source code the `exclusion` and `algorithm` packages are included last. This did not cause problem when building with gcc in my case. However, depending on your setup, they may need to be included first, and their order may need to be changed.
- In the source code `std::execution` is used instead of `dpl::execution`. However, depending on your setup you may need to switch to the latter.
- The `$(pkg-config --libs --cflags tbb)` option in the command line is from the Intel's oneTBB web page [here][1] . 

### Command line build with gcc

Use the following command line for the short code:

`$ g++ -o testtbb_short.out testtbb_short.cpp $(pkg-config --libs --cflags tbb)`

and execute:

`$ ./testtbb_short`


and for the long code:

`$ g++ -o testtbb_long.out testtbb_long.cpp $(pkg-config --libs --cflags tbb)`

and execute:

`$ ./testtbb_long`


[1]: https://www.intel.com/content/www/us/en/develop/documentation/get-started-with-onetbb/top.html "Intel oneTBB Web Page"
