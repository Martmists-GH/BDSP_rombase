# BDSP Mod Base

This repository is a base for BDSP mods based on Sigma Platinum, but free to use by anyone under the terms of the [BSD-3-Clause license](./LICENSE).

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

### Installation

1. Build the project using cmake
2. Copy the built files, or use the existing copy/ftp tasks from cmake.
3. Put `romfs/shaders/imgui.bin` at `sdmc:/shaders/imgui.bin` (or the equivalent for emulators)

### License

This project is licensed under the terms of the [BSD-3-Clause license](./LICENSE). 
This means you can use this code in your own projects, but you must include the license file in your project. 
Additionally, on each site where you distribute a modified version of this code, you must:
- make it clear that the code has been modified, 
- include a link to the original code, and 
- include the contents of the license file.

You must repeat this for the projects mentioned in [NOTICE](./NOTICE) as well.


The authors of this project also wish to discourage others from sub-licensing derivative works under copyleft licenses, such as the GPL, as to encourage the open sharing of code.