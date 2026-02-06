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
* **Manager Pattern**: The `clsGameField` acts as the central engine, coordinating physics updates, collision detection, and the rendering subsystem.
* **Game Loop & Timing**: Implemented `SDL_GetTicks()` to manage frame-independent logic, ensuring consistent fire rates and smooth entity updates regardless of CPU speed.

### 📐 Physics & Math
* **Vector-Based Movement**: A custom `clsVector` class serves as the mathematical foundation for all position and velocity updates.
* **Trigonometric Trajectories**: Projectile paths are calculated using `atan2`, `sin`, and `cos` to map mouse coordinates to precise firing vectors.
* **AABB Collision Detection**: Implemented Axis-Aligned Bounding Box (AABB) checks via `SDL_HasIntersection` for efficient $O(n \times m)$ hit detection.



### 💾 Data Structures & Memory Management
* **Node-Based Entity Management**: Built using `std::list<T*>` to ensure $O(1)$ complexity for frequent insertions and deletions. This approach avoids the "shifting" overhead of contiguous arrays, making it ideal for high-speed arcade shooters.
* **Fragmentation Resistance**: By utilizing a linked list, the game maintains stable performance during intense gameplay by avoiding memory fragmentation and reallocations common in dynamic arrays.
* **Manual Lifecycle Control**: Carefully managed heap-allocated objects through a list of pointers. This allows for polymorphic behavior (supporting different chicken types) while ensuring manual memory cleanup to prevent leaks.

---

## 🚀 Getting Started

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
