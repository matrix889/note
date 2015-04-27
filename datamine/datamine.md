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
