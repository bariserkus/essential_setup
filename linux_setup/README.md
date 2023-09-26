# Tools for Linux Setup

These suggestions are mostly for Ubuntu 20.04, 22.04 and 23.04. However, some of them will not work with 23.04 as of today (September, 2023).

## Install TeXLive

There is a quick installation guide [here][a].

[a]: https://tug.org/texlive/quickinstall.html

Make sure necessary Perl packages installed:

```
$ perl -MLWP -le "print(LWP->VERSION)"
```

LWP is generally installed with standard Ubuntu installations. If not installed, visit [this][c] web page.

[c]: https://lwp.interglacial.com/ch01_03.htm

Install `perl-tk` package using `apt`.

Download the latest version of `install-tl` form [this][b] web page.

[b]: https://mirror.dogado.de/tex-archive/systems/texlive/tlnet/

Start installer using:
```
$ sudo perl install-tl -gui
```

Suggest to install full system.

TeXlive is installed to `\usr\local\texlive`. For upgrades and other future modifications, the folder is not writable. There are several ways suggested to fix this. I prefer to give access to this folder using

```
$ sudo chmod -R 777 /usr/local/texlive
```

After installation you can manage the TeX system using `tlmgr` command.

Custom and user packages should be placed into the following folder:

```
/usr/local/texlive/texmf-local/tex/latex
```

Note that 2023 version of TeXlive comes with Biblatex and Babel packages, and they do not need to be installed seperately.

## Install LyX

LyX can be installed using the Snap.

Start LyX using the terminal command line, instead of directly starting from the application list.

Fix the issue with the security policy of ghostscript as explained [here][d].

[d]: https://stackoverflow.com/questions/52998331/imagemagick-security-policy-pdf-blocking-conversion

Essentially check the `gs` version with

```
$ gs --version
```

Make sure the version is >= 9.24. If yes, just remove this whole following section from `/etc/ImageMagick-6/policy.xml`:

```
<!-- disable ghostscript format types -->
<policy domain="coder" rights="none" pattern="PS" />
<policy domain="coder" rights="none" pattern="PS2" />
<policy domain="coder" rights="none" pattern="PS3" />
<policy domain="coder" rights="none" pattern="EPS" />
<policy domain="coder" rights="none" pattern="PDF" />
<policy domain="coder" rights="none" pattern="XPS" />
```

Make sure ImageMagick is installed. This a very standard package available in standard Ubuntu installations.

Add the PDF viewer to LyX:

* Go to Tools->Preferences->File Handling->Converters`
* Create PDF to PNG converter using the following converter command:

`convert -density 200 -trim -quality 100 -colorspace RGB -sharpen 0x1.0 $$i $$o`


## Install TeXStudio

Install TeXStudio using the PPA:

```
$ sudo add-apt-repository ppa:sunderme/texstudio
$ sudo apt update
$ sudo apt install texstudio

```


## Install `spyder`

To install spyder, first we need to create a virtual environment using

```
$ python3 -m venv spyder-env
```

and activate this environment using

```
$ source spyder-env/bin/activate
```

Install using `pip` after activation using

```
$ pip install spyder numpy scipy pandas matplotlib sympy cython
```

After Ubuntu 23.04, direct use of pip is prohibited. So, virtual environments are suggested or use of `pipx` is suggested.

## Auto Complete Command

Create a file `~/.inputrc` with the content:

```
"\e[A": history-search-backward
"\e[B": history-search-forward
```

## Git Setup

Git can be installed using apt.

Install Git Credential Manager as explained [here][1]:

[1]: https://github.com/GitCredentialManager/git-credential-manager

* download the deb package
* install using `sudo dpkg`
* `$ git-credential-manager-core configure`

Set a way to store password as explaine [here][2]. 

[2]: https://github.com/GitCredentialManager/git-credential-manager/blob/main/docs/credstores.md

One way to do this in Linux is

`$ git config --global credential.credentialStore cache`

Then GCM GUI will start automatically when git is called. Personal Accces Token should be used in the GCM GUI. Personal Access Token can be generated in GitHub using `Settings` -> `Developer Settings`.

## Gnome Tweak Tools

A utility tool to configure Gnome desktop and such.

`$ sudo apt install gnome-tweak-tool` 

`$ gnome-tweaks`

Note that you can activate already-installed extentions from here.

## Gnome `dconf-editor`

A utility to configure GNOME.

You can install `dconf-editor` using `apt`.


## Gnome Shell Extensions

Small add-ons for Gnome to make it more practical and efficient.

There are several ways to install extensions:

1. Install a minimal set of extentions
2. Install the extension using `apt`
3. Install the extension using a web browser
4. Download and install manually

### 1. Install a minimal set of extensions

`sudo apt install gnome-shell-extensions` 

### 2. Install the extension using `apt`

Search for Gnome Shell Extensions

`$ apt search gnome-shell-extension-??????`

Install an extension

`$ sudo apt install gnome-shell-extension-??????`

### 3. Install the extension using a web browser

You can install the extensions from Gnome Extentions web site using a web browser plugin:

<https://extensions.gnome.org/>

- first install the plugin
- then install the connector: `sudo apt install chrome-gnome-shell`
- install the extension from the web site of that extension

### 4. Download and install manually

Please see related web pages...

Please see <https://itsfoss.com/gnome-shell-extensions/> for more info.

## Gnome Shell Extension Manager

A tool to manage Gnome shell extensions.

`sudo apt install gnome-shell-extension-prefs`

`gnome-extensions-app`


## System Monitor

A Gnome shell extension to observe the system resources on the taskbar visually.

Install it from the web page:

<https://extensions.gnome.org/extension/120/system-monitor/>


## Alacarte

A tool that creates shortcuts of applications.

`$ sudo apt install alacarte` 

It appears as `Main Menu` in the Applications. It can be started using:

`$ alacarte`

I have used this program to create shortcut for `Eclipse` as it comes as a zip file and does not have installer.

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

```
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

```
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

## Desktop Shortcut to Folders

This is not a symbolic link.

Create a file with `.desktop` extention with the following:

```
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

```
## CUDA variables
export CUDA_HOME="/usr/local/cuda"
export PATH="$PATH:$CUDA_HOME/bin"
export CUDACXX="/usr/local/cuda/bin/nvcc"  #This is for CMAKE to recognize CUDA compiler
```

## Install OpenCL Headers:

OpenCL headers can be installed with:

`$ sudo apt install opencl-headers`

OpenCL headers are located at:

`/usr/include/CL`

A tool about OpenCL devices, clinfo can be installed with:

`$ sudo apt install clinfo`

## Install `sysstat`

`$ sudo apt install sysstat`

## Install `cscope` and `screen` using `apt`

## Install `emacs`

`$ sudo add-apt-repository ppa:kelleyk/emacs`

`$ sudo add update`

`$ sudo apt install emacs28-nativecomp`

for version 28 with native compilation

## Install `vim`

vim can be installed using apt.

## Markdown Tools

Install:

* pandoc
* multimarkdown package: `sudo apt install libtext-multimarkdown-perl`
* cmark package: `sudo apt install cmark`

Install `ghostwriter` for markdown editor using ppa and apt. Don't use snap as it has the older version.

## Install `xclip` using `apt`

## Adding a Custom Directory to Include Library Path

`LIBRARY_PATH` is used by gcc before compilation to search directories containing static and shared libraries that need to be linked to your program.

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

## Git Credentials

Update the URL of origin remote using SSH instead of HTTPS;

`git remote set-url origin git@github.com:username/repo.git`

or

Make Git store the username and password and it will never ask for them.

`git config --global credential.helper store`

Save the username and password for a session (cache it);

`git config --global credential.helper cache`

You can also set a timeout for the above setting

`git config --global credential.helper 'cache --timeout=600'`

## Upgrade `python`

For Ubuntu 20.04, the default version of Python3 is 3.8. Most of the GTK programs (e.g. installer, updater) need Python 3.8 and they will not work with a newer version.

One way to workaround for may be to tell the GTK programs to use Python 3.8 even if a newer version is the default one. For example:

`$sudo vim /usr/bin/gnome-terminal`

Change `#!/usr/bin/python3` to `#!/usr/bin/python3.8`

Do the same for `/usr/bin/software-properties-gtk` and `/usr/bin/update-manager`

However, in my case the update manager did not start properly for the last one. So I switch shebang back to `#!/usr/bin/python3` for `update-manager`.






 

