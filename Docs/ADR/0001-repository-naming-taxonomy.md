# ADR-0001 / 决策记录 0001

## Repository Naming Taxonomy / 仓库命名分类法

## Status / 状态

Accepted / 已采纳

## Date / 日期

2026-03-22

## Summary / 摘要

This ADR defines the repository naming taxonomy used across a personal technical project ecosystem. The taxonomy adopts the form `<greek-prefix>-<domain-code><index>` to improve consistency, extensibility, recognizability, and long-term portfolio structure.

本 ADR 规定个人技术项目体系中使用的仓库命名分类法。该分类法采用 `<greek-prefix>-<domain-code><index>` 的形式，以提升一致性、可扩展性、可识别性以及长期作品集结构的稳定性。

The taxonomy is a governance rule for repository names. It is not a claim that every Greek-letter association is universally canonical in mathematics, physics, or computer science. Where associations are strong, the document states that directly. Where associations are weaker, the document describes them as conventional or accepted rather than as textbook-level facts.

该分类法是针对仓库名称的治理规则，并不宣称所有希腊字母与学科之间的对应关系在数学、物理或计算机科学中都具有普遍 canonical 地位。对于关联较强的映射，本文会直接说明；对于关联较弱的映射，本文仅将其表述为约定性或可接受做法，而不会包装为教科书级事实。

## Context / 背景

The repository owner maintains multiple repositories as part of a personal technical ecosystem rather than as isolated one-off projects. Over time, the absence of a stable naming taxonomy would make the ecosystem harder to navigate, explain, and extend in public.

仓库维护者管理的是一个由多个仓库组成的个人技术项目体系，而不是若干彼此孤立的一次性项目。随着时间推移，如果缺少稳定的命名分类法，这个体系在公开展示、说明和持续扩展时都会变得更难理解和维护。

The naming system is intended to support:

- consistency across repositories
- extensibility as new domains are added
- recognizability in public hosting platforms
- technical identity for each repository family
- long-term portfolio structure without repeated renaming

该命名系统旨在支持以下目标：

- 跨仓库的一致性
- 新领域加入时的可扩展性
- 在公开托管平台上的可识别性
- 各仓库家族的技术身份表达
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

The taxonomy is defined as follows:

该分类法的定义如下：

1. `greek-prefix` identifies a domain family at the taxonomy level.
2. `domain-code` identifies a more precise technical area within that family.
3. `index` identifies a concrete repository within the same naming lane.

其含义如下：

1. `greek-prefix` 用于在分类层面标识一个领域家族。
2. `domain-code` 用于标识该家族下更具体的技术方向。
3. `index` 用于标识同一命名轨道中的具体仓库。

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

1. 该分类法用于命名仓库，而不是定义普适性的学科符号体系。
2. 前缀含义是在本项目体系的治理层面进行解释，而不是宣称具有普遍学术权威。
3. 强关联映射可以表述为较为 established 或具备充分动机。
4. 约定性映射应如实表述为 accepted convention，而不是 canonical truth。
5. 弱关联应维持保留、暂定或明确受限的状态。
6. 领域代码应保持简短、稳定且可读。
7. 当同一家族可能包含多个仓库时，索引应使用数字并优先采用零填充格式。

## Rationale / 理由

The taxonomy balances semantics with operational stability.

该分类法在语义表达与操作稳定性之间做平衡。

The Greek prefix provides a memorable family marker. The domain code provides technical precision. The index allows the system to scale without forcing ad hoc suffixes or disruptive renames.

希腊前缀提供可记忆的家族标识，领域代码提供技术精度，而索引则使系统能够扩展，而不必依赖临时后缀或通过重命名来腾挪空间。

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
- `pi` -> geometry / computation
- `omega` -> concurrency / async

### Reserved or Weakly Associated Prefixes / 保留或弱关联前缀

These prefixes may be reserved for future use or only adopted with explicit review:

这些前缀可为未来保留，或仅在明确审查后使用：

- `kappa` -> reserved or weakly associated; not adopted as a core mapping in this ADR

## Consequences / 后果

This decision produces several practical consequences:

该决策带来以下实际后果：

- Repository names become easier to interpret across the portfolio.
- New repositories can be assigned names with less ad hoc discussion.
- Existing accepted names can remain stable even if some symbolic associations are imperfect.
- Future review can focus on governance quality rather than symbolic over-optimization.

- 作品集中的仓库名称会更易于整体解释。
- 新仓库在命名时可以减少临时性的讨论成本。
- 即使某些符号关联并不完美，现有已接受名称仍可保持稳定。
- 未来审查可以更多聚焦于治理质量，而不是符号层面的过度优化。

The decision also imposes discipline:

该决策也带来约束：

- weak mappings must be labeled honestly
- naming churn should be avoided
- public naming stability is prioritized over retrospective symbolic refinement

- 弱映射必须被诚实标注
- 应避免命名震荡
- 对公开仓库而言，命名稳定性优先于事后追求符号更“纯”

## Non-Goals / 非目标

This ADR does not attempt to:

本 ADR 不试图实现以下目标：

- prove a universal symbolic correspondence for every Greek letter
- standardize all repository internals, build systems, or code structures
- force immediate renaming of existing repositories
- define a complete ontology for every future technical domain
- treat weak associations as textbook-level facts

- 证明每一个希腊字母都具有普适性的学科对应
- 统一所有仓库的内部结构、构建系统或代码组织
- 强制现有仓库立即改名
- 为所有未来技术领域建立一套完备本体
- 将弱关联包装成教科书级事实

## Current Accepted Grammar / 当前采纳的命名语法

The currently accepted grammar is:

当前采纳的命名语法如下：

```text
repository-name := <greek-prefix> "-" <domain-code> <index>
greek-prefix    := lower-case Greek name written in ASCII letters
domain-code     := 4 to 5 lower-case ASCII letters
index           := 2 or more digits, zero-padded when practical
```

Interpretation guidance:

解释约定：

- use lower-case ASCII for portability and consistency
- avoid punctuation beyond the single hyphen separator
- keep domain codes stable once publicly used
- prefer creating a new indexed repository over renaming a public repository for minor semantic refinement

- 使用小写 ASCII，以提高可移植性和一致性
- 除单个连字符分隔符外，避免使用其他标点
- 领域代码一旦公开使用，应尽量保持稳定
- 若只是为了轻微语义优化，优先新增同系列索引仓库，而不是重命名公开仓库

## Follow-Up Actions / 后续行动

- Record future accepted names in a lightweight registry or appendix update process.
- Review reserved prefixes only when a real repository requires them.
- Add short reviewer guidance to the root README in a future change if the portfolio becomes more public-facing.
- Revisit domain-code coverage only when new areas cannot be represented clearly by the existing codes.

- 将未来新接受的名称记录到轻量注册表或附录更新流程中。
- 仅在确有真实仓库需求时审查保留前缀。
- 如果作品集未来面向公众展示的程度更高，可在后续变更中把简短审核说明加入根 README。
- 只有在新领域无法被现有代码清晰表达时，才重新审查领域代码覆盖范围。

## Appendix A / 附录 A: Core Mapping Table / 核心映射表

| Greek Prefix | 中文前缀 | Domain Family | 中文领域 | Example Repository | Classification | Notes |
| --- | --- | --- | --- | --- | --- | --- |
| delta | 德尔塔 | graphics / rendering | 图形学 / 渲染 | `delta-grfx01` | stronger | Strong practical association with change, rendering pipelines, and graphics-oriented branding; used here as a stable family marker rather than a universal theorem. |
| lambda | 拉姆达 | compiler / language | 编译器 / 语言 | `lambda-ccmp01` | stronger | Strong association with formal systems, lambda calculus, and language-oriented work. |
| epsilon | 艾普西龙 | mathematics / numerics | 数学 / 数值计算 | `epsilon-math01` | stronger | Well-suited for mathematical and numerical work; broad but stable. |
| zeta | 泽塔 | algorithms / complexity | 算法 / 复杂度 | `zeta-algo01` | conventional | Acceptable as a portfolio convention, but not presented as a universally canonical algorithms symbol. |
| eta | 艾塔 | systems / efficiency | 系统 / 效率 | `eta-mmgr01` | stronger | Used for systems-oriented, performance-aware, or efficiency-related repository families. |
| theta | 西塔 | AI / machine learning | 人工智能 / 机器学习 | `theta-nnet01` | stronger | Strong practical fit due to common parameter notation and optimization contexts. |
| iota | 约塔 | tools / utilities | 工具 / 实用程序 | `iota-bldt01` | conventional | Chosen as a compact conventional label for smaller tools and utilities, without claiming canonical status. |
| sigma | 西格玛 | statistics / data | 统计 / 数据 | `sigma-stat01` | stronger | Strong statistical association, especially with summation and aggregate reasoning. |
| pi | 派 | geometry / computation | 几何 / 计算几何 | `pi-geom01` | conventional | Widely recognizable and acceptable for geometry-related work, but broader than a strict canonical mapping. |
| phi | 斐 | physics / simulation | 物理 / 仿真 | `phi-phys01` | stronger | Commonly used in physics and field notation; appropriate for simulation-oriented repositories. |
| omega | 欧米伽 | concurrency / async | 并发 / 异步系统 | `omega-async01` | conventional | Accepted here as an end-state or systems-scale convention, not as a universal concurrency symbol. |

## Appendix B / 附录 B: Extended or Reserved Prefixes / 扩展或保留前缀

| Greek Prefix | 中文前缀 | Suggested Domain | 中文建议领域 | Status | Notes |
| --- | --- | --- | --- | --- | --- |
| kappa | 卡帕 | reserved / to be reviewed | 保留 / 待审查 | reserved | Weak association in this taxonomy; do not treat as a core established mapping without a concrete need. |
| gamma | 伽马 | reserved for future technical fit | 为未来技术方向保留 | reserved | May be assigned later if a clear, durable portfolio use emerges. |
| mu | 缪 | reserved for future technical fit | 为未来技术方向保留 | reserved | Keep unassigned until a real repository family requires it. |
| rho | 柔 | reserved for future technical fit | 为未来技术方向保留 | reserved | Avoid speculative assignment without practical naming pressure. |

## Appendix C / 附录 C: Domain Code Conventions / 领域代码约定

Domain codes provide the precise technical discriminator inside a repository family. They should be short, memorable, and semantically stable.

领域代码用于在同一家族内部提供更精确的技术区分。它们应当简短、易记，并在语义上保持稳定。

Recommended conventions:

推荐约定：

- use 4 to 5 lower-case ASCII letters
- prefer recognizable abbreviations over opaque compression
- keep one dominant meaning per code
- avoid reusing one code for unrelated technical areas

- 使用 4 到 5 个小写 ASCII 字母
- 优先选择可识别缩写，而非过度压缩
- 每个代码尽量对应一个主导含义
- 避免将同一代码复用于彼此无关的技术方向

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

## Appendix D / 附录 D: Current Accepted Examples / 当前已接受示例

| Repository | Interpretation | 中文解释 | Prefix Strength | Notes |
| --- | --- | --- | --- | --- |
| `delta-grfx01` | graphics / rendering repository in the delta family | 属于 delta 家族的图形学 / 渲染仓库 | stronger | Accepted as a stable public-facing graphics family name. |
| `lambda-ccmp01` | compiler or language implementation repository in the lambda family | 属于 lambda 家族的编译器或语言实现仓库 | stronger | Appropriate for parsing, compiling, or language-system work. |
| `epsilon-math01` | mathematics or numerics repository in the epsilon family | 属于 epsilon 家族的数学或数值计算仓库 | stronger | Suitable for numerical methods, applied math, or analytical experiments. |
| `eta-mmgr01` | systems-oriented memory-management repository in the eta family | 属于 eta 家族的系统向内存管理仓库 | stronger | Indicates systems and efficiency concerns more than pure theory. |
| `theta-nnet01` | neural-network repository in the theta family | 属于 theta 家族的神经网络仓库 | stronger | Suitable for ML experimentation and parameterized model work. |

## Appendix E / 附录 E: Practical Review Criteria for New Names / 新命名的实务审核标准

Use the following checklist before accepting a new repository name:

在接受新的仓库命名前，可使用以下检查清单：

- Does the name follow the grammar `<greek-prefix>-<domain-code><index>`?  
  该名称是否符合 `<greek-prefix>-<domain-code><index>` 语法？
- Is the prefix classification honest: stronger, conventional, or reserved?  
  前缀分类是否诚实明确：较强、约定性，还是保留？
- Does the chosen domain code describe the repository more precisely than the prefix alone?  
  所选领域代码是否比前缀本身更精确地描述了仓库？
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
