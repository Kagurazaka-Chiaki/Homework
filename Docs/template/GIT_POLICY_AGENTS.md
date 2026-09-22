# Git Commits

- After completing the requested work and passing relevant checks, create coherent local commits without asking again.
- Before staging, inspect `git status` and the task diff; preserve all pre-existing and unrelated changes.
- Stage only changes made for the current task, then review `git diff --staged` before committing.
- Split independent changes into separate commits; each commit must represent one logical intent.
- Use `<type>(<scope>): <summary>`; the scope is mandatory.
- Allowed types: `feat`, `fix`, `docs`, `style`, `refactor`, `perf`, `test`, `build`, `ci`, `chore`, `revert`.
- Choose the scope in this order: an established repository scope; the narrowest stable module or subsystem; a shared intent such as `policy`, `cmake`, `deps`, or `tooling`; otherwise `repo`.
- Keep scopes short, lowercase kebab-case, and based on repository vocabulary rather than temporary filenames.
- Write a concise English summary that states the actual result; avoid vague text such as `update files`, `codex changes`, or `misc`.
- Do not mention AI, Codex, assistants, models, or tools in the commit message or trailers.
- Never commit unrelated files, secrets, generated artifacts, or machine-local configuration.
- Do not amend, rewrite history, force-push, or push unless the user explicitly requests it.
