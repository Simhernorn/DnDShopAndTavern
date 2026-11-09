#!/bin/bash

make clean 2>/dev/null || true
rm -f *.pro *.pro.user Makefile* ui_*.h moc_*.cpp object_script.* .qmake.stash
rm -rf debug release .qtc_clangd .qtcreator

qmake -project
fichero=$(ls *.pro)
echo "QT += widgets" >> "$fichero"

qmake
make