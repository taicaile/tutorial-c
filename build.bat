@echo off

:: Get the current Git version
for /f %%i in ('git describe --tags --always') do set VERSION_INFO=%%i

echo VERSION_INFO: %VERSION_INFO%

echo gcc -v -DVERSION_INFO=\"%VERSION_INFO%\" sv.c -o a.exe -Wall -Wextra -pedantic
gcc -v -DVERSION_INFO=\"%VERSION_INFO%\" sv.c -o a.exe -Wall -Wextra -pedantic

a.exe
