Space Invaders (C++ / SFML 3.1)

A classic Space Invaders clone built from scratch in modern C++17, using SFML 3.1 and object-oriented design principles. Built incrementally as a milestone-based learning project to practice clean software architecture in a real game.
Features
Main menu with keyboard navigation
Player movement and shooting (frame-rate independent, delta-time based)
Enemy formation with classic side-to-side + step-down movement
Enemy shooting on a randomized timer
Rectangle-based collision detection between bullets, enemies and the player
Score tracking and a lives/game-over system
Clean state-machine architecture (Menu / Playing / Game Over)
Tech Stack
Language: C++17
Library: SFML 3.1 (Graphics, Window, System)
Build system: CMake (also runnable directly as a Visual Studio project)
Paradigm: Object-Oriented Programming
Architecture

The project follows a state-machine design with clear separation of responsibilities across small, focused classes:

Game            -- owns the window, runs the main loop, owns the active state
GameState       -- abstract interface: MenuState, PlayingState, GameOverState
Player          -- player ship: input, movement, bounds
Enemy / EnemyManager -- individual enemy + the formation that moves them as a group
Bullet / BulletManager / EnemyBulletManager -- player and enemy projectiles
CollisionManager -- resolves overlaps between bullets, enemies and the player
ScoreManager    -- tracks the current run's score
UI              -- on-screen score/lives display
AssetManager    -- loads and shares the font

State transitions use a "pending state" pattern: a state change is requested via Game::changeState() and applied at the start of the next frame, rather than immediately -- this avoids destroying a GameState object while one of its own member functions is still executing.

Build
CMake
bash
mkdir build && cd build
cmake ..
cmake --build .
Visual Studio

Open the project, point Include/Library directories to your SFML 3.1 installation, and build with Ctrl+Shift+B.

Required assets

Not included in the repo (add your own):

assets/fonts/arial.ttf   -- any TrueType font
Controls
Key	Action
Left / Right	Move the player ship
Space	Fire
Up / Down	Move menu selection
Enter	Confirm menu selection
What I learned

This project was built milestone by milestone as a hands-on exercise in:

Structuring a real-time application around a game loop and delta time
Designing a state machine with polymorphism instead of if/else chains
Managing object lifetimes with std::unique_ptr and std::vector instead of manual new/delete
Separating rendering, input handling, and game logic into single- responsibility classes
