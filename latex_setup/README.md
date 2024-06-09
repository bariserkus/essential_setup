# LaTeX Tools

## Install TeXLive

There is a quick installation guide [here][a]. I will explain the procedure and prerequistes in detail below. 

[a]: https://tug.org/texlive/quickinstall.html

The following installation notes are prepared for TeXLive 2024. For other versions, please modify as required.

* TeXlive is installed to `\usr\local\texlive`. For upgrades and other future modifications, the folder is not writable. There are several ways suggested to fix this. First create the folder `textlive` under `/usr/local/` using `sudo`. I prefer to give access to this folder using

```shell
$ sudo chmod -R 777 /usr/local/texlive
```

or

```shell
$ sudo chown -R "$USER" /usr/local/texlive
```


* First, make sure necessary Perl packages installed:

```
$ perl -MLWP -le "print(LWP->VERSION)"
```

LWP is generally installed with standard Ubuntu installations. If not installed, visit [this][c] web page.

[c]: https://lwp.interglacial.com/ch01_03.htm

Then, do the following:

* Install `perl-tk` package using `apt`.
* Install `tk` package using `apt`.
* Download the latest version of `install-tl-unx.tar.gz` form [this][b] web page.

[b]: https://mirror.dogado.de/tex-archive/systems/texlive/tlnet/

* Unzip the package:
```
$ zcat < install-tl-unx.tar.gz | tar xf -
```

* Start installer using:
```
$ cd install-tl-*
$ sudo perl install-tl -gui
```

* I suggest to install full system.

*Add /usr/local/texlive/2024/texmf-dist/doc/man to MANPATH.
*Add /usr/local/texlive/2024/texmf-dist/doc/info to INFOPATH.
*Most importantly, add /usr/local/texlive/2024/bin/x86_64-linux to your PATH for current and future sessions:

```
export PATH="/usr/local/texlive/2024/bin/x86_64-linux:$PATH"
export MANPATH="/usr/local/texlive/2024/texmf-dist/doc/man:$MANPATH"
export INFOPATH="/usr/local/texlive/2024/texmf-dist/doc/info:$INFOPATH"
```

Rerun:

```
$ sudo chmod -R 777 /usr/local/texlive
```

* After installation, you can manage the TeX system using `tlmgr --gui` command.

* Custom and user packages should be placed into the following folder:

```
/usr/local/texlive/texmf-local/tex/latex
```

* Note that 2024 version of TeXlive comes with `biblatex` and `babel` packages, and they do not need to be installed seperately.

## ImageMagick

If not installed, install ImageMagick using the following:

```
$ sudo apt install imagemagick
```

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
* Create PDF (graphics) to PNG converter using the following converter command:

```
convert -density 200 -trim -quality 100 -colorspace RGB -sharpen 0x1.0 $$i $$o
```


## Install TeXStudio

Install TeXStudio using the PPA as explained in the followingweb page:

<https://linuxhint.com/install-texstudio-latex-editor-linux/>

```
$ sudo add-apt-repository ppa:sunderme/texstudio
$ sudo apt update
$ sudo apt install texstudio
```

However, TeXStudio may install a seperate tex-live system on top of the existing tex system. So, to prevent TeXStudio installing a second TeX system on your Ubuntu:

```
$ apt --no-install-recommends install texstudio
```

Please check if this is the case for your version of Ubuntu. For Ubuntu 23.04, this may not be the case.


## Install Jabref

Jabref can be installed using Snap Store:

<https://snapcraft.io/install/jabref/ubuntu>

On Ubuntu 23.04, it is available on the Snap Store App.
