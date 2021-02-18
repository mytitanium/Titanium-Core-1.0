
Debian
====================
This directory contains files used to package ttmd/ttm-qt
for Debian-based Linux systems. If you compile ttmd/ttm-qt yourself, there are some useful files here.

## ttm: URI support ##


ttm-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install ttm-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your ttm-qt binary to `/usr/bin`
and the `../../share/pixmaps/ttm128.png` to `/usr/share/pixmaps`

ttm-qt.protocol (KDE)

