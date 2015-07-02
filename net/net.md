[TOC]

### ubuntu下查看端口命令：
* 查看哪些进程打开了指定端口port（对于守护进程必须以root用户执行才能查看到）
>lsof -i:port

* 查看哪些进程打开了指定端口port，最后一列是进程ID（此方法对于守护进程作用不大）
>netstat -nap|grep port

* 查看端口号对应的系统服务名称
>cat /etc/services

* 启动｜停止｜重启系统服务
>sudo /etc/init.d/service start|stop|restart


### php socket
[socket](www.cnblogs.com/thinksasa/archive/2013/02/26/2934206.html)

