🎮 Hangman SDL2 Game

A fun Hangman game built with C++ and SDL2, featuring background music, sound effects, hints, word category selection, and difficulty modes.

📜Create by: Đinh Quang Duy - 24022638

📋 Features

🔥 Smooth and colorful SDL2-based graphics.

🎵 Background and menu music, plus sound effects for guesses and game results.

🧠 Hints available during gameplay (press Space).

⚡ Time-limited gameplay (default: 60 seconds).

🌍 Choose categories like Fruits, Jobs, Countries, and more.

🛡️ Easy and Hard difficulty modes.


🛠 Requirements

C++17 or higher

SDL2

SDL2_image

SDL2_ttf

SDL2_mixer


📂 Project Structure

├── main/

│   ├── hangman.cpp        # Main game loop and initialization

│   ├── GameLogic.cpp      # Core gameplay logic

│   ├── GameLogic.h

│   ├── draw.cpp           # Drawing images and text

│   ├── draw.h

│   ├── windows.cpp        # Window and renderer handling

│   ├── windows.h

│   ├── diff.cpp           # Word selection and difficulty

│   ├── diff.h

│

├── word/                  # Word list files (e.g., all.txt, fruits.txt)

├── image/                 # Game images (e.g., hangman stages, menu background)

├── sound/                 # Sound effects and music (e.g., background.mp3, found.wav)

├── Font.ttf               # Font file

└── README.md



🚀 How to Run


1.Make sure you have SDL2 libraries installed.

2.Run the game: 

+ Open Terminal using Ctrl+J in Vs Code and type "make"

+ Run directly from the .exe application

🎮 Controls

Action	|                     Key

Guess a letter	|            Press the corresponding key

Use a hint   |       	      Press Space

Exit during game/menu	  |    Press ESC

Confirm / Continue	 |       Press Enter


💬 Notes

If background music or sounds do not load, check that the audio files exist in the sound/ folder and are properly formatted.
Word lists for each category are stored in word/ folder as text files.
Make sure all resources (fonts, images, sounds) are correctly placed relative to the executable.

📷 Game Demo Video :
https://github.com/user-attachments/assets/94e1dddd-c13b-4fc5-8224-a42e36694735

.
