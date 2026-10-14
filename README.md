# Familiar

**A productivity companion for navigating projects, overcoming task initiation barriers, and making progress one step at a time.**

Familiar is an open-source productivity application inspired by the familiar mechanic in Dungeons & Dragons. It explores a different approach to productivity: instead of relying on willpower, rigid schedules, or overwhelming task lists, Familiar aims to help users identify their next actionable step and make progress at a sustainable pace.

The project is designed with people who experience difficulties with focus, task initiation, organization, working memory, motivation, and maintaining momentum. These challenges can arise for many reasons, including ADHD, anxiety, depression, stress, burnout, and other personal or environmental circumstances.

Rather than treating productivity as a measure of discipline or personal worth, Familiar approaches it as a process that should adapt to the individual.

The goal is simple:

**Help users turn overwhelming projects into manageable actions, regain their bearings when they lose momentum, and move forward without unnecessary pressure.**

<img width="524" height="443" alt="Familiar application preview" src="https://github.com/user-attachments/assets/5460e2ea-1636-4d28-88a1-cf94d0f2516b" />

---

## Table of Contents

- [Why Familiar?](#why-familiar)
- [Design Philosophy](#design-philosophy)
- [Planned Features](#planned-features)
- [Mental Health and Accessibility](#mental-health-and-accessibility)
- [Technology](#technology)
- [Project Structure](#project-structure)
- [Getting Started](#getting-started)
- [Roadmap](#roadmap)
- [Contributing](#contributing)

---

## Why Familiar?

Many productivity systems assume that users can consistently:

- Identify what needs to be done.
- Break large projects into manageable tasks.
- Prioritize competing responsibilities.
- Begin working without significant difficulty.
- Remember where they left off.
- Maintain attention over time.
- Recover quickly after interruptions.

For some people, these expectations create additional friction rather than reducing it.

A person may understand exactly what needs to be done and still struggle to begin. A large project may feel too ambiguous to approach, an extensive task list may increase cognitive overload, or returning to unfinished work may require reconstructing hours of lost context.

Familiar aims to address these challenges by reducing the amount of planning, decision-making, and mental effort required to take the next step.

Instead of asking users to manage everything at once, Familiar centers the experience around two questions:

**What are we working on?**

**What's the next thing we can do?**

The intention is not to eliminate planning or long-term organization. It is to make those activities more manageable and help users translate intentions into actions.

## Design Philosophy

Familiar is guided by several core principles.

### 1. No Judgment

Missing a goal, abandoning a task, or taking an extended break should not result in punishment or shame.

Familiar should behave like a supportive companion: helping users understand their current situation, identify a reasonable next step, and resume work when they are ready.

Progress should be encouraged without implying that productivity determines personal worth.

### 2. Reduce the Activation Energy

Large or ambiguous tasks can be difficult to begin.

For example:

**Original task:**
> Write my research paper.

Familiar could help transform it into a sequence of smaller actions.

**Quest: Research Paper**

1. Open the document.
2. Write the title.
3. Find one relevant source.
4. Write three notes.
5. Take a short break.

The objective is to make the first action small enough to begin without requiring the user to complete the entire project immediately.

Tasks can then be expanded or adjusted as the project develops.

### 3. One Step at a Time

Presenting an extensive list of unfinished work can increase the feeling of being overwhelmed.

Familiar aims to make the immediate next action easy to identify while keeping the larger project accessible when needed.

For example:

**Current Quest**

Open your project document.

After completing that action:

**Next Step**

Write three ideas for your introduction.

The user retains visibility into the larger objective without having to mentally process every outstanding task at once.

### 4. Flexible Productivity

Energy, attention, and available time vary from day to day.

Familiar should not assume that users can maintain a constant level of productivity.

A future version could let users indicate how they are feeling:

**How are you doing today?**

- 🟢 Plenty of energy
- 🟡 Somewhat focused
- 🟠 Struggling to get started
- 🔴 Overwhelmed

Recommendations could then adapt to the user's stated capacity.

For example:

**Plenty of energy:** Work on the next major feature.

**Feeling overwhelmed:** Open the project and identify one small task.

The purpose is to make progress more accessible, not to pressure users into doing more than they can reasonably manage.

---

## Planned Features

The following features represent potential directions for Familiar's development. They are design goals rather than a claim that every feature is currently implemented.

### Task Decomposition

Familiar aims to help users transform large, ambiguous objectives into smaller, actionable tasks.

For example, the objective *Build my portfolio* could become:

Build Portfolio | +-- Choose Projects | +-- Identify project one | +-- Identify project two | +-- Identify project three | +-- Create Portfolio Structure | +-- Create homepage | +-- Add projects section | +-- Add contact section | +-- Publish


Task decomposition should reduce cognitive load rather than produce another overwhelming list.

Users should be able to adjust the resulting tasks to match their needs, preferences, and available resources.

### The Next Step System

Familiar could offer a dedicated focus view that emphasizes one recommended action at a time.

+----------------------------------+ | Your Familiar | | | | Current Quest: Portfolio | | | | Your Next Step: | | | | Open your project folder. | | | | [ Done ] [ Not Yet ] | +----------------------------------+


This approach keeps attention on the next actionable step rather than the entire workload.

The larger project remains available, but users do not need to navigate it continuously to make progress.

### Gentle Focus Sessions

Focus sessions should be customizable rather than requiring everyone to follow a fixed productivity technique.

Potential session lengths include:

- 5 minutes
- 10 minutes
- 15 minutes
- 25 minutes
- 45 minutes
- A custom duration

Users should also be able to indicate when focusing is difficult and choose a smaller objective instead.

Breaks should be treated as a normal part of the workflow, not as interruptions that need to be justified.

### Easy Recovery

Losing momentum should not mean losing progress.

Whether a user steps away for several hours or several days, Familiar should make returning to unfinished work straightforward.

For example:

**Welcome back!**

You were working on:

*Add authentication.*

Last completed:

- Create the login form.

Suggested next step:

- Connect the login form to the server.

The goal is to make resuming work easier than reconstructing the entire plan from memory.

### Context Restoration

Returning to a project can require remembering decisions, unfinished work, and the reasoning behind previous actions.

Familiar could maintain a lightweight record of project context.

For example:

**Current Project:** Book Club Application

**Last worked on:** Authentication

**Completed:**
- Login page
- Registration form

**Current task:** Session handling

**Next step:** Test login persistence.

**Notes:** Investigate cookie configuration.

This information would help users recover their place in a project without having to reconstruct the entire context themselves.

### Brain Dump Mode

Sometimes organizing thoughts is itself a barrier to getting started.

A brain dump feature could allow users to record unstructured thoughts, responsibilities, and reminders without organizing them beforehand.

For example:

> I need to finish my resume, email my professor, fix the login page, buy groceries, and finish that assignment.

Familiar could help organize these items into categories such as:

- Education
- Career
- Development
- Personal

The principle is straightforward: users should not need to organize everything before receiving help organizing it.

### Familiar Personalities

Different users may prefer different communication styles.

Familiar could offer customizable personalities, including:

- 🦊 Encouraging
- 🐱 Calm
- 🐉 Motivational
- 🦉 Analytical
- 🐕 Friendly
- 🐸 Playful
- 🐢 Patient

For example:

**Encouraging**
> You've already completed two steps. Let's tackle one more.

**Calm**
> No rush. Let's find the smallest next step.

**Playful**
> A wild task appeared! Let's see how we can tackle it.

Users should be able to choose the interaction style that feels most comfortable and useful to them.

---

## Mental Health and Accessibility

Familiar is intended to support organization and productivity. It is not designed to diagnose, treat, or replace professional mental health care.

The project recognizes that productivity can be influenced by many factors, including attention, energy, stress, environment, workload, and individual circumstances.

Its design should avoid language or mechanics that imply:

- People are lazy when they struggle to begin.
- Difficulty with productivity reflects a lack of discipline.
- Personal worth depends on completed tasks.
- Missing a goal represents a moral failure.
- Everyone should work in the same way.
- Greater productivity is always the appropriate objective.

Familiar should encourage users to seek professional support when appropriate without attempting to function as a therapist or medical treatment.

### Anti-Shame Design

Productivity mechanics should be evaluated for their potential to create unnecessary pressure.

Features requiring particular care include:

- Punishments for missed goals.
- Aggressive streak systems.
- Shame-based notifications.
- Failure-oriented messaging.
- Productivity leaderboards.
- Comparisons between users.
- Excessive notifications.
- Artificial urgency.
- Constant productivity scoring.

Gamification can make progress engaging, but it should support the user's goals rather than make the user feel accountable to an arbitrary system.

The familiar should feel like a companion, not another source of pressure.

### Progress Without Pressure

Progress does not always mean finishing a task.

Familiar could recognize other meaningful actions, including:

- Starting a difficult task.
- Returning to an unfinished project.
- Completing one small step.
- Asking for help.
- Taking a needed break.
- Making progress after feeling stuck.

Recognizing these actions could help users develop a more flexible and sustainable relationship with productivity.

### Accessibility as a Design Principle

Accessibility should inform the application from the beginning rather than being treated as a later enhancement.

Potential areas of focus include:

- Clear and predictable navigation.
- Minimal unnecessary interaction.
- Readable text and consistent visual hierarchy.
- Keyboard accessibility.
- Customizable interaction styles.
- Flexible task and session management.
- Clear recovery from interruptions.
- User control over reminders and notifications.

The objective is to make Familiar useful to people with different needs, preferences, and working styles.

---

## Technology

Familiar is currently being developed primarily in **C++**, with an emphasis on modular design and maintainable application architecture.

The project is organized around separate components for application coordination, terminal interaction, domain models, and persistence.

Development infrastructure includes:

- A Makefile-based build workflow.
- Modular source and header files.
- A dedicated testing directory.
- Project documentation.
- Sample and supporting resources.

The specific implementation and availability of individual features will evolve as development progresses.

## Project Structure

The repository currently follows a modular structure similar to the following:

familiar/ ├── include/ │ ├── domain/ │ ├── persistence/ │ └── ui/ ├── src/ │ ├── ui/ │ ├── main.cpp │ ├── Familiar.cpp │ ├── Project.cpp │ ├── ProjectManager.cpp │ ├── Task.cpp │ ├── User.cpp │ └── ErrorHandler.cpp ├── Assets/ ├── docs/ ├── sample/ ├── tests/ ├── Makefile └── README.md


The exact directory contents may change as the application develops.

### Key Components

**`include/` and `src/`**

Contain the application's declarations and implementations, organized by responsibility.

**`domain/`**

Contains domain models representing application concepts such as projects, tasks, and users.

**`persistence/`**

Contains components responsible for project persistence and related data operations.

**`ui/`**

Contains the terminal interface and user-interaction logic.

**`Assets/`**

Contains project resources and supporting assets.

**`docs/`**

Contains project documentation and design notes.

**`sample/`**

Contains sample resources and examples.

**`tests/`**

Provides a location for automated tests and behavior verification.

**`Makefile`**

Defines common development commands for compiling, running, and cleaning the application.

---

## Getting Started

### Prerequisites

Building Familiar currently requires:

- A C++ compiler with C++17 support.
- GNU Make.
- Git.

The instructions below assume a Unix-like development environment with `g++` and `make` installed.

### Installation

Clone the repository:

git clone https://github.com/jocoso/familiar.git cd familiar


Build the application:

make


Run Familiar:

make run


Clean generated build artifacts:

make clean


The included Makefile provides the primary development workflow.

As the project evolves, additional setup instructions and dependencies may be documented here.

---

## Roadmap

Familiar is an evolving project. Potential areas of future development include the following.

### Core Functionality

- [ ] Project management.
- [ ] Task creation and organization.
- [ ] Project selection and navigation.
- [ ] Task completion tracking.
- [ ] Persistent project and task data.
- [ ] Improved input validation and error handling.

### Focus and Organization

- [ ] Task decomposition.
- [ ] Next Step focus mode.
- [ ] Brain dump and task organization.
- [ ] Context restoration.
- [ ] Project notes and memory.
- [ ] Project progress tracking.

### Personalization

- [ ] Customizable familiar personalities.
- [ ] Custom familiar creation.
- [ ] Adjustable task difficulty.
- [ ] Flexible focus sessions.
- [ ] Optional reminders.
- [ ] Customizable break schedules.

### Accessibility and User Experience

- [ ] Focus-friendly interaction patterns.
- [ ] Improved keyboard accessibility.
- [ ] Reduced cognitive overhead.
- [ ] Flexible navigation and presentation.
- [ ] Non-judgmental progress tracking.

### Advanced Features

- [ ] Optional AI-assisted planning.
- [ ] Intelligent task decomposition.
- [ ] Adaptive recommendations.
- [ ] Gamified progression.

These items are potential development goals, not guarantees or commitments to specific release dates.

---

## Contributing

Contributions, suggestions, and constructive feedback are welcome.

Familiar is built around the idea that technology should help people navigate difficulties without adding unnecessary pressure.

Contributions are particularly valuable when they improve:

- Accessibility and inclusive design.
- Executive-function support.
- Task organization and project management.
- Focus assistance.
- User experience.
- Error handling and application reliability.
- Testing and documentation.
- Non-judgmental productivity mechanics.

When proposing a feature, consider whether it genuinely reduces friction for the user or introduces another system they must manage.

Small, focused improvements are welcome alongside larger architectural contributions.

---

## Project Status

Familiar is under active development. Its current implementation focuses on establishing the application's core structure and project-management functionality.

Many of the focus-support, personalization, and adaptive-planning concepts described in this README are planned directions rather than completed features.

The project will continue to evolve as its architecture, functionality, and design principles mature.

---

## Philosophy

Familiar is built on a simple belief:

**You don't need to have everything figured out to take the next step.**

Sometimes progress means completing a major milestone. Sometimes it means opening a document, writing one sentence, or finding your place again after a difficult week.

Both matter.

Familiar aims to make those next steps easier to find, easier to begin, and easier to return to.

A few recommendations before publishing

The README is now more structured and professional, but I recommend three additional considerations.

    Keep the roadmap aligned with the code. I've labeled many features as planned and described the current implementation conservatively. Update the project-status section as functionality becomes available. Avoid marking roadmap items complete until they're implemented and tested.

    Consider adding a license. If you want Familiar to be an open-source project, adding a LICENSE file will clarify how other people may use, modify, and distribute the code. MIT and Apache-2.0 are common choices, depending on your goals.

    Consider adding screenshots as the UI develops. Your existing image gives visitors a visual introduction. Additional screenshots showing project creation, task selection, or the focus interface would make the README more informative as those features become available.

One final thought: Familiar's strongest differentiator is not that it is another task manager, but that it is being designed around the difficulty of beginning and resuming work. I'd keep that message prominent throughout the README. It gives the project a clear identity and helps potential contributors understand what makes it worth building.