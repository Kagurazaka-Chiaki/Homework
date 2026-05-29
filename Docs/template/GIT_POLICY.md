# Git Policy

本文档定义仓库通用的 Git 工作流、提交规范，以及 AI/Codex 参与修改时的提交边界。

大部分规则应保持通用，适用于个人仓库之间的复用。仓库特定的例外和命令应放在最后一节。

## 1. 核心原则

1. 一个 commit 应只表达一个完整、连贯的变更。
2. commit 应便于 review，也应便于回滚。
3. 不要把无关修改混在同一个 commit 中。
4. 不要提交 secrets、凭据、token 或仅适用于本机的配置。
5. 不要提交生成的构建产物，除非仓库明确要求。
6. 每次提交前都要检查 diff。
7. 优先使用小而清晰的 commit，避免大而不透明的 commit。
8. 对 AI agents 来说，本 Git Policy 是硬约束，不是建议或一次性提示。

## 2. 提交信息格式

提交信息使用 Conventional Commits 风格：

```text
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

commit message 可以使用英文。对于跨仓库复用的模板、工具链、构建和 API 相关变更，推荐使用简洁英文，便于搜索、复用和与生态工具对齐。

常用 type：

```text
feat      新功能
fix       缺陷修复
docs      文档变更
style     仅格式化变更，不影响代码含义
refactor  重构，不包含功能变化或缺陷修复
perf      性能优化
test      测试相关变更
build     构建系统、依赖、工具链、CMake 等变更
ci        CI 配置或流水线变更
chore     维护性变更
revert    回滚已有 commit
```

scope 用于说明变更影响的模块或范围。scope 应简短、稳定，并尽量使用仓库中已有的模块名、目录名或概念名。

示例：

```text
feat(parser): add diagnostic output
fix(cmake): handle clang-cl debug preset
docs(policy): document git workflow
test(lexer): add escaped newline coverage
build(vcpkg): update dependency manifest
```

如果变更包含破坏性变更，在 type 或 scope 后添加 `!`：

```text
feat(api)!: change parser result format
```

也可以在 footer 中说明破坏性变更：

```text
BREAKING CHANGE: parser result now returns structured diagnostics.
```

提交信息应描述实际变更，而不是描述使用了什么工具。

好：

```text
fix(cmake): correct clang-cl debug preset
```

坏：

```text
chore: codex changes
```

## 3. 提交粒度

一个 commit 通常只应修改一个逻辑区域或完成一个明确目标。

好：

```text
fix(lexer): handle escaped newline tokens
test(lexer): add escaped newline coverage
```

坏：

```text
fix: update lexer, rewrite README, change CMake presets, reformat all files
```

如果一次工作包含多个互不依赖的变更，应拆分为多个 commit。

## 4. 分支策略

对于个人仓库，小而安全的修改可以直接在默认分支上完成。

以下情况应使用 feature branch：

1. 变更较大。
2. 变更带有实验性质。
3. 变更影响项目结构。
4. 变更由 AI 大量生成或辅助完成。
5. 变更可能破坏已有行为。

推荐分支命名：

```text
feat/<short-name>
fix/<short-name>
refactor/<short-name>
docs/<short-name>
experiment/<short-name>
```

示例：

```text
feat/lexer-token-stream
fix/cmake-clangcl-debug
refactor/parser-ast-layout
experiment/custom-vm-backend
```

除非明确授权，不要 force push，也不要重写已经共享的历史。

## 5. 禁止提交的文件

不要提交：

```text
build/
out/
dist/
.cache/
.tmp/
temp/
*.o
*.obj
*.exe
*.dll
*.so
*.dylib
*.class
*.pdb
*.ilk
*.log
.env
.env.*
```

不要提交本机编辑器状态，除非该文件是仓库级通用配置。

通常避免提交：

```text
.vscode/
.idea/
CMakeUserPresets.json
```

## 6. 通常建议提交的文件

通常应提交：

```text
README.md
AGENTS.md
GIT_POLICY.md
TODO.md
ROADMAP.md
CMakeLists.txt
CMakePresets.json
src/
include/
tests/
docs/
scripts/
```

对于 C++ 仓库，通常应提交：

```text
.clang-format
.clang-tidy
.editorconfig
CMakePresets.json
vcpkg.json
conanfile.txt
conanfile.py
```

## 7. AI / Codex 提交策略

AI agents 可以协助编辑、重构、生成或解释代码。

当仓库使用本模板作为 Git Policy 时，AI agents 必须把本文件视为提交行为的强制规则。不得用一条对话消息、临时说明或上下文中的自我提醒替代实际约束；长上下文、恢复会话或切换 agent 后，规则仍然有效。

AI agents 只有在满足以下条件时才可以提交：

1. 请求任务是明确的。
2. 已检查 working tree diff。
3. 修改范围限定在请求任务内。
4. 没有包含无关文件。
5. 没有提交 secrets 或本机路径。
6. 在适用时已经运行构建或测试。
7. commit message 具体描述了实际变更。

AI agents 不得：

```text
force push
rewrite history
delete user-authored files without explanation
perform broad refactors without a plan
hide failing tests
commit generated binaries
commit credentials or tokens
```

### AI 辅助修改的 commit message

AI 辅助修改的 commit message 必须遵守与人工修改相同的提交规范：

1. 必须使用 Conventional Commits 风格。
2. 必须描述实际变更。
3. 不得描述使用了 AI、Codex、assistant、模型或其它工具。
4. 不得使用泛化描述掩盖变更内容。

好：

```text
fix(cmake): correct clang-cl debug preset
```

坏：

```text
chore: codex changes
```

### 禁止 AI 协助信息进入 commit trailer

commit trailer 不得包含任何 AI 协助信息。

禁止使用以下字段或类似字段声明 AI、Codex、assistant、bot、模型名称或工具名称参与了提交：

```text
Co-authored-by
Signed-off-by
Generated-by
Assisted-by
```

`Co-authored-by` 只应用于真实的人类共同作者。

禁止：

```text
Co-authored-by: Codex <codex@example.com>
Assisted-by: AI Assistant
Generated-by: GPT
```

## 8. Git Hook 强制执行

如果仓库接受并启用本 Git Policy，应创建或更新本地 Git hooks，或者使用等效的自动化校验，确保可自动判断的规则在提交时被拦截。

不得只依赖 agent 自己发送一条“我会遵守”的消息，也不得只依赖长上下文中的说明。只要规则可以自动检查，就应由 hook 执行；不满足规则时，hook 必须以非零状态退出并阻止提交。

推荐至少启用：

```text
pre-commit
commit-msg
```

`pre-commit` 应检查：

1. staged 文件是否包含禁止提交的构建产物、临时文件或本机配置。
2. staged 内容是否疑似包含 secrets、token、私钥或本机绝对路径。
3. staged diff 是否包含明显无关的大范围生成文件或二进制文件。

`commit-msg` 应检查：

1. commit message 是否符合 Conventional Commits 基本格式。
2. commit message 是否使用了泛化描述，例如 `codex changes`、`ai changes`、`update files`。
3. commit trailer 是否包含禁止的 AI 协助字段或工具署名。

如果某条规则因仓库特殊情况需要例外，应在“仓库特定规则”中记录，并让 hook 读取该例外，而不是让 agent 临时跳过。

## 9. 提交前检查清单

提交前检查：

```text
git status
git diff
git diff --staged
```

确认：

1. 这是一个连贯的变更吗？
2. 是否包含无关文件？
3. 是否误包含生成文件？
4. 是否包含 secrets 或本机路径？
5. commit message 是否解释了实际变更？
6. 是否运行了相关构建或测试？

## 10. 仓库特定规则

本节可以在不同仓库之间变化。保持简短，只记录当前仓库真正需要的特殊规则。

### 构建产物

不要提交：

```text
build/
out/
```

### 生成文件

生成文件默认不提交，除非在本节明确说明。

### Lockfiles

记录依赖 lockfile 是否应该提交。

```text
# 按仓库填写
```

### 测试命令

```text
# 按仓库填写
```

### 构建命令

```text
# 按仓库填写
```

### 格式化命令

```text
# 按仓库填写
```

### Release 和 tag 策略

```text
# 按仓库填写
```

### 例外

在这里记录任何有意保留的例外。
