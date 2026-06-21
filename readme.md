# Strategy Pattern Performance Evaluation

## About the Project
This is a small educational project I created to support a presentation/report on Design Patterns, with a strong focus on the **Strategy Pattern**. 

The main goal of this benchmark is to demonstrate the performance overhead caused by dynamic dispatch (**vtable**) when using the Strategy Pattern. By comparing the algorithm execution time using polymorphism versus traditional conditional logic (`if-else` or `switch`). It helps developers clearly see the trade-offs between clean, maintainable object-oriented architecture and raw execution speed.

**Project Details & Tech Stack:**
- **Language:** C++
- **Core Concepts:** Strategy Pattern, Polymorphism, Virtual Table (vtable) overhead
- **Benchmarking Technique:** Measuring and comparing execution times of different approaches (Strategy vs. traditional conditions) over large datasets.

## Project Structure
```text
Strategy Pattern Performance Evaluation/
├── evaluate_Strategy_pattern_performance.cpp
└── readme.md
```

## Getting Started
Follow these instructions to get a copy of the project up and running on your local machine.

### Prerequisites
- A C++ compiler (e.g., GCC, Clang, or MSVC) supporting C++11 or higher.

### Installation & Execution
1. **Clone the repository:**
   ```bash
   git clone https://github.com/HieuStudyingCS/Strategy-Pattern-Performance-Evaluation.git
   ```

2. **Navigate to the project folder:**
   ```bash
   cd "Strategy Pattern Performance Evaluation"
   ```

3. **Compile the code:**
   ```bash
   g++ -o evaluate_performance evaluate_Strategy_pattern_performance.cpp
   ```

4. **Run the executable:**
   - On Windows:
     ```bash
     .\evaluate_performance.exe
     ```
   - On Linux / macOS:
     ```bash
     ./evaluate_performance
     ```

## Contributing
Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. We use **Conventional Commits** for our commit messages. 

### Commit Conventions
Please follow these prefixes when making a commit:
- `feat:` for new features (e.g. adding a new sorting algorithm)
- `fix:` for bug fixes
- `docs:` for documentation changes
- `style:` for formatting changes (missing semicolons, etc.)
- `refactor:` for refactoring production code
- `test:` for adding missing tests
- `chore:` for updating build tasks, settings, etc.

*Example:* `feat: add insertion sort algorithm`

## Contact
If you have any questions or want to collaborate, feel free to reach out:

- **Email:** letronghieu09012007@gmail.com
- **Github:** [HieuStudyingCS](https://github.com/HieuStudyingCS)
- **LinkedIn:** [Le Trong Hieu](https://www.linkedin.com/in/1lth/?locale=vi)
