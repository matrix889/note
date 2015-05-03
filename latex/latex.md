[TOC]

#### 1. 安装:
>使用下面命令可以在 Ubuntu 上安装 Tex Live
1 	sudo apt-get install texlive-full
要编辑 LaTeX 文档需要一个编辑器，你可以找到很多编辑器，这里我们推荐 Texmaker
1 	sudo apt-get install texmaker 

#### 2. Sublime Text 2 下配置latex运行环境:
* 点击Preferences > Packages Settings > LaTeXTools > Reconfigure LaTeXTools and migrate settings
* 点击Preferences > Packages Settings > LaTeXTools > Setting-User，找到windows部分，该成一下内容：
>"windows": {
	"textpath" : "$PATH",
	"distro"   : "texlive"
},
