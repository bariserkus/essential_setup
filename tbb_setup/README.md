# Testing TBB or oneTBB Setup

This repository provides minimal C++ examples for testing your TBB or oneTBB setup under Linux/Ubuntu using CMAKE command line, CLion CMAKE and GCC.

TBB is the older version of Threading Building Blocks (see [here][2]). The newer version is oneTBB maintained by Intel (see [here][1]) 

I am assuming you have all the necessary packages installed and they are working fine. The versions of some of the basic required packages I have on my Ubuntu are:

- GCC, version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
- CMAKE, version 3.23.2
- CLion, version 2022.1.1
- TBB, version 2020.2
- oneTBB, version 2021.6.0
- oneDPL, version 2021.7.0

Note that I install and uninstall TBB when switching back and forth to oneTBB.

The directories:

`oneTBB` includes files for the oneTBB installation.

`TBB` includes files for TBB installation.

The codes designated as `_long` are taken from [here][3] and modifed a little bit.

[1]: https://www.intel.com/content/www/us/en/developer/tools/oneapi/onetbb.html "Intel oneTBB"

[2]: https://github.com/wjakob/tbb "TBB GitHub"

[3]: https://solarianprogrammer.com/2019/05/09/cpp-17-stl-parallel-algorithms-gcc-intel-tbb-linux-macos/ "TBB Setup by Solarian Programmer"
