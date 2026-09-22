# ADR-0001 / 决策记录 0001

## Repository Naming Taxonomy / 仓库命名分类法

## Status / 状态

Accepted / 已采纳

## Date / 日期

2026-03-22

## Last Updated / 最后更新

2026-08-27

## Summary / 摘要

This ADR defines the repository naming taxonomy used across a personal technical project and knowledge ecosystem. The taxonomy adopts the form `<greek-prefix>-<domain-code><index>` to improve consistency, extensibility, recognizability, and long-term portfolio structure.

本 ADR 规定个人技术项目与知识作品体系中使用的仓库命名分类法。该分类法采用 `<greek-prefix>-<domain-code><index>` 的形式，以提升一致性、可扩展性、可识别性以及长期作品集结构的稳定性。

The taxonomy is a governance rule for repository names. It is not a claim that every Greek-letter association is universally canonical in mathematics, physics, or computer science. Where associations are strong, the document states that directly. Where associations are weaker, the document describes them as conventional or accepted rather than as textbook-level facts.

该分类法是针对仓库名称的治理规则，并不宣称所有希腊字母与学科之间的对应关系在数学、物理或计算机科学中都具有普遍 canonical 地位。对于关联较强的映射，本文会直接说明；对于关联较弱的映射，本文仅将其表述为约定性或可接受做法，而不会包装为教科书级事实。

## Context / 背景

The repository owner maintains multiple repositories as part of a personal ecosystem rather than as isolated one-off projects. The ecosystem includes both executable technical projects and knowledge publications such as notes, tutorials, books, references, and Obsidian-compatible knowledge bases. Over time, the absence of a stable naming taxonomy would make the ecosystem harder to navigate, explain, and extend in public.

仓库维护者管理的是一个由多个仓库组成的个人体系，而不是若干彼此孤立的一次性项目。该体系既包含可执行的技术项目，也包含笔记、教程、书籍、参考资料和兼容 Obsidian 的知识库等知识作品。随着时间推移，如果缺少稳定的命名分类法，这个体系在公开展示、说明和持续扩展时都会变得更难理解和维护。

The naming system is intended to support:

- consistency across repositories
- extensibility as new domains or repository families are added
- recognizability in public hosting platforms
- a clear identity for each technical or knowledge-oriented repository family
- long-term portfolio structure without repeated renaming

该命名系统旨在支持以下目标：

- 跨仓库的一致性
- 新领域或新仓库家族加入时的可扩展性
- 在公开托管平台上的可识别性
- 各技术型或知识型仓库家族的清晰身份表达
- 避免反复改名的长期作品集结构

The owner also prefers durability over symbolic perfection. A naming scheme that is stable, reviewable, and understandable is more valuable than one that attempts to maximize symbolic elegance at the cost of churn.

维护者同时强调稳定性优先于符号纯度。一个稳定、可审查、可理解的命名体系，比一个为了追求符号上的“完美”而不断变动的体系更有价值。

## Decision / 决策

The accepted repository naming grammar is:

本 ADR 采纳的仓库命名语法为：

```text
<greek-prefix>-<domain-code><index>
```

Examples:

示例：

- `delta-grfx01`
- `lambda-ccmp01`
- `epsilon-math01`
- `eta-mmgr01`
- `theta-nnet01`
- `kappa-geng01`

The taxonomy is defined as follows:

该分类法的定义如下：

1. `greek-prefix` identifies a repository family at the taxonomy level. A family normally represents a technical domain, but an explicitly adopted artifact family may group repositories by durable content purpose.
2. `domain-code` identifies a more precise technical area or subject within that family.
3. `index` identifies a concrete repository within the same naming lane.

其含义如下：

1. `greek-prefix` 用于在分类层面标识一个仓库家族。仓库家族通常表示技术领域，但经过明确采纳的内容形态家族也可以按长期稳定的内容用途聚合仓库。
2. `domain-code` 用于标识该家族下更具体的技术方向或主题。
3. `index` 用于标识同一命名轨道中的具体仓库。

This ADR explicitly adopts `kappa` as the knowledge-publication family. It groups repositories whose primary deliverable is maintained knowledge rather than a standalone executable product. The mapping is a deliberate portfolio convention, motivated by the mnemonic `K = Knowledge`; it is not claimed to be a universal Greek-letter association.

本 ADR 明确采纳 `kappa` 作为知识作品家族。它用于聚合主要交付物是持续维护的知识内容、而非独立可执行产品的仓库。该映射是由 `K = Knowledge` 助记关系支持的个人作品集约定，并不宣称这是希腊字母的普遍学术对应。

This ADR accepts a mixed-strength mapping model:

本 ADR 采纳“强弱分层”的映射模型：

- Some Greek-prefix mappings are treated as strong or canonical enough for stable use.
- Some mappings are treated as conventional but still acceptable for long-term naming.
- Some prefixes are reserved or weakly associated and should not be promoted as core mappings without further review.

- 部分希腊前缀映射被视为较强、足以稳定使用的关联。
- 部分映射被视为约定性但仍适合长期命名的关联。
- 部分前缀仅保留或仅有较弱关联，未经进一步审查前不应被提升为核心映射。

Public repositories should generally not be renamed merely to improve symbolic purity once a name is already stable and usable.

对于已经稳定并可用的公开仓库，不应仅仅为了提升“符号纯度”而进行重命名。

## Naming Interpretation Rules / 命名解释规则

1. The taxonomy is for naming repositories, not for defining universal disciplinary symbolism.
2. Prefix meaning is interpreted at the governance level of this project ecosystem, not as a claim of universal academic authority.
3. Strong mappings may be described as established or well-motivated.
4. Conventional mappings should be described honestly as accepted conventions rather than as canonical truth.
5. Weak associations should remain reserved, provisional, or explicitly limited in scope.
6. Domain codes should remain short, stable, and readable.
7. Index values should be numeric and zero-padded when a family may contain multiple repositories.
8. Classification should follow the repository's primary deliverable. A runnable implementation remains in its technical family even when it contains extensive documentation; a maintained tutorial, book, or knowledge base belongs to `kappa` even when it includes supporting code and labs.
9. Within `kappa`, the domain code identifies the subject of the knowledge work, not the Markdown format or note-taking application.

1. 该分类法用于命名仓库，而不是定义普适性的学科符号体系。
2. 前缀含义是在本项目体系的治理层面进行解释，而不是宣称具有普遍学术权威。
3. 强关联映射可以表述为较为 established 或具备充分动机。
4. 约定性映射应如实表述为 accepted convention，而不是 canonical truth。
5. 弱关联应维持保留、暂定或明确受限的状态。
6. 领域代码应保持简短、稳定且可读。
7. 当同一家族可能包含多个仓库时，索引应使用数字并优先采用零填充格式。
8. 分类应以仓库的主要交付物为准。可运行实现即使包含大量文档，仍归入相应技术家族；持续维护的教程、书籍或知识库即使包含配套代码和实验，也归入 `kappa`。
9. 在 `kappa` 家族中，领域代码表示知识作品的主题，而不是 Markdown 格式或具体笔记软件。

## Rationale / 理由

The taxonomy balances semantics with operational stability.

该分类法在语义表达与操作稳定性之间做平衡。

The Greek prefix provides a memorable family marker. The domain code provides subject precision. The index allows the system to scale without forcing ad hoc suffixes or disruptive renames.

希腊前缀提供可记忆的家族标识，领域代码提供主题精度，而索引则使系统能够扩展，而不必依赖临时后缀或通过重命名来腾挪空间。

The `kappa` family adds an intentional second axis to the portfolio: it identifies repositories whose durable purpose is knowledge publication. This lets all books and notes group together on GitHub while preserving their subjects through codes such as `geng`, `algo`, `math`, and `grfx`.

`kappa` 家族为作品集增加了一个有意设计的第二分类轴：它标识长期用途为知识出版与维护的仓库。这样，所有书籍和笔记可以在 GitHub 上聚合展示，同时仍可通过 `geng`、`algo`、`math` 和 `grfx` 等代码保留具体主题。

This layered structure is preferable to either of the following extremes:

这种分层结构优于以下两种极端做法：

- a purely symbolic system that is elegant but ambiguous
- a purely literal system that is precise but visually flat and harder to group across repositories

- 纯符号化但语义模糊的体系
- 纯字面化但视觉上缺乏家族感、难以跨仓库分组的体系

The taxonomy also creates room for honest governance. It allows strong mappings to remain stable while giving weaker mappings a controlled, explicitly non-universal status.

该分类法也为“诚实治理”留下空间。它允许强关联映射稳定保留，同时让较弱映射在明确非普适的前提下被受控使用。

## Classification Policy / 分类策略

The current policy divides prefix mappings into three categories:

当前策略将前缀映射划分为三类：

### Stronger Mappings / 较强映射

These mappings are considered sufficiently motivated for durable public use:

这些映射被认为具有足够动机，可用于长期、公开的稳定命名：

- `delta` -> graphics / rendering
- `lambda` -> compiler / language
- `epsilon` -> mathematics / numerics
- `eta` -> systems / efficiency
- `theta` -> AI / machine learning
- `sigma` -> statistics / data
- `phi` -> physics / simulation

### Conventional but Acceptable Mappings / 约定性但可接受映射

These mappings are acceptable within this ecosystem, but they should not be overstated as universal canon:

这些映射在本体系中可接受，但不应被过度包装为普遍 canonical 对应：

- `zeta` -> algorithms / complexity
- `iota` -> tools / utilities
- `kappa` -> knowledge publications / notes / books
- `pi` -> geometry / computation
- `omega` -> concurrency / async

### Reserved or Weakly Associated Prefixes / 保留或弱关联前缀

These prefixes may be reserved for future use or only adopted with explicit review:

这些前缀可为未来保留，或仅在明确审查后使用：

- `gamma` -> reserved for future technical fit
- `mu` -> reserved for future technical fit
- `rho` -> reserved for future technical fit

## Consequences / 后果

This decision produces several practical consequences:

该决策带来以下实际后果：

- Repository names become easier to interpret across the portfolio.
- New repositories can be assigned names with less ad hoc discussion.
- Knowledge repositories become visibly grouped on public hosting platforms while retaining subject-level distinctions.
- Existing accepted names can remain stable even if some symbolic associations are imperfect.
- Future review can focus on governance quality rather than symbolic over-optimization.

- 作品集中的仓库名称会更易于整体解释。
- 新仓库在命名时可以减少临时性的讨论成本。
- 知识型仓库可以在公开托管平台上清晰聚合，同时保留主题层面的区分。
- 即使某些符号关联并不完美，现有已接受名称仍可保持稳定。
- 未来审查可以更多聚焦于治理质量，而不是符号层面的过度优化。

The decision also imposes discipline:

该决策也带来约束：

- weak mappings must be labeled honestly
- the `kappa` family must be used only when maintained knowledge is the repository's primary deliverable
- naming churn should be avoided
- public naming stability is prioritized over retrospective symbolic refinement

- 弱映射必须被诚实标注
- 只有当持续维护的知识内容是仓库的主要交付物时，才使用 `kappa` 家族
- 应避免命名震荡
- 对公开仓库而言，命名稳定性优先于事后追求符号更“纯”

## Non-Goals / 非目标

This ADR does not attempt to:

本 ADR 不试图实现以下目标：

- prove a universal symbolic correspondence for every Greek letter
- standardize all repository internals, build systems, or code structures
- force immediate renaming of existing repositories
- define a complete ontology for every future technical domain
- classify every repository containing documentation as a `kappa` repository
- require Obsidian-specific syntax, plugins, or workspace configuration in `kappa` repositories
- treat weak associations as textbook-level facts

- 证明每一个希腊字母都具有普适性的学科对应
- 统一所有仓库的内部结构、构建系统或代码组织
- 强制现有仓库立即改名
- 为所有未来技术领域建立一套完备本体
- 将所有包含文档的仓库一律归入 `kappa`
- 强制 `kappa` 仓库使用 Obsidian 专有语法、插件或工作区配置
- 将弱关联包装成教科书级事实

## Current Accepted Grammar / 当前采纳的命名语法

The currently accepted grammar is:

当前采纳的命名语法如下：

```text
repository-name := <greek-prefix> "-" <domain-code> <index>
greek-prefix    := lower-case Greek name written in ASCII letters
domain-code     := 4 to 5 lower-case ASCII letters identifying a technical area or subject
index           := 2 or more digits, zero-padded when practical
```

Interpretation guidance:

解释约定：

- use lower-case ASCII for portability and consistency
- avoid punctuation beyond the single hyphen separator
- keep domain codes stable once publicly used
- use `kappa-<subject-code><index>` for knowledge publications; do not use generic codes such as `note` or `book` when a stable subject code is available
- prefer creating a new indexed repository over renaming a public repository for minor semantic refinement

- 使用小写 ASCII，以提高可移植性和一致性
- 除单个连字符分隔符外，避免使用其他标点
- 领域代码一旦公开使用，应尽量保持稳定
- 知识作品使用 `kappa-<subject-code><index>`；存在稳定主题代码时，不使用 `note` 或 `book` 这类泛化代码
- 若只是为了轻微语义优化，优先新增同系列索引仓库，而不是重命名公开仓库

## Follow-Up Actions / 后续行动

- Record future accepted names in a lightweight registry or appendix update process.
- Record newly accepted `kappa` subject codes in Appendix C before broad reuse.
- Review reserved prefixes only when a real repository requires them.
- Add short reviewer guidance to the root README in a future change if the portfolio becomes more public-facing.
- Revisit domain-code coverage only when new areas cannot be represented clearly by the existing codes.

- 将未来新接受的名称记录到轻量注册表或附录更新流程中。
- 新增的 `kappa` 主题代码应先记录在附录 C，再进行广泛复用。
- 仅在确有真实仓库需求时审查保留前缀。
- 如果作品集未来面向公众展示的程度更高，可在后续变更中把简短审核说明加入根 README。
- 只有在新领域无法被现有代码清晰表达时，才重新审查领域代码覆盖范围。

## Appendix A / 附录 A: Core Mapping Table / 核心映射表

| Greek Prefix | 中文前缀 | Repository Family | 中文仓库家族 | Example Repository | Classification | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| delta | 德尔塔 | graphics / rendering | 图形学 / 渲染 | `delta-grfx01` | stronger | Strong practical association with change, rendering pipelines, and graphics-oriented branding; used here as a stable family marker rather than a universal theorem. |
| lambda | 拉姆达 | compiler / language | 编译器 / 语言 | `lambda-ccmp01` | stronger | Strong association with formal systems, lambda calculus, and language-oriented work. |
| epsilon | 艾普西龙 | mathematics / numerics | 数学 / 数值计算 | `epsilon-math01` | stronger | Well-suited for mathematical and numerical work; broad but stable. |
| zeta | 泽塔 | algorithms / complexity | 算法 / 复杂度 | `zeta-algo01` | conventional | Acceptable as a portfolio convention, but not presented as a universally canonical algorithms symbol. |
| eta | 艾塔 | systems / efficiency | 系统 / 效率 | `eta-mmgr01` | stronger | Used for systems-oriented, performance-aware, or efficiency-related repository families. |
| theta | 西塔 | AI / machine learning | 人工智能 / 机器学习 | `theta-nnet01` | stronger | Strong practical fit due to common parameter notation and optimization contexts. |
| iota | 约塔 | tools / utilities | 工具 / 实用程序 | `iota-bldt01` | conventional | Chosen as a compact conventional label for smaller tools and utilities, without claiming canonical status. |
| kappa | 卡帕 | knowledge publications / notes / books | 知识作品 / 笔记 / 书籍 | `kappa-geng01` | conventional | Adopted as an explicit portfolio convention using the mnemonic `K = Knowledge`. It groups maintained knowledge artifacts and is not presented as a universal Greek-letter association. |
| sigma | 西格玛 | statistics / data | 统计 / 数据 | `sigma-stat01` | stronger | Strong statistical association, especially with summation and aggregate reasoning. |
| pi | 派 | geometry / computation | 几何 / 计算几何 | `pi-geom01` | conventional | Widely recognizable and acceptable for geometry-related work, but broader than a strict canonical mapping. |
| phi | 斐 | physics / simulation | 物理 / 仿真 | `phi-phys01` | stronger | Commonly used in physics and field notation; appropriate for simulation-oriented repositories. |
| omega | 欧米伽 | concurrency / async | 并发 / 异步系统 | `omega-async01` | conventional | Accepted here as an end-state or systems-scale convention, not as a universal concurrency symbol. |

## Appendix B / 附录 B: Extended or Reserved Prefixes / 扩展或保留前缀

| Greek Prefix | 中文前缀 | Suggested Domain | 中文建议领域 | Status | Notes |
| --- | --- | --- | --- | --- | --- |
| gamma | 伽马 | reserved for future technical fit | 为未来技术方向保留 | reserved | May be assigned later if a clear, durable portfolio use emerges. |
| mu | 缪 | reserved for future technical fit | 为未来技术方向保留 | reserved | Keep unassigned until a real repository family requires it. |
| rho | 柔 | reserved for future technical fit | 为未来技术方向保留 | reserved | Avoid speculative assignment without practical naming pressure. |

## Appendix C / 附录 C: Domain Code Conventions / 领域代码约定

Domain codes provide the precise technical or subject discriminator inside a repository family. In technical families, the code identifies the narrower implementation area. In `kappa`, the code identifies the subject of the knowledge publication. Codes should be short, memorable, and semantically stable.

领域代码用于在同一家族内部提供更精确的技术或主题区分。在技术家族中，代码表示更窄的实现方向；在 `kappa` 中，代码表示知识作品的主题。代码应当简短、易记，并在语义上保持稳定。

Recommended conventions:

推荐约定：

- use 4 to 5 lower-case ASCII letters
- prefer recognizable abbreviations over opaque compression
- keep one dominant meaning per code
- avoid reusing one code for unrelated technical areas
- reuse an established subject code across technical and `kappa` families when it preserves the same meaning
- avoid generic `note`, `book`, or `docs` codes inside `kappa`; the prefix already expresses the artifact family

- 使用 4 到 5 个小写 ASCII 字母
- 优先选择可识别缩写，而非过度压缩
- 每个代码尽量对应一个主导含义
- 避免将同一代码复用于彼此无关的技术方向
- 当含义一致时，可在技术家族与 `kappa` 家族之间复用已经建立的主题代码
- 避免在 `kappa` 内使用泛化的 `note`、`book` 或 `docs` 代码；前缀已经表达了内容家族

| Domain Code | Meaning | 中文含义 | Example |
| --- | --- | --- | --- |
| `grfx` | graphics / rendering | 图形学 / 渲染 | `delta-grfx01` |
| `ccmp` | compiler / compilation | 编译器 / 编译 | `lambda-ccmp01` |
| `math` | mathematics / numerics | 数学 / 数值计算 | `epsilon-math01` |
| `algo` | algorithms | 算法 | `zeta-algo01` |
| `mmgr` | memory management | 内存管理 | `eta-mmgr01` |
| `nnet` | neural networks | 神经网络 | `theta-nnet01` |
| `bldt` | build / tooling | 构建 / 工具链 | `iota-bldt01` |
| `stat` | statistics / data | 统计 / 数据 | `sigma-stat01` |
| `geom` | geometry / computational geometry | 几何 / 计算几何 | `pi-geom01` |
| `phys` | physics / simulation | 物理 / 仿真 | `phi-phys01` |
| `async` | concurrency / async systems | 并发 / 异步系统 | `omega-async01` |
| `geng` | game engine engineering | 游戏引擎工程 | `kappa-geng01` |
| `cppx` | modern C++ | 现代 C++ | `kappa-cppx01` |
| `vulk` | Vulkan | Vulkan | `kappa-vulk01` |
| `blnd` | Blender | Blender | `kappa-blnd01` |

## Appendix D / 附录 D: Current Accepted Examples / 当前已接受示例

| Repository | Interpretation | 中文解释 | Prefix Strength | Notes |
| --- | --- | --- | --- | --- |
| `delta-grfx01` | graphics / rendering repository in the delta family | 属于 delta 家族的图形学 / 渲染仓库 | stronger | Accepted as a stable public-facing graphics family name. |
| `lambda-ccmp01` | compiler or language implementation repository in the lambda family | 属于 lambda 家族的编译器或语言实现仓库 | stronger | Appropriate for parsing, compiling, or language-system work. |
| `epsilon-math01` | mathematics or numerics repository in the epsilon family | 属于 epsilon 家族的数学或数值计算仓库 | stronger | Suitable for numerical methods, applied math, or analytical experiments. |
| `eta-mmgr01` | systems-oriented memory-management repository in the eta family | 属于 eta 家族的系统向内存管理仓库 | stronger | Indicates systems and efficiency concerns more than pure theory. |
| `theta-nnet01` | neural-network repository in the theta family | 属于 theta 家族的神经网络仓库 | stronger | Suitable for ML experimentation and parameterized model work. |
| `kappa-geng01` | maintained game-engine engineering book, tutorial, or knowledge base in the kappa family | 属于 kappa 家族、持续维护的游戏引擎工程书籍、教程或知识库 | conventional | Accepted because its primary deliverable is structured knowledge. Supporting code and labs do not change the family classification. |

### Knowledge-Family Boundary Examples / 知识家族边界示例

| Repository Purpose | Family Choice | Example | Reason |
| --- | --- | --- | --- |
| A Vulkan renderer whose primary deliverable is runnable engine code | technical family | `delta-grfx01` | Documentation supports the implementation; it is not the primary artifact. |
| A maintained Vulkan tutorial or reference notebook with supporting samples | knowledge family | `kappa-vulk01` | The durable deliverable is the structured learning material. |
| A game-engine engineering book with labs, questions, and cheat sheets | knowledge family | `kappa-geng01` | Code and exercises support a book-like knowledge product. |
| A standalone build utility with a detailed manual | technical family | `iota-bldt01` | The utility remains the primary deliverable. |

| 仓库用途 | 家族选择 | 示例 | 原因 |
| --- | --- | --- | --- |
| 以可运行引擎代码为主要交付物的 Vulkan 渲染器 | 技术家族 | `delta-grfx01` | 文档服务于实现，并非主要作品。 |
| 带配套示例、持续维护的 Vulkan 教程或参考笔记 | 知识家族 | `kappa-vulk01` | 结构化学习内容是长期主要交付物。 |
| 包含实验、题目和速查表的游戏引擎工程书籍 | 知识家族 | `kappa-geng01` | 代码与练习服务于书籍型知识产品。 |
| 带详细手册的独立构建工具 | 技术家族 | `iota-bldt01` | 工具本身仍是主要交付物。 |

## Appendix E / 附录 E: Practical Review Criteria for New Names / 新命名的实务审核标准

Use the following checklist before accepting a new repository name:

在接受新的仓库命名前，可使用以下检查清单：

- Does the name follow the grammar `<greek-prefix>-<domain-code><index>`?  
  该名称是否符合 `<greek-prefix>-<domain-code><index>` 语法？
- Is the prefix classification honest: stronger, conventional, or reserved?  
  前缀分类是否诚实明确：较强、约定性，还是保留？
- Does the chosen domain code describe the repository more precisely than the prefix alone?  
  所选领域代码是否比前缀本身更精确地描述了仓库？
- Is the family selected according to the primary deliverable rather than the mere presence of documentation or code?  
  是否按照主要交付物选择家族，而不是仅根据仓库中是否出现文档或代码？
- For `kappa`, does the code identify the subject instead of repeating `book`, `note`, or `docs`?  
  对于 `kappa`，代码是否表达具体主题，而不是重复 `book`、`note` 或 `docs`？
- Is the name stable enough to survive public use without later symbolic correction?  
  该名称是否足够稳定，能够在公开使用后避免因追求符号修正而再次更改？
- Would renaming an existing public repository produce more churn than value?  
  如果这是针对已有公开仓库，重命名带来的扰动是否会大于收益？
- Is the association being described as strong only when it is genuinely strong?  
  只有在关联确实较强时，才将其描述为强关联了吗？
- If the association is weak, is that weakness stated explicitly?  
  如果关联较弱，是否已经明确写出这一点？

If the answer to several of these questions is negative, the proposed name should be revised before adoption.

如果上述问题中有多项答案为否，则应在采纳前修订该命名方案。
