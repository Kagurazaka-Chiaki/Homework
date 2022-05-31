
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