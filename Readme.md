PDCurses WebAssembly Demo
This project demonstrates how to compile a basic PDCurses application to WebAssembly using Emscripten.

Live Demo
Visit the live demo to see the application in action.

Description
This is a simple "bouncing text" demo built with:

PDCurses for text-based UI
Emscripten for WebAssembly compilation
SDL2 as the PDCurses backend
The application displays a bouncing "Hello, PDCurses!" message inside a bordered window.

Development Setup
Prerequisites
Emscripten SDK
SDL2 and SDL2_ttf development libraries
A TrueType font (DejaVuSansMono.ttf is used by default)
Building Locally
Clone this repository:
git clone https://github.com/yourusername/your-repo-name.git
cd your-repo-name
Run the setup command to download PDCurses and prepare assets:
make setup
Build the application:
make
Run locally with:
make run
Structure
main.c - The main application code with the bouncing text demo
Makefile - Build configuration
shell.html - Custom HTML template for the WebAssembly output
.github/workflows/build-and-deploy.yml - GitHub Actions workflow for automatic building and deployment
GitHub Pages Deployment
This project is automatically built and deployed to GitHub Pages using GitHub Actions. Any push to the main branch will trigger a new build and deployment.

License
[Choose an appropriate license for your project]

Acknowledgments
PDCurses - Public domain curses library
Emscripten - LLVM to WebAssembly compiler
