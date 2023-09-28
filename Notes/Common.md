
### 常见问题

```bash
make[2]: warning:  Clock skew detected.  Your build may be incomplete.
```

<details>

<!-- <summary>  </summary> -->

```bash
$ touch * # 无效
```

```
两系统时间不一致，顾同步时间
```

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

```
找到按键映射

Plug-ins -> Terminal -> Switch Focus To Editor
( -> 将焦点切换到编辑器 )

删除该按键绑定
```

</details>

---

```
压缩 WSL2 虚拟磁盘 (VHD) 占用空间
```

<details>

```powershell
wsl --shutdown
diskpart
# open window Diskpart
select vdisk file="C:\WSL-Distros\…\ext4.vhdx"
attach vdisk readonly
compact vdisk
detach vdisk
exit
```

</details>

---

```
WSL2 报错

占位程序接收到错误数据。
Error code: Wsl/Service/0x800706f7
Press any key to continue...
```

<details>

```powershell
sudo netsh winsock reset
```

</details>

---







