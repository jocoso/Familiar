# Familiar — Terminal Interface Plan

**Project:** Familiar  
**Focus:** Add a basic terminal interface with a title screen and initial options  
**Estimated time:** 2 hours maximum  
**Language:** C++17  

---

## 1. Objective

Create a simple terminal entry point for Familiar.

When the application starts, it should display:

- The Familiar title.
- A short welcome message.
- A small set of initial options.
- A prompt for user input.
- A way to exit cleanly.

This milestone should make the application feel usable from the terminal without adding major new domain behavior.

---

## 2. Initial menu

Display the following options:

```text
================================
           FAMILIAR
================================

Welcome to Familiar.

1. Projects
2. Tasks
3. Exit

Select an option:
```

Behavior:

- `1` — Display a placeholder message such as `Projects are not implemented yet.`
- `2` — Display a placeholder message such as `Tasks are not implemented yet.`
- `3` — Exit the application.
- Any other input — Display `Invalid option. Please choose 1, 2, or 3.` and show the menu again.

---

## 3. Development plan

| Phase | Activity | Time |
|---|---|---:|
| 1 | Review current entry point | 15 min |
| 2 | Create terminal interface structure | 30 min |
| 3 | Implement title screen and menu | 30 min |
| 4 | Handle user input and invalid choices | 25 min |
| 5 | Build, test, and clean up | 15 min |
| 6 | Document result | 5 min |
| **Total** | | **120 min** |

---

## Phase 1 — Review current entry point

**Time:** 15 minutes

**Tasks:**

- Locate the current `main()` function.
- Confirm how the application currently starts.
- Identify where project and task creation is currently demonstrated or tested.
- Decide whether the terminal interface should replace the current demonstration code or run before it.
- Ensure the project builds before making changes.

**Expected result:**  
You know the current startup flow and have a working baseline.

---

## Phase 2 — Create terminal interface structure

**Time:** 30 minutes

Create a small interface component directly in `main()`.

Suggested files:

```text
include/ui/TerminalInterface.hpp
src/ui/TerminalInterface.cpp
```


Keep the class small.

Do not create a full UI framework, command parser, or screen-management system.

---

## Phase 3 — Implement title screen and menu

**Time:** 30 minutes

Implement the title screen and main menu.

Use `std::cout` for output and keep the layout simple.



---

## Phase 4 — Handle user input and invalid choices

**Time:** 25 minutes

Use a loop so the menu remains visible until the user chooses to exit.

Read the user’s selection as an integer.

Handle invalid input safely:

- If input is not a number, clear the error state.
- Discard the invalid input.
- Ask the user to try again.
- Do not allow invalid input to crash or corrupt the input stream.

For numeric menu input, `std::cin >> choice` is appropriate. If input fails, use `std::cin.clear()` and `std::cin.ignore()` to recover the stream state. [11][15]

Example:

```cpp
int TerminalInterface::readMenuChoice() {
    int choice = 0;

    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n'
        );

        std::cout << "Invalid option. Please enter a number.\n";
        std::cout << "Select an option: ";
    }

    return choice;
}
```

Then validate the selected range:

```cpp
void TerminalInterface::handleChoice(int choice) {
    switch (choice) {
        case 1:
            std::cout << "\nProjects are not implemented yet.\n\n";
            break;

        case 2:
            std::cout << "\nTasks are not implemented yet.\n\n";
            break;

        case 3:
            std::cout << "\nGoodbye.\n";
            break;

        default:
            std::cout << "\nInvalid option. Please choose 1, 2, or 3.\n\n";
            break;
    }
}
```

---

## Phase 5 — Build, test, and clean up

**Time:** 15 minutes

**Tasks:**

- Rebuild the application.
- Run the terminal interface.
- Verify that the title and menu appear.
- Test option `1`.
- Test option `2`.
- Test option `3`.
- Test invalid input, such as `abc`, `0`, and `9`.
- Confirm that the application exits cleanly on option `3`.
- Remove temporary debugging output.

**Expected result:**  
The application starts, displays the menu, accepts valid input, rejects invalid input, and exits cleanly.

---

## Phase 6 — Document result

**Time:** 5 minutes

Record:

- The new terminal interface files.
- The available menu options.
- The current placeholder behavior.
- Any known limitations.
- The next suggested milestone.

---

## 4. Definition of done

This session is complete when:

- The application builds successfully.
- A title screen appears when the program starts.
- The initial menu displays `Projects`, `Tasks`, and `Exit`.
- Option `1` shows a placeholder response.
- Option `2` shows a placeholder response.
- Option `3` exits the application.
- Invalid input is handled without crashing.
- The existing domain classes still compile.
- No unrelated refactoring was introduced.

---

## 5. Out of scope

Do not implement during this session:

- Creating or editing projects.
- Creating or editing tasks.
- Persistent storage.
- Database integration.
- User authentication.
- Graphical user interface.
- Advanced terminal styling.
- Screen clearing or terminal-control libraries.
- Command-line arguments.
- Full menu navigation.
- A general-purpose UI framework.

---

## 6. Recommended next milestone

After the basic terminal interface works, the next milestone should be:

**Project menu with basic project creation and listing.**

At that point, option `1` can display a secondary menu such as:

```text
1. Create project
2. List projects
3. Back
```

Keep the interface simple and build one working workflow at a time.