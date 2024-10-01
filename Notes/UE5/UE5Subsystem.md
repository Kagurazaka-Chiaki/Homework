# UE5 Subsystem 子系统

创建具有明确定义的生命周期的全局可访问的模块

子系统的生存期将与其父级的生存期匹配。有 5 种不同的父类

| Subsystem 子系统 | Parent Class 父类        | Lifetime 生命周期                      |
| :--------------- | ------------------------ | -------------------------------------- |
| Engine           | `UEngineSubsystem`       | Engine                                 |
| Editor           | `UEditorSubsystem`       | 当 Editor 启动                         |
| GameInstance     | `UGameInstanceSubsystem` | 游戏开始后，保持活动状态，直到游戏关闭 |
| LocalPlayer      | `ULocalPlayerSubsystem`  | 匹配其父级 `ULocalPlayer` 的生命周期   |
| World            | `UWorldSubsystem`        | 匹配其父级 `UWorld`                    |

没有办法创建 Subsystem 的 Blueprint 子类，因此要公开数据供设计人员控制，必须想出一种替代方法。

[more](https://dev.epicgames.com/documentation/en-us/unreal-engine/programming-subsystems-in-unreal-engine?application_version=5.4)

每个可以拥有子系统的对象都有一个与之关联的 `FSubsystemCollection`, 比如 `UGameInstance` 包含 `FSubsystemCollection<UGameInstanceSubsystem>`。

当 `GameInstance` 中 `Init` 函数被调用时，其 `FSubsystemCollection` 会查看从其继承的所有内容 `UGameInstanceSubsystem`（或它当时正在使用的任何子系统）。

如果 `USubsystem->ShouldCreateSubsystem` 返回 `true`，那么它将创建关联的子系统作为新对象，并将其作为 `FSubsystemCollection` 其父级（在我们的例子中是）的父级 UGameInstance。

因此实际上，我们所有的子系统都是作为主系统的子系统创建的。

最终结果是，可以使用 `UGameInstanceSubsystem` 的任何有效子类调用 `UGameInstance->GetSubsystem`，它将返回该类的实例。这类似于在 `Actor` 上拥有组件。

子系统本身实际上不执行任何操作。它不会被调用任何内容，并且不会覆盖任何函数。您可以使用 `Initialize` 和 `Deinitialize` 来启动和停止子系统，

