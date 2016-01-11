# Game Project Template

Boilerplate for quickly getting started with SFML 2.3 and Thor while using Sublime Text 2 as the project/build manager and MinGW G++ for compiling.

Source files are located in `src/`. A few C++ structs are included, namely `Game`, `Screen`, and `Level`. `Level` (*for now*) is where most new code will be placed. `Game` runs the show and `Screen` manages most of the window management and drawing with SFML. `utils.hpp` is used for storing miscellaneous functions.

Images, sounds, fonts, etc are stored in `resources/` (which can be easily accessed through SFML's `loadFromFile()` functions using `'resources/...'`).

Open the project in Sublime Text 2 by opening `Project.sublime-project`. Select `Build & Run` from the `Tools > Build System` pulldown. `CTRL` + `B` will run `compile.bat` (`compile.sh` for linux) which gathers C++ files, starts the build, automatically opens the newly built project (if possible), logs output to the Sublime Text console window, and cleans up all build-related files upon exit. Executables are built to `build/win32/main.exe` (`build/linux/main` for linux).

# Prerequisites

This project uses a few external requirements like `GCC 4.9.2`, `SFML 2.3.2 (GCC 4.9.2)`, and `Thor v2.0 (mingw)`. They're extracted into their relative directories into `C:\dev_resources\`. This is primarily focused for Windows development but notes for building to Linux is also included.

### Windows 

- Download [MinGW 4.9.2](http://sourceforge.net/projects/mingw-w64/files/latest/download?source=files) and extract to `C:\dev_resources\mingw32-4.9.2\`
- Download [SFML (GCC 4.9.2 MinGW (DW2)) - 32-bit](http://www.sfml-dev.org/download/sfml/2.3.2/) and extract to `C:\dev_resources\SFML-2.3.2_GCC-4.9.2\`
- Download [Thor](https://github.com/Bromeon/Thor) and extract to `C:\dev_resources\thor-v2.0-mingw\`

`compile.bat` automatically sets (and reverts) environment variables so you don't have to manually add the above paths to your `%PATH%` environment variable. It's recommended to not have MinGW/SFML/Thor directories in your `%PATH%` variable if you already do.

`libstdc++-6.dll` in `build/win32/` is necesary to run a newly built `main.exe`. This is likely due to my inexperience with building projects using G++.

### Linux

Install [GCC 4.9.2](https://gist.github.com/craigminihan/b23c06afd9073ec32e0c). Extract [SFML (GCC) - 32-bit](http://www.sfml-dev.org/download/sfml/2.3.2/) and [Thor](https://github.com/Bromeon/Thor) into /root/sfml/ and /root/thor/ respectively. If another path is chosen (and you should), be sure to update compile.sh. Also, be sure to `chmod +x compile.sh`.

# Future

- OS X additions to build requirements/build script
- Better cleanup on build errors
- other useful library support
	- [Box2D](https://mistermage.wordpress.com/2013/08/25/snippet-box2d-with-sfml-net/)
	- [SFGUI](http://sfgui.sfml-dev.de/)
	- JSON parser/compiler
- Game states
- Entities
- Tilemap class
- Switch from structs to classes

# Related documentation links

MinGW has a helpful [C Preprocessor](https://gcc.gnu.org/onlinedocs/gcc-4.9.3/cpp/) page.

SFML 2.3 has helpful pages like their [documentation tutorials](http://www.sfml-dev.org/tutorials/2.3/), [class index](http://www.sfml-dev.org/documentation/2.3/classes.php), and [wiki examples](https://github.com/SFML/SFML/wiki).

Thor v2.0+ documentation can be [found here](http://www.bromeon.ch/libraries/thor/tutorials.html).

# Helpful links

- [How to C in 2016](https://matt.sh/howto-c)
- [Dive into C++11 - Arkanoid Clone](https://www.youtube.com/watch?v=_4K3tsKa1Uc)
- [Creating a City Building Game with SFML](https://www.binpress.com/tutorial/creating-a-city-building-game-with-sfml/137) (has some unchecked bugs)
- [C++ Sfml 2.0 Made Easy](https://www.youtube.com/playlist?list=PLHJE4y54mpC5j_x90UkuoMZOdmmL9-_rg)
- [Game Development Design](http://stefan.boxbox.org/game-development-design/)
- [Organizing Code Files in C and C++](http://www.gamedev.net/page/resources/_/technical/general-programming/organizing-code-files-in-c-and-c-r3173)
- [Game Programming Patterns](http://gameprogrammingpatterns.com/contents.html)
- [Sublime Text 2 - Build Systems](http://sublimetext.info/docs/en/reference/build_systems.html)