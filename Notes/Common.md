
### 常见问题

```bash
make[2]: warning:  Clock skew detected.  Your build may be incomplete.
```

<details>

<!-- <summary>  </summary> -->

```bash
$ touch * # 无效
```

两系统时间不一致，顾同步时间

```bash
$ sudo ntpdate ntp.sjtu.edu.cn
$ sudo hwclock --localtime --systohc
```

</details>


---


```
IDEA 终端 Vim 无法使用 Esc
```

<details>

找到按键映射

```
Plug-ins -> Terminal -> Switch Focus To Editor
( -> 将焦点切换到编辑器 )
```

删除该按键绑定

</details>


