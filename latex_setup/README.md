## TexLive Setup

Follow the instructions on the TexLive web page. You can use GUI installer. Install full tex-live.

Give user access to the TeXLive folder:

`$ sudo chown -R "$USER" /usr/local/texlive`

TeXLive Manager GUI:

`$ tlmgr --gui`

## TeXStudio

TeXStudio is frequently updated, therefore Snap Store installation is not recommended. Use PPA and apt install, instead:

<https://linuxhint.com/install-texstudio-latex-editor-linux/>

However, TeXStudio installs a seperate tex-live system on top of the existing tex system. So, to prevent TeXStudio installing a second TeX system on your Ubuntu:

`$ apt --no-install-recommends install texstudio`

## ImageMagick

`$ sudo apt install imagemagick`

## Jabref

Jabref can be installed using Snap Store

<https://snapcraft.io/install/jabref/ubuntu>


## LyX

Install LyX using PPA.

Add a new converter to LyX: PDF (graphics) -> PNG

`convert -density 200 -trim -quality 100 -sharpen 0x1.0 $$i -colorspace RGB $$o`
