[TOC]
### python
>ubuntu 下安装mysqldb
sudo apt-get install python-mysqldb

* python 连接 mysql
```python

#!/usr/bin/python
# Filename: pp.py
import sys
import MySQLdb

#set the encoding to utf8 to ensure the Chinese echo normal
reload(sys)
sys.setdefaultencoding('utf8')

conn = MySQLdb.connect(host='localhost',user='root',passwd='',charset='utf8')
conn.select_db('test')
curs = conn.cursor()
count = curs.execute('select * from sutdent')
print "the sum of record %s" % count 

result = curs.fetchone()
#get the current one result
print "the current record is name: %s id :%s" % result
#pay attend to the 
results = curs.fetchmany(2)

for i in results: 
	print i

#reset the cursor to the position 0, mode = relative(default)
curs.scroll(0, mode='absolute')
results = curs.fetchall()
print "the number of records %d" %curs.rowcount
for i in results:
	print i

f = file('/home/wzx/sublime/test1.txt', 'w')
for i in results:
	f.write(str(i)+'\n')

sql = 'insert into sutdent values("what", "10086")'
try:
	curs.execute(sql)
	conn.commit()
except:
	conn.rollback()

conn.commit()
curs.close()
curs.close()

```
### SomeThing to read
[python+mysql](http://blog.csdn.net/yelbosh/article/details/7498641)
[k-Means](http://blog.csdn.net/jairuschan/article/details/7516989)
[python-theano](http://wiki.swarma.net/index.php?title=%E5%88%A9%E7%94%A8python%E7%9A%84theano%E5%BA%93%E5%88%B7kaggle_mnist%E6%8E%92%E8%A1%8C%E6%A6%9C&variant=zh-cn)
[Deep-learning](http://blog.csdn.net/u012162613/article/details/42651233)
[kaggle](http://doc.okbase.net/u012162613/archive/118848.html)
[to_use_kaggle](blog.csdn.net/u012162613/article/details/41929171)
[numpy](http://blog.csdn.net/u012162613/article/details/42784403)