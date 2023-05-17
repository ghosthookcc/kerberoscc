meson setup build --buildtype=release
meson dist -C build
ninja -C build
meson compile -C build
set /p DUMMY=[ENTER] to continue...
cls
