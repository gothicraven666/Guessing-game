# 🎯 Number Guessing Game in C

A console-based number guessing game written in C that supports multiple difficulty levels, high score tracking per difficulty, and optional hints. Designed to help beginners practice conditionals, loops, file handling, and basic logic.

---

## 🕹️ How to Play

1. **Choose a difficulty level:**
   - `0` → Easy (1 to 50)
   - `1` → Medium (1 to 100)
   - `2` → Hard (1 to 200, 10 attempts max, includes a hint)

2. **Try to guess the randomly generated number.**
3. **Feedback is provided** after each guess: too high or too low.
4. **High scores** are tracked and saved separately for each difficulty in external `.txt` files.

---

## 🔧 Features

- 🧠 **Three Difficulty Modes** with different number ranges
- 🏆 **Persistent High Scores** saved in files like `highscore_easy.txt`, etc.
- 💡 **Hints in Hard Mode** after 5 incorrect attempts
- 🔁 **Replay Option** after each game
- 📂 **File Handling** using `fopen`, `fscanf`, `fprintf`
- 👨‍💻 **Beginner-friendly logic**, clean structure

---

## 🛠️ Compilation & Execution

### On Linux / Mac:

```bash
gcc guess_game.c -o guess_game
./guess_game
