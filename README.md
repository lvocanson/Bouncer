# Bouncer

**Bouncer** is a C++ project designed to practice encapsulation. The application displays circles that bounce off the edges of the window. Clicking a circle makes it disappear and increases the score, which is shown in the top-left corner below the FPS. As the game progresses, new circles appear more quickly, up to a maximum of 50 circles on screen at once.

## Cloning and Opening the Project in Visual Studio

1. Clone the repository with its submodules:

   ```bash
   git clone https://github.com/lvocanson/Bouncer.git --recursive
   ```

2. Open the `Bouncer.sln` solution file located at the root of the repository.

3. Build the project in Visual Studio using your desired configuration (Debug/Release).

That's it!

## Compilation and Library Configuration

### Graphics Library Selection

To set the default graphics library, define one of the following macros during compilation:

- `USE_SDL`: Defaults to **SDL**.
- `USE_RAYLIB`: Defaults to **raylib**.

If `FORCE_LIB` is defined, the library choice will be locked and cannot be overridden at runtime.

### Changing the Library at Runtime

If `FORCE_LIB` is not defined, you can switch the graphics library at runtime using the following command line arguments:

- `--SDL`: Switch to **SDL**.
- `--Raylib`: Switch to **raylib**.
