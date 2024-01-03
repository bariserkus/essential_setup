# Tools for Linux Setup

These suggestions are mostly for 23.10. (December, 2023).

## Package Installer for Ubuntu 23.10

Ubuntu 23.10 does not support installing downloaded dep packages by double clicking it. To be able to that you can install `Gdebi` from App Center by selecting the Debian Packages filter.

You can always install deb packages by 

```
$ sudo dpkg -i yourfile.deb
```


## Auto Complete Command

Create a file `~/.inputrc` with the content:

```shell
"\e[A": history-search-backward
"\e[B": history-search-forward
```

## Gnome Tweak Tools

A utility tool to configure Gnome desktop and such.

`$ sudo apt install gnome-tweaks` 

`$ gnome-tweaks`

## Gnome `dconf-editor`

A utility to configure GNOME.

You can install `dconf-editor` using `apt`.

## Gnome Shell Extensions

Gnome Shell Extensions are useful tools for Gnome. To install extensions, it is recommended to install the Extension Manager using `apt`:

`sudo apt install gnome-shell-extension-manager`

From the extension manager, you can search for the extention and install it. However, some of the extensions do not appear in the search of Extension Manager. For those, you can locate them at [Gnome Shell Extensions][11] web page. And then, direct the setup to the Extension Manager.

[11]: https://extensions.gnome.org/

For example, a very useful extention is Dash to Panel tool. This tool does not appear in the manager but you can locate it [here][22] and when you click to Install, it will ask for your permission to open the manager app. From the app, you can install the extention.

[22]: https://extensions.gnome.org/extension/1160/dash-to-panel/

## Install `ispell` and `spell` using `apt`

## Git Setup

Git can be installed using `apt`.

## Git Credential Manager (GCM)

Download the latest [deb package][55], and run the following:

[55]: https://github.com/git-ecosystem/git-credential-manager/releases

```shell
$ sudo dpkg -i <path-to-package>
$ git-credential-manager configure
```
To uninstall:

```shell
$ git-credential-manager unconfigure
$ sudo dpkg -r gcm
```

See [this page][33] for reference.

[33]: https://github.com/git-ecosystem/git-credential-manager/blob/release/docs/install.md

## Setting up Credentials and GCM

There are several ways to store GitHub credentials. I recommend the following method:

```shell
export GCM_CREDENTIAL_STORE=cache
# or
git config --global credential.credentialStore cache
```

This credential store uses Git's built-in ephemeral
in-memory [credential cache][credential-cache]. 
This helps you reduce the number of times you have to authenticate but
doesn't require storing credentials on persistent storage. It's good for
scenarios like [Azure Cloud Shell][azure-cloudshell]
or [AWS CloudShell][aws-cloudshell], where you don't want to
leave credentials on disk but also don't want to re-authenticate on every Git
operation.

By default, `git credential-cache` stores your credentials for 900 seconds.
That, and any other [options it accepts][git-credential-cache-options],
may be altered by setting them in the environment variable
`GCM_CREDENTIAL_CACHE_OPTIONS` or the Git config value
`credential.cacheOptions`. (Using the `--socket` option is untested
and unsupported, but there's no reason it shouldn't work.)

```shell
export GCM_CREDENTIAL_CACHE_OPTIONS="--timeout 300"
# or
git config --global credential.cacheOptions "--timeout 300"
```

When you need the first credential verification, GCM will appear and you can verify your credentials from GitHub web page.

See [this page][44] for reference.

[44]: https://github.com/git-ecosystem/git-credential-manager/blob/release/docs/credstores.md

## Install `sysstat` using `apt`

## Install `cscope` and `screen` using `apt`

More info on cscope is here:

<https://cscope.sourceforge.net/>

More info on screen is here:

<https://linuxize.com/post/how-to-use-linux-screen/>


## Install `emacs`

In Ubuntu 23.10, `emacs` is available in Snap Store, which is the recommended method of installation.

For Native Compilation use the following (I did not test this in Ubuntu 23.10):

```shell
$ sudo add-apt-repository ppa:kelleyk/emacs
$ sudo add update
$ sudo apt install emacs28-nativecomp
```
for version 28 with native compilation. For newer versions, adjust accordingly.

## Install `vim` using `apt`

## Install `xclip` using `apt`

## Install `flameshot` using Snap Store

Note that Ubuntu 23.10 has the clip tool embedded into the settings parts of the  taskbar.

## Markdown Tools
Ghostwriter is a great tool for markdown editing. Ghostwriter requires the following packages as prerequiste:

```shell
$ sudo apt install g++ qtbase5-dev libqt5svg5-dev qtmultimedia5-dev qtwebengine5-dev pkg-config libqt5concurrent5 qttools5-dev-tools qttools5-dev libkf5coreaddons-dev libkf5xmlgui-dev libkf5configwidgets-dev libkf5sonnet-dev libkf5doctools5 libkf5doctools-dev cmake extra-cmake-modules libhunspell-dev
```

Also install seperately the following:

* pandoc package: `sudo apt install pandoc`
* multimarkdown package: `sudo apt install libtext-multimarkdown-perl`
* cmark package: `sudo apt install cmark`

For Ubuntu 23.10, install Ghostwriter using Snap Store, as it has its own specific version (23.10.xx).

For Ubuntu 20.04, 22.04, install `ghostwriter` using `ppa` and `apt`. Don't use snap as it has the older version.


## Reduce Ubuntu Titlebar Thickness

Create the file `~/.config/gtk-3.0/gtk.css` with the contents below:

```
headerbar entry,
headerbar spinbutton,
headerbar button,
headerbar separator {
    margin-top: 0px; /* same as headerbar side padding for nicer proportions */
    margin-bottom: 0px;
}

headerbar {
    min-height: 24px;
    padding-left: 2px; /* same as childrens vertical margins for nicer proportions */
    padding-right: 2px;
    margin: 0px; /* same as headerbar side padding for nicer proportions */
    padding: 0px;
  }


/* No line below the title bar */
.ssd .titlebar {
    border-width: 2px;
    box-shadow: none;
}
```

Or 

```
/* shrink headerbars */
headerbar {
    min-height: 0px;
    padding-left: 2px; /* same as childrens vertical margins for nicer proportions */
    padding-right: 2px;
    background-color: #2d2d2d;
}

headerbar entry,
headerbar spinbutton,
headerbar button,
headerbar separator {
    margin-top: 0px; /* same as headerbar side padding for nicer proportions */
    margin-bottom: 0px;
}

/* shrink ssd titlebars */
.default-decoration {
    min-height: 0; /* let the entry and button drive the titlebar size */
    padding: 0px;
    background-color: #2d2d2d;
}

.default-decoration .titlebutton {
    min-height: 0px; /* tweak these two props to reduce button size */
    min-width: 0px;
}

window.ssd headerbar.titlebar {
    padding-top: 3px;
    padding-bottom: 3px;
    min-height: 0;
}

window.ssd headerbar.titlebar button.titlebutton {
    padding-top: 3px;
    padding-bottom:3px;
    min-height: 0;
}

```


## System Monitor

Note that the following may not work for Ubuntu 23.10 at the moment. However, this is a great tool and hope it is fixed for 23.10.

A Gnome shell extension to observe the system resources on the taskbar visually.

Install it from the web page:

<https://extensions.gnome.org/extension/120/system-monitor/>

## Desktop Shortcut to Folders

This is not a symbolic link.

Create a file with `.desktop` extention with the following:

```shell
[Desktop Entry]
Name=name_of_the_shortcut
Exec=xdg-open /home/user/path_to_directory
Type=Application
Terminal=false
Icon=/usr/share/icons/Yaru/48x48/places/folder.png
```

Then, 

* allow executing this shortcut using right-click -> Properties -> Permissions -> "Allow executing file as program"
* right-click "Allow Launching"


## Make Monday the First Day of the Week

Identify the locale:

`$ locale | grep LC_TIME`

Assume that the output is 

`LC_TIME="en_US.UTF-8"`

Then, open `/usr/share/i18n/locales/en_US` for editing. Add the line:

`first_weekday 2`

right before the line

`END LC_TIME`

and save. Generate the modified locale:

`$ sudo locale-gen en_US.UTF-8`







## Creating Python Environments 

Create a virtual environment using

```shell
$ python3 -m venv myenv 
```

and activate this environment using

```shell
$ source myenv/bin/activate
```

## Install `spyder`

Note that after Ubuntu 23.04, direct use of pip is prohibited. Two methods are suggested: (a) virtual environments or (b) use of `pipx` is suggested. In the following we use virtual environment method:

First create a Python environment and activate it.

Install using `pip` after activation using

```shell
$ (myenv) pip install spyder numpy scipy pandas matplotlib sympy cython
```

Start spyder from the virtual environment usig the CLI.


## Multiple Versions of Eclipse

Eclipse for Intel oneAPI is an older version. Eclipse for NVidia can be a newer version. So, if you want to use newer version with NVidia, you have to have two seperate versions of Eclipse: one for Intel oneAPI. You can use the program Alacarte to create shortcuts for both.

## Vitis, Git and Multiple Projects in Eclipse

If you want use Git for you Vitis project, this is what I recommend.

First of all, you are probably aware of that Vitis creates four sub-projects when you create a Vector Add example. These are not originally located under one folder and they are all directly under the workspace folder. For example if you create a `test01` project with Vitis Vector Add wizard, Vitis creates four project folders:

* `test01`
* `test01_kernels`
* `test01_system`
* `test01_system_hw_link`

but these would be directly under the workspace folder, say  `vitis_workspace`.

In this scenario, I want to have one main folder of `vitis_repo`, which will act Git repo folder, and I want to have one subfolder for each of the Vitis project and in each of these project folders I will have four Vitis project folders:

```shell
vitisws
├── RemoteSystemsTempFiles
└── vitis_repo
    ├── test01
    │   ├── test01
    │   ├── test01_kernels
    │   ├── test01_system
    │   └── test01_system_hw_link
    └── test02
        ├── test01
        ├── test01_kernels
        ├── test01_system
        └── test02_system_hw_link

```

There is an alternate scenario that `vitis_repo` is placed out of the Vitis workspace directory. You can do both using Vitis-Eclipse Share Team option.

```shell
vitisws
└── RemoteSystemsTempFiles
vitis_repo
├── test01
│   ├── test01
│   ├── test01_kernels
│   ├── test01_system
│   └── test01_system_hw_link
└── test02
    ├── test01
    ├── test01_kernels
    ├── test01_system
    └── test02_system_hw_link
```

To achieve the first alternative, do as follows: 

* Create `test01` project with Vitis-Eclipse, as usual. These will create four folders in the workspace.
* In the Vitis-Eclipse project navigator, select the main project and three sub projects.
* Right click and select `Share Team`
* From there create a new folder for your repo, `vitis_repo` and create a new subfolder `test01`.
* This will move all project directories to new subfolders of `vitis_repo` and `test01` while keeping the necessary link information in Vitis-Eclipse.
* Do not do any commit/push at this stage.

To push-pull from an Git origin, I would recommend this:

* Create a Git Project on your Git system (e.g. github.com.) with name `vitis_repo`. While creating this repo, create `README.md`, `.gitignore` and license files. For the ignore file, choose C/C++ development. This will create a project with one initial commit.
* Clone this project to your computer somewhere different than Vitis-Eclipse workspace.
* In the Vitis workspace, rename your `vitis_repo` folder to `vitis_repo_`
* Copy the cloned vitis_repo folder into the Vitis-Eclipse workspace directory.
* Move everything inside the `vitis_repo_` folder to the `vitis_repo` folder.
* Delete `vitis_repo_` folder.
* Now do a typical commit/push for `viti_repo` and upload your files to `origin` as usual. My favorite tool is GitKraken, but you can use git command line.
* Vitis-Eclipse will see the git system at this stage. I would not use Vitis-Eclipse for git commit/push-pull. I would recommend using your usual git practices.

Also note that following a similar procedure, you can create multiple and seperate repo directories.

## ASCII Format of a Directory Structure

For command line use:

`$ tree`

There are also web pages that creates ASCII caracters of a given directory structure such as:

<https://ascii-tree-generator.com/>

## Question Mark on Wifi - Ubuntu.

* Settings -> Privacy -> Connectivity Checking -> On/Off

or

* `$ sudo service network-manager restart`


## OpenSSL Libraries

`$ sudo apt install libssl-dev`

## Install the Latest Version of CMAKE

The latest version of CMAKE is available in Snap Store:

<https://snapcraft.io/install/cmake/ubuntu> 

and can be installed with:

`$ sudo snap install cmake --classic`

Otherwise, it can be installed using PPA and apt:

`$ sudo apt remove --purge --auto-remove cmake`

`$ sudo apt update && \`

`$ sudo apt install -y software-properties-common lsb-release && \`

`$ sudo apt clean all`

`$ wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null`

`$ sudo apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main"`

`$ sudo apt update`

`$ sudo apt install cmake`

## Install Latest Stable GCC

Ubuntu 20.04 has an older version of GCC, I guess, 9.4.0. To install the latest version, which I guess is 11.1.0, using PPA and `apt`:

`$ sudo apt update`

`$ sudo apt install build-essential`

`$ sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test`

`$ sudo apt install gcc-11 g++-11`

Check version:

`$ g++ --version`

## Configure Multiple Installations of GCC

I assume, you have versions 9 and 11 of GCC:

`$ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 11`

`$ sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 11`

`$ sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 9`

`$ sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 9`

Then use the following to select the default version:

`$ sudo update-alternatives --config gcc`

`$ sudo update-alternatives --config g++`

If you made a mistake with the configuration, you can use to remove all configuration settings by

`$ sudo update-alternatives --remove-all gcc`

`$ sudo update-alternatives --remove-all g++`

Then you can configure them again with the correct settings.

## Install MPICH

`$ sudo apt install mpich`

## Install Boost Libraries using `apt`

`$ sudo apt update`

`$ sudo apt install libboost-all-dev`

You can get current version of installed Boost Libraries:

`$ dpkg -s libboost-dev | grep 'Version'`

or you can go to the `/usr/include/boost` folder and check the file `version.hpp`.

## Install Boost Libraries using `bootstrap`

Install MPICH.

First get the boost package. In the following example version 1.81 is downloaded:

`$ wget http://downloads.sourceforge.net/project/boost/boost/1.81.0/boost_1_81_0.tar.gz`

Unzip the package:

`$ tar -zxvf boost_1_81_0.tar.gz`

Enter to the installation directory:

`cd boost_1_81_0`

To install Boost to `/usr/` folder:

`$ ./bootstrap.sh --prefix=/usr/`

This will place the header files (include files) to `/usr/include/boost` folder and place the boost library files (eg: `libboost_serialization.so.1.81.0`) to `/usr/lib` folder.

To install Boost to a different folder, e.g `/home/user_name/boost/` folder:

`$ ./bootstrap.sh --prefix=/home/user_name/boost/`

This will place the header files (include files) to `/home/user_name/boost/include/boost` folder and place the boost library files (eg: `libboost_serialization.so.1.81.0`) to `/home/user_name/boost/lib` folder.

It will also generate the `project-config.jam` file. Edit this file and add the following line to the end of file: `using mpi ;`.

If you want to use a toolset other than `gcc` (e.g. `clang`), then add the following option:

`--with-toolset=clang`

This will set the default toolset to `clang` in the `project-config.jam` file.

Get the core numbers for fast build:

``$ cpuCores=`cat /proc/cpuinfo | grep "cpu cores" | uniq | awk '{print $NF}'` ``

Install Boost to `/usr` folder using `sudo`:

`$ sudo ./b2 --with=all -j $cpuCores install --prefix=/usr/`

To install Boost to a different folder, e.g. `/home/user_name/boost/`:

`$ ./b2 --with=all -j $cpuCores install --prefix=/home/user_name/boost/`

If you want to use a toolset other than `gcc` (e.g. `clang`), then add the following option:

`toolset=clang`

Ignore the warnings about use of `auto_ptr`.

Check the installed version:

`$ cat /usr/include/boost/version.hpp | grep "BOOST_VERSION"`

`$ cat /usr/include/boost/version.hpp | grep "BOOST_LIB_VERSION"`

## Uninstall Boost Library
`$ sudo apt update`

`$ sudo apt -y --purge remove libboost-all-dev libboost-doc libboost-dev`

`$ sudo rm -f /usr/lib/libboost_*`

`$ sudo apt -y install build-essential g++ python-dev autotools-dev libicu-dev libbz2-dev`

## Install OpenGL Libraries

`$ sudo apt install freeglut3-dev`

## Install CUDA Toolkit

Go to CUDA Developer web site and download the installer, follow the instructions there. I suggest to follow the `deb(local)` path.

The `.bashrc` enviroment:

```shell
## CUDA variables
export CUDA_HOME="/usr/local/cuda"
export PATH="$PATH:$CUDA_HOME/bin"
export CUDACXX="/usr/local/cuda/bin/nvcc"  #This is for CMAKE to recognize CUDA compiler
```

## Install OpenCL Headers

OpenCL headers can be installed with:

`$ sudo apt install opencl-headers`

OpenCL headers are located at:

`/usr/include/CL`

A tool about OpenCL devices, `clinfo` can be installed with:

`$ sudo apt install clinfo`




 

