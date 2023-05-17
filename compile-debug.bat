meson setup build --buildtype=debug
ninja -C build
meson compile -C build
set /p DUMMY=[ENTER] to continue...
cls
