[TOC]

### 下载工具：
#### aria2
1. 安装： sudo apt-get install aria2
2. 使用： aria2c http://.....

#### vim 快捷键
vimtutor:linux下自带vim教程
* 交换两个字符的位置：xp   
* 交换两行的位置：ddp  
* 调换两个单词（光标开始处于第一个单词的左边）：deep
* 10.2 复制与移动行

语法：

       :x,ycoz

       :x,ymz

说明：
1      x，y，z都是行号。x，y是源行，z是目标行号。
2      源行x,y被复制或移动，插入到z行的下面。
3      :m删除原始行，:co不删除原始行。

[如何使用vim](http://www.zhihu.com/question/20565366)
[vim to amcer](http://www.cnblogs.com/ma6174/archive/2012/02/02/2335835.html)
[how to use vim](http://www.iplaysoft.com/vim.html)

#### 右键打开终端：

1. 把终端加到右键菜单：
```
sudo apt-get install nautilus-open-terminal
```

2. 右键单击文件或文件夹以 root 权限打开：
```
sudo apt-get install nautilus-gksu
```

3. 重新加载文件夹
```
nautilus -q
```

#### teamviewer

[how to install](http://askubuntu.com/questions/362951/installed-teamviewer-using-a-64-bits-system-but-i-get-a-dependency-error)

4. 问题： lock

运行程序更新时出现报错：

无法获得锁 /var/lib/dpkg/lock - open (11: 资源临时不可用)

解决：
其实这是因为有另外一个程序在运行，导致锁不可用。原因可能是上次运行更新或安装没有正常完成。解决办法是杀死此进程
>sudo rm /var/cache/apt/archives/lock
sudo rm /var/lib/dpkg/lock

5. 更新：
>sudo apt-get update
sudo apt-get upgrape
