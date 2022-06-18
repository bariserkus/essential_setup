# Tools for Linux Setup
----------------------

## Gnome Tweak Tools

A utility tool to configure Gnome desktop and such.

`$ sudo apt install gnome-tweak-tool` 

`$ gnome-tweaks`

Note that you can activate already-installed extentions from here.


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

If you want use Git for you Vitis project, this is what I recommended.

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
    │   ├── test01
    │   ├── test01_kernels
    │   ├── test01_system
    │   └── test01_system_hw_link
    └── test02
        ├── test01
        ├── test01_kernels
        ├── test01_system
        └── test02_system_hw_link

```

There is an alternate scenario that `vitis_repo` is places out of the Vitis workspace directory. You can do both using Vitis-Eclipse Share Team option.

```
vitisws
└── RemoteSystemsTempFiles
vitis_repo
├── test01
│   ├── test01
│   ├── test01_kernels
│   ├── test01_system
│   └── test01_system_hw_link
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

`sudo apt-get install libssl-dev`

## Install the latest version of CMAKE

`sudo apt remove --purge --auto-remove cmake`

`sudo apt update && \`

`sudo apt install -y software-properties-common lsb-release && \`

`sudo apt clean all`

`wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | sudo tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null`

`sudo apt-add-repository "deb https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main"`

`sudo apt update`

`sudo apt install cmake`

## Install Latest Stable GCC

Ubuntu 20.04 has an older version of GCC, I guess, 9.4.0. To install the latest version, which I guess is 11.1.0, using PPA and `apt`:

`sudo apt update`

`sudo apt install build-essential`

`sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test`

`sudo apt install gcc-11 g++-11`

Check version:

`g++ --version`

## Configure Multiple Installations of GCC

I assume, you have versions 9 and 11 of GCC:

`sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 11`

`sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 11`

`sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 9`

`sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 9`

Then use the following to select the default version:

`sudo update-alternatives --config gcc`

`sudo update-alternatives --config g++`

If you made a mistake with the configuration, you can use to remove all configuration settings by

`sudo update-alternatives --remove-all gcc`

`sudo update-alternatives --remove-all g++`

Then you can configure them again with the correct settings.

## Install Boost Libraries

`sudo apt-get update`

`sudo apt install libboost-all-dev`

## Install CUDA Toolkit

Go to CUDA Developer web site and download the installer, follow the instructions there. I suggest to follow the `deb(local)` path.

The `.bashrc` enviroment:

```
## CUDA variables
#export CUDA_HOME="/usr/local/cuda"
#export PATH="$PATH:$CUDA_HOME/bin"
#export CUDACXX="/usr/local/cuda/bin/nvcc"  #This is for CMAKE to recognize CUDA compiler
```









 

