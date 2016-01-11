@echo off

echo Initial cleanup

if exist build/win32/files.tmp (
	del build\win32\files.tmp
)

if exist build\win32\main.exe (
	del build\win32\main.exe
)

echo Gathering source files

setlocal enabledelayedexpansion
for /r %%f in (*.cpp) do (
	set a=%%f
	set a=!a:\=/!
	echo "!a!" >>build\win32\files.tmp
)
endlocal

setlocal
set PATH=%PATH%;C:/dev_resources/mingw32-4.9.2/bin/;C:/dev_resources/SFML-2.3.2_GCC-4.9.2/bin/;C:/dev_resources/thor-v2.0-mingw/bin/

echo Building
:: non-Thor:
::g++ -std=c++11 @build/win32/files.tmp -IC:/dev_resources/SFML-2.3.2_GCC-4.9.2/include -LC:/dev_resources/SFML-2.3.2_GCC-4.9.2/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -o build/win32/main.exe
::g++ -std=c++11 @build/win32/files.tmp -Wfatal-errors -IC:/dev_resources/SFML-2.3.2_GCC-4.9.2/include -IC:/dev_resources/thor-v2.0-mingw/include -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -LC:/dev_resources/SFML-2.3.2_GCC-4.9.2/lib -LC:/dev_resources/thor-v2.0-mingw/lib -lthor -o build/win32/main.exe
g++ -std=c++11 -O2 @build/win32/files.tmp -Wall -Wextra -pedantic -IC:/dev_resources/SFML-2.3.2_GCC-4.9.2/include -IC:/dev_resources/thor-v2.0-mingw/include -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system -LC:/dev_resources/SFML-2.3.2_GCC-4.9.2/lib -LC:/dev_resources/thor-v2.0-mingw/lib -lthor -o build/win32/main.exe


echo Running

build\win32\main.exe 

echo Cleanup

if exist build\win32\files.tmp (
	del build\win32\files.tmp
)

if exist build\win32\main.exe (
	del build\win32\main.exe
)

echo Done

endlocal