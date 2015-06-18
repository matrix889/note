[TOC]

### LAMP环境搭建

#### PHP环境

[PHP安装配置](http://dsec.pku.edu.cn/~lyj/Programming/configure_php.html)
[LAMP配置](http://www.linuxidc.com/Linux/2012-05/61079.htm)

1. LAMP 的安装

    sudo apt-get install apache2 mysql-server mysql-client php5 php5-gd php5-mysql

由于LAMP大部分操作与/var/www目录相关，为了方便，修改该目录的权限为普通用户可访问。

 >sudo chmod 777 /var/www/

2. phpmyadmin 安装

    sudo apt-get install phpmyadmin

    在安装过程中会要求选择Web server：apache2或lighttpd，选择apache2，按tab键然后确定。然后会要求输入设置的Mysql数据库密码连接密码 Password of the database's administrative user。

    然后将phpmyadmin与apache2建立连接，以我的为例：www目录在/var/www，phpmyadmin在/usr/share /phpmyadmin目录，所以就用命令：sudo ln -s /usr/share/phpmyadmin /var/www 建立连接。

    phpmyadmin测试：在浏览器地址栏中打开http://localhost/phpmyadmin。

3. Apache 配置

（1）启用 mod_rewrite 模块

   > 终端命令：sudo a2enmod rewrite

（2）重启Apache服务器：sudo /etc/init.d/apache2 restart

   > Apache重启后可以测试一下，在/var/www目录下新建文件test.php，写入代码： 保存，在地址栏输入http://127.0.0.1/test.php 或 http://localhost/test.php ，如果正确出现了Mysql已经正确配置，表明Apache和mysql都正常了。(记得重启Apache服务器后再测试)。

test.php
```php
    <?php
        $link = mysql_connect("localhost","root","mysql密码");
         
        if (!$link)
         
        {
         
        die('Could not connect: ' . mysql_error());
         
        }
         
        else echo "Mysql已经正确配置";
         
        mysql_close($link);
         
        ?>
?>
```
4. 浏览器PHP中文乱码问题

上面在FireFox浏览器中打开test.php测试时，如果出现了中文乱码，则是默认语言设置问题，解决方法如下：

>打开apache配置文件： udo gedit /etc/apache2/apache2.conf，在最后面加上：AddDefaultCharset UTF-8，如果还是乱码的，再将UTF-8改用gb2312。

>重启Apache：sudo /etc/init.d/apache2 restart 再刷新test.php 中文乱码没有了


4、安装phpmyadmin
>sudo apt-get install phpmyadmin

安装完成后访问：http://localhost/phpmyadmin/，提示not found。还需要把安装好的phpmyadmin文件夹放入/var/www/。

>sudo ln -s /usr/share/phpmyadmin/ /var/www/

或者将phpmyadmin直接复制到/var/www。 

5、安装adminer
adminer就是一个php文件，从http://www.adminer.org/下载，放入/var/www/。比如在/var/www新建adminer文件夹，将下载的adminer-3.5.1.php或者其他版本放入该文件夹，然后访问http://localhost/adminer/，点击php文件即可。
linux