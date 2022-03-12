#

### git commit

<details>

commit message 格式

```
<type>(<scope>): <subject>
// 空一行
<body>
// 空一行
<footer>
```

```
-----------------------------------------------------------
feat：    新功能 (feature)
fix：     修补 (bug)
docs：    文档 (documentation)
style：   格式 (不影响代码运行的变动)
refactor：重构 (即不是新增功能, 也不是修改 bug 的代码变动)
test：    增加测试
chore：   构建过程或辅助工具的变动
-----------------------------------------------------------
code:     杂项
```

更改上一个 commit 内容

```git
git commit --amend
```

更改 commit 时间为当前时间

```git
git commit --amend --date="$(date -R)"
```

</details>

### git merge

<details>

开发分支（dev) 上的代码达到上线的标准后，要合并到 master 分支

```
git checkout dev
git pull
git checkout master
git merge dev
git push -u origin master
```

当 master 代码改动了，需要更新开发分支 (dev) 上的代码

```
git checkout master
git pull
git checkout dev
git merge master
git push -u origin dev
```

</details>

### git rebase

<details>

<!-- <summary> </summary> -->

</details>

<!-- TODO -->


### git stash

<details>

临时保存修改，并命名


```
git stash save "fix: ..."
```


保存开发到一半的代码

```
# ... hack hack hack ...
git stash                    // 保存开发到一半的代码
# ... edit emergency fix ...
git commit -a -m "fix: ..."
git stash pop                // 将代码追加到最新的提交之后, 并删除该缓存
# ... continue hacking ...
```

查看现有 stash

```
git stash list
```

应用指定缓存

```
git stash apply @{%d}
```

</details>


<!-- TODO -->