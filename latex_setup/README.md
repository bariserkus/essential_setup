## MikTeX Setup

Follow the instructions on the MikTeX web page. For 64 bit system, use the following:

`deb [arch=amd64] http://miktex.org/download/ubuntu`

Note the `[arch=amd64]` option.

## TeXStudio

TeXStudio is frequently updated, therefore Snap Store installation is not recommended. Use PPA and apt install, instead:

<https://linuxhint.com/install-texstudio-latex-editor-linux/>

However, TeXStudio install tex-live system on top of the MikTeX system. You do not need tex-live, if you have MikTeX. So, to prevent TeXStudio installing a second TeX system on your Ubuntu:

`$ apt --no-install-recommends install texstudio`

## ImageMagick

`$ sudo apt install imagemagick`

## Jabref

JAbref can be installed using Snap Store

<https://snapcraft.io/install/jabref/ubuntu>


