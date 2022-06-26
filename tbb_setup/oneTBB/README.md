## Testing for Intel oneTBB

This directory is for Intel oneTBB. oneTBB is the newer version of TBB and maintained by Intel (see [here][1]).  You can install oneTBB as seperate package  or as part of the oneAPI Base Toolkit (see [here][2]). I prefer the second approach. You have to install oneDPL (see [here][3]) for oneTBB to work. I used the GUI installer of oneAPI Base Toolkit instead of the `apt` installer and installed only oneTBB and oneDPL packages.

The directories:

`cmake` directory is for CMAKE projects. You can use it for both command line CMAKE and CLion CMAKE.

`gcc` directory is for command line build with GCC.

The enviroment settings in the `.bashrc` assuming Intel oneAPI is installed to the default directory:

```
## OneAPI variables
source /opt/intel/oneapi/tbb/latest/env/vars.sh
source /opt/intel/oneapi/dpl/latest/env/vars.sh
source /opt/intel/oneapi/setvars.sh
```


[1]: https://www.intel.com/content/www/us/en/developer/tools/oneapi/onetbb.html "Intel oneTBB"
[2]: https://www.intel.com/content/www/us/en/developer/tools/oneapi/base-toolkit.html "Intel oneAPI Base Toolkit"
[3]: https://www.intel.com/content/www/us/en/developer/tools/oneapi/dpc-library.html "Intel oneDPL"
