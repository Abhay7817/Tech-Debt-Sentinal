A static analysis tool to automate detection of Tech Debt Markers in C++ source files using
Google RE2 regex engine for matching of keywords like TODO, BUG, FIX etc. and assigning weighted
score like +2 for low, +3 for medium, +5 for high. The core logic is build using C++ and the simple
dashboard in Vanilla JS. The frontend connects to backend using a JSON file.

Libraries used: Chart.js, jsoncpp, Google RE2.
