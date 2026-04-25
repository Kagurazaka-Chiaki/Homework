# Repository Guide

## Overview
This repository is an old monorepo-style personal C++ learning and experimentation workspace. VS Code and Codex should treat the repository root as the full working tree for code, build files, and related experiments.

## Important source directories
- `Structure/` for data structures and related practice
- `LeetCode/`, `NowCoder/`, `Luogu/` for algorithm exercises and problem-solving
- `Common/`, `Templates/`, `Concurrency/` for C++ mechanisms, utilities, and concurrency experiments
- `Math/`, `Model/`, `Unity/`, `Vision/` for domain-specific experiments and learning projects

## Knowledge directory
`Knowledge/` is an independently managed note layer. It is not part of this change and should not be treated as a reason to reorganize the code-heavy repository root.

## Independently managed areas
- `LaTeXTemplate/` is independently managed.
- Any directory tracked as a Git submodule is out of scope unless explicitly requested.
- Current examples include `Knowledge/`, `LaTeXTemplate/`, `Notes/GameDevNote/`, and `Notes/EngineFeatureNote/`.

## Do not
- Do not mass-rename old directories.
- Do not refactor the whole build unless explicitly asked.
- Do not move existing algorithm, C++, or graphics code into new locations unless explicitly asked.
- Do not modify independently managed submodule content unless explicitly asked.

## Preferred reuse for future code examples
- Data structures should preferably reuse `Structure/`.
- Algorithms should preferably reuse `LeetCode/`, `NowCoder/`, and `Luogu/`.
- C++ mechanisms should preferably reuse `Common/`, `Templates/`, and `Concurrency/`.

## ADR note
If ADR backups are used for this repository, they belong in `Knowledge/ADR/`. This run does not modify that area.
