@echo off

mkdir .\build
pushd .\build

set INC=..\include

if "%1"=="Test" (
	cl /I%INC% -EHsc -Zi ..\test\test.cpp ..\test\timer.cpp ..\src\vec2_math.cpp ..\src\my_string.cpp /Wall
)

if "%1"=="Release" (
	cl /I%INC% -EHsc -Zi ..\src\hellsing.cpp ..\src\vec2_math.cpp ..\src\vec3_math.cpp /Wall
)

popd

if "%1"=="Clean" (
	rmdir /s .\build\
)