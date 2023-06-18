# ExLaunch - Luminescent

This repository contains a fork of Martmists-GH's [BDSP_rombase](https://github.com/Martmists-GH/BDSP_rombase), a base for BDSP mods based on Sigma Platinum. This mod base is free to use by anyone under the terms of the [BSD-3-Clause license](./LICENSE).

It has been modified to be used for Pokémon Luminescent.

### Features

- Debug UI (ZL + ZR)
- Logging over WI-FI or to the Debug UI
- Custom save data with migration tools built in
- Dex expansion
- Infinite TMs
- Custom Key Items
- Button remapping for a few actions
- Support specifying forms in wild encounter tables
- Exp. Share as item
- Friendship toggle as flag (1753)
- Custom menu settings
- Element inspector for Unity transforms
- 2-button poketch

### Installation
Installation requires Linux or a WSL instance for the building process.

1. Clone the repository and its submodule using `git clone --recurse-submodules https://github.com/TeamLumi/Luminescent_ExLaunch.git`.
2. Build the project using `cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE:STRING="Debug" -DCMAKE_INSTALL_PREFIX:PATH="out/install/WSL-GCC-Debug" -DCMAKE_TOOLCHAIN_FILE:FILEPATH="cmake/toolchain.cmake" -Bbuild`.
3. In the `build` directory, make the RomBase target with `make RomBase`.
4. Again, in the `build` directory, make the RomBase_release_x target with `make RomBase_release_x` where x is yuzu, ryujinx, or atmosphere. The only difference between all these targets should be the directory structure of the output.
5. Copy the built files from the corresponding directory in `build/RomBase_Diamond_releases`, or use the existing copy/ftp tasks from cmake.
6. Put `embedded_files/shaders/imgui.bin` at `sdmc:/shaders/imgui.bin` (or `sdcard/shaders/imgui.bin` for Ryujinx)
<br>
After the initial installation, only steps 4-6 need to be repeated to rebuild the mod.

### License

This project is licensed under the terms of the [BSD-3-Clause license](./LICENSE). 
This means you can use this code in your own projects, but you must include the license file in your project. 
Additionally, on each site where you distribute a modified version of this code, you must:
- make it clear that the code has been modified, 
- include a link to the original code, and 
- include the contents of the license file.

You must repeat this for the projects mentioned in [NOTICE](./NOTICE) as well.


The authors of this project also wish to discourage others from sub-licensing derivative works under copyleft licenses, such as the GPL, as to encourage the open sharing of code.

### Credits

- Martmists-GH - The initial [BDSP_rombase](https://github.com/Martmists-GH/BDSP_rombase) repository
- shadowninja108 - The initial [exlaunch](https://github.com/shadowninja108/exlaunch) repository
- craftyboss - The [scarlet-exlaunch-base](https://github.com/craftyboss/scarlet-exlaunch-base) repository, with minor modifications that have been made to make IMGui work on BDSP
