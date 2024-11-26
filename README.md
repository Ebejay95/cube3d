![cub3d img](https://raw.githubusercontent.com/Ebejay95/cube3d/master/cub3d.gif)

# cub3D

**My First RayCaster with MiniLibX**

---

## Summary

**cub3D** is a ray-casting project inspired by the iconic Wolfenstein 3D game. This project challenges you to create a dynamic first-person view of a maze using ray-casting techniques. It combines algorithmic thinking, graphics rendering, and interactive user input to simulate a 3D environment.

---

## Features

### Core Functionality

- **Ray-Casting**:
  - Simulates a 3D perspective by calculating wall distances and rendering textures.

- **Textures and Colors**:
  - Assign different textures to walls based on orientation (N/S/E/W).
  - Customizable floor and ceiling colors.

- **Player Controls**:
  - **W/A/S/D**: Move through the maze.
  - **Left/Right Arrows**: Rotate the view.
  - **ESC**: Exit the program.
  - Red cross on the window closes the program.

- **Map Parsing**:
  - Reads `.cub` files for scene descriptions.
  - Ensures maps are properly closed by walls and meet format requirements.

### Bonus Features (Optional)

- **Enhanced Gameplay**:
  - Wall collision detection.
  - Minimap display.
  - Doors that open and close.
  - Animated sprites.
  - Mouse-controlled rotation.

- **Advanced Visuals**:
  - Floor and ceiling textures.
  - HUD and additional graphical elements.

---

## Structure

### Directories and Files

#### `src/`

- **`main.c`**:
  Initializes the game and handles the main game loop.
- **`raycasting.c`**:
  Implements the ray-casting algorithm for rendering.
- **`controls.c`**:
  Handles keyboard and mouse inputs for movement and interaction.
- **`map_parser.c`**:
  Parses `.cub` scene files and validates map configurations.
- **`utils.c`**:
  Includes helper functions for error handling and utility operations.

#### `includes/`

- **`cub3d.h`**:
  Declares function prototypes, defines game constants, and includes necessary libraries.

#### Bonus Files (Optional)

- **`bonus/`**:
  Contains additional files for handling bonus features such as minimaps, animations, and advanced controls.

### Key Files

- **Makefile**:
  Automates compilation with targets for mandatory and bonus parts:
  - `all`, `clean`, `fclean`, `re`, and `bonus`.

---

## Examples

### Mandatory Example

A simple `.cub` scene configuration:
NO ./path_to_the_north_texture SO ./path_to_the_south_texture WE ./path_to_the_west_texture EA ./path_to_the_east_texture F 220,100,0 C 225,30,0 111111 100101 101001 1100N1 111111

markdown
Code kopieren

### Command Line Usage

1. **Compile the Project**:
   ```bash
   make
Run cub3D:
bash
Code kopieren
./cub3D map.cub
Requirements
Mandatory Part
Program Name: cub3D
Input: A .cub file describing the map and scene elements.
Graphics Library: MiniLibX (system version or source).
Allowed Functions: open, close, read, write, printf, malloc, free, perror, strerror, exit, and math library functions (-lm).
Bonus Part
Add additional functionality such as wall collisions, minimaps, animated sprites, or HUD.
Map Specifications
Valid Characters:
0: Empty space.
1: Wall.
N/S/E/W: Player's starting position and orientation.
Texture Identifiers:
NO, SO, WE, EA: Path to wall textures.
F, C: Floor and ceiling colors in RGB format (e.g., 220,100,0).
Advanced Features
Wall Textures:

Load and render textures dynamically based on wall orientation.
Player Interactivity:

Navigate the maze using keyboard inputs.
Realistic wall collisions ensure a smooth gaming experience.
Bonus Examples:

Minimap visualization for better navigation.
Interactive doors and animated sprites for added immersion.
cub3D – Your gateway into the world of 3D graphics programming! 🚀
