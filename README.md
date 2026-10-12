# Familiar

A virtual familiar for people who want help navigating projects, tasks, and focus. Especially when getting started is simple.
Familiar is a productivity companion inspired by the familiar mechanic in Dungeons & Dragons.
Instead of treating productivity as a matter of willpower, Familiar is designed around a more productive idea:
Sometimes the hardest part of a task is doing the work and getting started. This app was made with people 
who struggle with focus, task initiation, organization, working memory, overwhelm, motivation, and 
maintaining momentum for many different reasons. These difficulties can be associated with conditions such as ADHD, 
anxiety, depression, stress, burnout, or other mental and cognitive challenges.


It acts as a virtual companion that helps users organize projects, break overwhelming goals into smaller steps, 
and focus on what they can do right now.

<img width="524" height="443" alt="image" src="https://github.com/user-attachments/assets/5460e2ea-1636-4d28-88a1-cf94d0f2516b" />


# Why Familiar?

Many productivity systems assume that the user can:

Decide what needs to be done.
Break large projects into reasonable tasks.
Prioritize those tasks.
Start working immediately.
Remember what they were doing.
Maintain attention.
Recover quickly after getting distracted.

For someone struggling with focus, these assumptions can make productivity systems feel like another source of failure.
A user may know exactly what they need to do and still be unable to start. Sometimes the problem is task initiation, 
executive functioning, cognitive overload, emotional resistance, or simply having too many things competing for attention 
at once.

Familiar aims to address the problem by asking a smaller question:

"Are we working on something already started?"
"What's the next thing we can do?"

Design Philosophy

Familiar is built around several principles.

1. No judgment

Missing a task shouldn't result in punishment, shame, or a message implying that the user failed.
The familiar should respond more like a supportive companion offering ways to get the task done.


2. Reduce the activation energy

A task such as:

Write my research paper. can feel enormous.

Familiar should help transform it into:

Quest: Research Paper

1. Open the document.
2. Write the title.
3. Find one source.
4. Write three notes.
5. Take a short break.


The objective is to make the user complete the entire project immediately or the first action small enough to begin.

3. One step at a time

When someone is overwhelmed, showing them 30 tasks may make the problem worse.

Familiar should be capable of presenting:

Current Quest

 Open your project document.


After completion:

Next Quest

 Write three ideas for your introduction.


The user can still see the larger project when they need it, but they don't have to mentally process everything at once.

4. Flexible productivity

Not every day has the same amount of available energy or focus.

Familiar should avoid assuming that productivity is constant.

A user might select a current state such as:

How are you doing?

🟢 Plenty of energy
🟡 Somewhat focused
🟠 Struggling
🔴 Overwhelmed


Familiar can then adjust the difficulty of recommended tasks.

For example:

🟢 Plenty of energy

Work on the next major feature.


versus:

🔴 Overwhelmed

Open the project.

That's it for now.

## Focus-Friendly Features

The following features are potential directions for making Familiar more useful for people experiencing genuine difficulties with focus and executive functioning.

## 🪜 Task Decomposition

Allow users to give Familiar a large or vague objective:

"Build my portfolio."

Familiar could help turn it into progressively smaller actions:

Build Portfolio

│

├── Choose projects

│   ├── Find project #1

│   ├── Find project #2

│   └── Find project #3

│

├── Create portfolio structure

│   ├── Create homepage

│   ├── Add projects section

│   └── Add contact section

│

└── Publish


Breaking a task down should reduce cognitive load and not create another overwhelming list.

# The "Next Step" System

Instead of constantly displaying an entire task list, Familiar could maintain a single recommended next action.

╭──────────────────────────╮

│    Your Familiar         │

│                          │

│ Current Quest: Portfolio │

│                          │

│ Your next step:          │

│                          │

│ Open your project folder.│

│                          │

│ [ Done ]   [ Not Yet ]   │

╰──────────────────────────╯


This keeps the user's attention on progress rather than the entire workload.

# Gentle Focus Sessions

Focus sessions should be customizable rather than forcing everyone into a rigid productivity technique.

Possible options:

5 minutes
10 minutes
15 minutes
25 minutes
45 minutes
Custom


A user should also be able to say:

"I can't focus today."


and receive a smaller goal rather than being treated as having failed.

Familiar should recognize breaks as part of the workflow.


# 🔄 Easy Recovery

Getting distracted shouldn't reset someone's progress.

If a user leaves a task for several hours, or several days, Familiar should make returning easy.

For example:

Welcome back!

You were working on:
"Add authentication."

Last completed:
✓ Create login form

Next suggested step:
→ Connect the login form to the server.


# Context Restoration

One difficult part of returning to a project is remembering what you were doing.

Familiar could maintain a lightweight project state:

Current Project: Book Club

Last worked on:
Authentication

Completed:
✓ Login page
✓ Registration form

Currently working on:
Session handling

Next:
Test login persistence

Notes:
"Need to investigate cookie configuration."


This reduces the amount of mental effort required to reconstruct the user's previous context.

# Brain Dump Mode

Sometimes organizing tasks is itself the problem.

Familiar could allow users to dump thoughts without requiring immediate organization:

"I need to finish my resume,
email my professor,
fix the login page,
buy groceries,
and I still haven't finished that assignment."


Familiar could then help organize the information into:

📚 School
📄 Resume
💻 Coding
🏠 Personal


The user shouldn't have to organize everything before getting help organizing it.

🐾 Familiar Personalities

Different users may respond better to different interaction styles.

Possible personalities could include:

🦊 Encouraging
🐱 Calm
🐉 Motivational
🦉 Analytical
🐕 Friendly
🐸 Playful
🐢 Patient

Users should be able to choose how their familiar communicates.

For example:

Encouraging
"You've already completed two steps. Let's tackle one more."
Calm
"No rush. Let's work on the smallest next step."
Playful
"A wild task appeared! Let's defeat it."

## Mental Health Considerations

Familiar is intended to support productivity—not diagnose, treat, or replace professional mental health care.

The project should avoid language that implies:

- Users are lazy.
- Users lack discipline.
- Productivity determines personal worth.
- Missing goals is a moral failure.
- Everyone should be able to work the same way.
- More productivity is always better.

Instead, Familiar should treat productivity as something that can be affected by energy, environment, stress, attention, workload, and individual circumstances.

The application should encourage users to seek appropriate professional support when they need it rather than attempting to function as a therapist or medical treatment.

## Anti-Shame Design

Familiar should intentionally avoid productivity mechanics that can make struggling users feel worse.

Features should be carefully evaluated before implementing:

Punishing missed goals
Aggressive streak systems
Shame-based notifications
"You failed" messages
Productivity leaderboards
Comparing users to other people
Excessive notifications
Artificial urgency
Constant productivity scoring

Gamification can be useful, but the user should feel like they are playing with their familiar.

## Progress Without Pressure

Instead of measuring only completed tasks, Familiar could track positive indicators such as:

- Started a task
- Returned to a project
- Completed one step
- Asked for help
- Took a needed break
- Made progress after being stuck


## Technology

Familiar is currently developed primarily with:

C++
Modular project structure
Automated development workflows
Testing infrastructure
Project documentation
📁 Project Structure
familiar/
├── Assets/
├── docs/
├── sample/
├── tests/
├── Makefile
└── ...

Assets/

Contains project resources used by Familiar.

docs/

Contains project documentation and supporting information.

sample/

Contains sample/example resources.

tests/

Contains tests used to verify application behavior.

Makefile

Provides development commands for common project tasks.

# 🚀 Getting Started

Clone the repository:

git clone https://github.com/jocoso/familiar.git
cd familiar


Follow the project's installation and setup instructions.

Development commands can be accessed through the included Makefile.

# 🗺️ Roadmap

Potential future development includes:

Intelligent task decomposition
"Next Step" focus mode
Brain dump → organized tasks
Focus sessions
Flexible break system
Context restoration
Project progress tracking
Familiar personalities
Custom familiar creation
Gentle reminders
Adaptive task difficulty
Gamified progression
Project notes and memory
Accessibility improvements
Optional AI-assisted planning

# 🤝 Contributing

Familiar is a project about building technology that treats people with patience.

Contributions are welcome, particularly ideas and implementations that improve:

Accessibility
Executive-function support
User experience
Task organization
Focus assistance
Non-judgmental productivity
Mental-health-conscious design
