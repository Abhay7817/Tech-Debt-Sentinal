# Tech Debt Sentinel

**Tech Debt Sentinel** is a static analysis tool designed to automatically identify and quantify technical debt indicators within C++ codebases. By scanning source files for common debt markers such as `TODO`, `FIXME`, `BUG`, and similar annotations, the tool helps development teams gain visibility into hidden maintenance costs and code quality risks.

The project combines a high-performance C++ analysis engine powered by Google's RE2 regular expression library with a lightweight web dashboard built using Vanilla JavaScript for visualizing technical debt metrics.

---

## Overview

Technical debt often accumulates through unfinished tasks, known issues, temporary workarounds, and deferred improvements that are left in source code comments. While these markers are easy to add, they are often difficult to track across large codebases.

Tech Debt Sentinel automates this process by:

* Scanning C++ source files for predefined technical debt markers.
* Detecting debt annotations using fast and reliable regular expression matching.
* Assigning weighted severity scores based on the impact of identified debt.
* Generating structured JSON output for reporting and visualization.
* Presenting debt statistics through an interactive dashboard.

---

## Key Features

### Automated Debt Detection

Identifies commonly used technical debt markers, including:

* `TODO`
* `FIXME`
* `BUG`
* `HACK`
* `XXX`
* Custom configurable markers

### Severity-Based Scoring

Each detected marker contributes to an overall technical debt score based on severity:

| Severity | Score |
| -------- | ----- |
| Low      | +2    |
| Medium   | +3    |
| High     | +5    |

This scoring model enables teams to prioritize remediation efforts and track debt accumulation over time.

### High-Performance Regex Matching

Built on **Google RE2**, providing:

* Fast execution on large codebases
* Safe regular expression evaluation
* Predictable performance without catastrophic backtracking

### JSON-Based Data Exchange

The analysis engine exports results as JSON, enabling seamless communication between the backend and frontend layers.

### Interactive Dashboard

A lightweight dashboard built with Vanilla JavaScript provides:

* Debt score summaries
* Severity distribution charts
* Technical debt statistics
* Visual insights into code quality trends

---

## Architecture

```text
+------------------+
|   C++ Source     |
|      Files       |
+--------+---------+
         |
         v
+------------------+
|  Analysis Engine |
|      (C++)       |
|  RE2 + jsoncpp   |
+--------+---------+
         |
         v
+------------------+
|   JSON Report    |
+--------+---------+
         |
         v
+------------------+
|   Web Dashboard  |
|   Vanilla JS     |
|    Chart.js      |
+------------------+
```

---

## Technology Stack

### Backend

* **C++**
* **Google RE2** – Regular expression matching
* **jsoncpp** – JSON generation and parsing

### Frontend

* **Vanilla JavaScript**
* **Chart.js** – Data visualization


