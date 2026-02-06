# 🚀 Vector Chicken Invaders

A high-performance 2D arcade shooter built from scratch using **C++** and **SDL2**. This project serves as a practical implementation of game engine architecture, design patterns, and vector-based physics.

## 🎮 Gameplay Demo

https://github.com/user-attachments/assets/a5cd4e19-e779-4231-b0d6-045fdfaa5936



## 🕹️ Controls
Designed for an intuitive, mouse-driven arcade experience:
* **Aiming**: Rotate the cannon in a 360-degree radius by moving the **Mouse**.
* **Firing**: Launch projectiles by clicking the **Left Mouse Button**.
* **Movement**: The cannon's orientation is calculated in real-time based on your cursor's position.

---

## 🛠️ Technical Highlights

### 🏛️ Architecture & Design Patterns
* **Factory Method Pattern**: Utilized `clsChickenFactory` and `clsShotFactory` to encapsulate object creation. This decouples the game loop from entity instantiation, allowing for scalable waves of enemies.
* **Object Pool Pattern**: Implemented fixed-size arrays for shots (200 max) and chickens (7 max) to eliminate memory fragmentation and improve cache locality. Objects are reused by toggling `isActive`/`isAlive` flags rather than allocating/deallocating.
* **Manager Pattern**: The `clsGameField` acts as the central engine, coordinating physics updates, collision detection, and the rendering subsystem.
* **Game Loop & Timing**: Implemented `SDL_GetTicks()` to manage frame-independent logic, ensuring consistent fire rates and smooth entity updates regardless of CPU speed.

### 📁 Project Structure
* **include/** - Header files (.h) containing class declarations and interfaces
* **src/** - Implementation files (.cpp) with method definitions and game logic
* **Makefile** - Automated build system with dependency management and proper compilation flags

The project follows the standard C++ convention of separating interface from implementation, improving code organization and compilation efficiency.

### 📐 Physics & Math
* **Vector-Based Movement**: A custom `clsVector` class serves as the mathematical foundation for all position and velocity calculations.
* **Trigonometric Trajectories**: Projectile paths are calculated using `atan2`, `sin`, and `cos` to map mouse coordinates to precise firing vectors. The `calculateTrajectory()` method dynamically updates shot angles when retargeted.
* **AABB Collision Detection**: Implemented Axis-Aligned Bounding Box (AABB) checks via `SDL_HasIntersection` for efficient collision detection.

### 💾 Data Structures & Memory Management
* **Fixed-Size Object Pools**: 
  - `clsShot allShots[200]` - Pre-allocated shot objects
  - `clsChicken allChickens[7]` - Pre-allocated chicken objects
  - Objects are reused during gameplay, avoiding memory allocation/deallocation overhead
  
* **Fragmentation Prevention**: By using fixed-size arrays instead of dynamic allocations, the game maintains stable performance without memory fragmentation buildup during gameplay.

* **Encapsulation & Accessors**: Comprehensive getter and setter methods for all critical properties:
  - **clsShot**: width, height, startPosition, targetPosition, texture, isActive
  - **clsChicken**: width, height, position, texture, isAlive
  - **clsShotFactory & clsChickenFactory**: maxShots, maxChickens (static properties)

* **Proper Initialization**: Default constructors properly initialize all pooled objects to prevent undefined behavior with uninitialized pointers and values.

---

## � Recent Improvements

### Memory & Performance Optimization
* **Object Pooling Implementation**: Replaced dynamic `std::list` with fixed-size arrays to achieve:
  - Zero memory fragmentation during gameplay
  - Improved CPU cache locality
  - Predictable, constant memory usage
  - Eliminated allocation/deallocation overhead per shot/chicken
---

### Prerequisites
Ensure you have the SDL2 development libraries installed on your Ubuntu/Linux system:

```bash
sudo apt update
sudo apt install libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev 
``` 

### Installation & Build

1. **Clone the repository:**
```bash
git clone https://github.com/Ahmed-Gamal24/Chicken-Invaders-Game.git
cd Chicken-Invaders-Game
``` 

2. **Compile the project**

```bash
make 
``` 

3. **Run the game:**

```bash
./chicken_invaders
``` 

# Chicken-Invaders-Game
