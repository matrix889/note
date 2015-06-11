

重装的ubuntu系统(ubuntu server)的开发环境几乎是裸的，再重新编译安装erlang需要一些关键库，去年装过，今年再装又忘了，记之备查

1. gcc/g++、make等开发工具
Bash代码

    sudo apt-get install build-essential

sudo apt-get install build-essential

2. 其它Erlang用到的关键库
Bash代码

    sudo apt-get install libncurses5-dev
    sudo apt-get install m4
    sudo apt-get install libssl-dev

sudo apt-get install libncurses5-dev
sudo apt-get install m4
sudo apt-get install libssl-dev

3. 此外还有一些非关键库也可以装上，不然make也通不过
Bash代码

    sudo apt-get install libc6 （这个新Ubuntu 9.10不用再装了）
    sudo apt-get install unixodbc unixodbc-dev  ODBC方式提供对传统关系数据库支持
    sudo apt-get install freeglut3-dev libwxgtk2.8-dev

sudo apt-get install libc6 （这个新Ubuntu 9.10不用再装了）
sudo apt-get install unixodbc unixodbc-dev  ODBC方式提供对传统关系数据库支持
sudo apt-get install freeglut3-dev libwxgtk2.8-dev

4. 安装JDK,需要这个编译JInterface
sudo apt-get install sun-java6-jdk
注：
安装完jdk后最好检查一下javac，因为新安装的JDK不一定会自动成为缺省的JDK。（JInterface是JDK5的, 若缺省JDK低于1.5，make到JInterface时依然会出错），检查java编译器的版本：
Bash代码

    javac -version

javac -version

如果不是刚安装的版本，修改javac链接指向新位置：
Bash代码

    rm /etc/alternatives/javac
    ln -s /usr/lib/jvm/java-6-sun/bin/javac /etc/alternatives/javac

    rm /etc/alternatives/java
    ln -s /usr/lib/jvm/java-6-sun/bin/java /etc/alternatives/java

rm /etc/alternatives/javac
ln -s /usr/lib/jvm/java-6-sun/bin/javac /etc/alternatives/javac

rm /etc/alternatives/java
ln -s /usr/lib/jvm/java-6-sun/bin/java /etc/alternatives/java

从Ubuntu 10.04开始,apt-get不再缺省提供sun-jdk，手动添加源：
Bash代码

    sudo apt-add-repository ”deb http://archive.canonical.com/ lucid partner”

sudo apt-add-repository "deb http://archive.canonical.com/ lucid partner"

或者去官方网站下载：

http://java.sun.com/javase/downloads/widget/jdk6.jsp

安装后设置环境变量JAVA_HOME和PATH，并在/usr/bin中设置java和javac的符号链接：
Bash代码

    sudo ln -s /usr/local/jdk1.6.0_20/bin/java /usr/bin/java
    sudo ln -s /usr/local/jdk1.6.0_20/bin/javac /usr/bin/javac

sudo ln -s /usr/local/jdk1.6.0_20/bin/java /usr/bin/java
sudo ln -s /usr/local/jdk1.6.0_20/bin/javac /usr/bin/javac

5. 在R13B03后,帮助文档的生成方式有了变化,要想自动生成帮助文件,需要安装xsltproc和
Bash代码

    sudo apt-get install xsltproc
    sudo apt-get install fop

sudo apt-get install xsltproc
sudo apt-get install fop

都挺大的,如果不在乎文档,可以不安装,不影响make

