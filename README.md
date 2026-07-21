# UE_CommonGameStarter

![Unreal Engine](https://img.shields.io/badge/Unreal%20Engine-5.8-black?logo=unrealengine)
![License](https://img.shields.io/badge/License-GPLv3-blue)
![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey)

A modular Unreal Engine starter framework for advanced Blueprint-first 3D game development.

> [!WARNING]
> This framework is currently in active development and is not considered production-ready yet.

---

## 🎮 Gameplay Features

| Feature | Description |
|---|---|
| Gameplay Loading Systems | Systems that can load gameplay primary assets and sub-levels |
| Starting Player BP | Ready-to-use Advanced Player Blueprint |
| Ragdoll Death Simulator | Ragdoll death effects without needing of animations |
| Advanced Object Interaction System | Flexible interaction between gameplay objects in the game world |
| Advanced AI System | A smart, developable AI system that aloows to have various detection layers and senses |
| Starting Modular Widget System | Developable Starting UI System for Unreal Widgets |

## 🛠️ Framework Features

| Feature | Description |
|---|---|
| Blueprintable Subsystem | Users can create subsystems only by Blueprint, without need of C++ |
| Actor Manager Registry Subsystem | Users can create actor type manager that other blueprint classes do not require Get Actor of Class to get the manager (Performance saving) |
| State Pattern | State Controllers inherited by various base classes (e.g. Actor Component, Game State) |
| Starting Blueprint Libraries | Started with Utility functions and macros made in Blueprint |

## ⚙️ Engine System Features

| Feature | Description |
|---|---|
| Startup Assets Preload System | Preload Startup Blueprint Assets that can be used for editor (e.g. Blueprintable Subsystems)|

---

# 🚀 Get Started

## 📋 Requirement

Before opening the project, make sure you have:

- Unreal Engine installed (tested with 5.7 at beginning then 5.8)
- Microsoft C++ Build Tools (MSVC v143 or compatible)
- Windows SDK 10/11

## 💻 Recommended IDE

- Visual Studio - 2022 for 5.7 or older, 2026 for 5.8 or newer (if possible)
- JetBrains Rider

---

# 📦 Installation

1. Download/clone this project.

2. Open file manager to locate this project.

3. Right click the .uproject file, select: **Generate Visual Studio project files**.
  
   (If this option is missing, see the resources section below)

4. Wait until the generation is finished.

5. Open the project, and the engine may ask you to build, choose Yes.

6. Once the build is complete, the project will launch automatically.

---

# 📝 Notes

> [!IMPORTANT]
> This project uses both Unreal Engine Blueprint and C++.
> 
> Therefore, you must generate project file before opening the project for the first time.

> [!NOTE]
> This project is currently developed and tested with Unreal Engine 5.7.
> 
> Other Unreal Engine 5 versions may work, but have not been thoroughly tested.
> 
> Compatibility of early Unreal Engine versions like Unreal Engine 3 or 4 are unknown.
> 
> Recommended for users already familiar with Unreal Engine 4 or 5 Blueprint workflows. Knowledge of Unreal Engine C++ is also beneficial.

---

# 🛠️ Project Architecture

- Blueprint-first workflow
- Modular gameplay systems
- State pattern implementation
- Blueprintable subsystem architecture
- Reusable gameplay libraries

---

# 📚 Resources

## Unreal Engine

- Unreal Engine Documentation  
  https://dev.epicgames.com/documentation/en-us/unreal-engine/

- Blueprint Visual Scripting  
  https://dev.epicgames.com/documentation/en-us/unreal-engine/blueprints-visual-scripting-in-unreal-engine

- Gameplay Framework Overview  
  https://dev.epicgames.com/documentation/en-us/unreal-engine/gameplay-framework-in-unreal-engine

- Setting Up Visual Studio for Unreal Engine  
  https://dev.epicgames.com/documentation/en-us/unreal-engine/setting-up-visual-studio-development-environment-for-cplusplus-projects-in-unreal-engine

- Programming with C++  
  https://dev.epicgames.com/documentation/en-us/unreal-engine/programming-with-cplusplus-in-unreal-engine

## Microsoft

- Visual Studio Download  
  https://visualstudio.microsoft.com/downloads/

- C++ Development Tools Installation Guide  
  https://learn.microsoft.com/en-us/cpp/build/vscpp-step-0-installation

---

# 🤝 Contributing

- Contributions, suggestions, and improvements are welcome.

- Please fork the repository and submit a pull request for review.

- Only repository maintainers and approved contributors can directly modify the main repository.

---

# 📄 License & Credits

## Programming

- Copyright(c) 2026 Nibour16

- License under the GNU General Public License v3.0

---

## Game Engine

- Unreal Engine

---

## Acknowledgements

- This project was developed with assistance from various learning resources. 

- Including ChatGPT (OpenAI) for development assistance, documentation support, technical discussions, and code references.
