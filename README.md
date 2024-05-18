# ImGUI_App

## Build Debug

mkdir build

cd build

cmake -G "MinGW Makefiles"  -DCMAKE_BUILD_TYPE=Debug ..

cmake --build . 
 
## Build Release

mkdir build

cd build

cmake -G "MinGW Makefiles"  -DCMAKE_BUILD_TYPE=Release ..

cmake --build .

