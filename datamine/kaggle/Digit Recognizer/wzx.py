#!/usr/bin/python
# Filename: wzx.py

from numpy import *
import csv

def toInt(array):
    array=mat(array)
    m,n=shape(array)
    newArray=zeros((m,n))
    for i in xrange(m):
        for j in xrange(n):
                newArray[i,j]=int(array[i,j])
    return newArray
    
def nomalizing(array):
    m,n=shape(array)
    for i in xrange(m):
        for j in xrange(n):
            if array[i,j]!=0:
                array[i,j]=1
    return array
    
def loadTrainData():
    l=[]
    with open('train.csv') as file:
         lines=csv.reader(file)
         for line in lines:
             l.append(line) #42001*785
    l.remove(l[0])
    l=array(l)
    label=l[:,0]
    data=l[:,1:]
    return nomalizing(toInt(data)),toInt(label)  #label 1*42000  data 42000*784
    #return trainData,trainLabel
    
def loadTestData():
    l=[]
    with open('test.csv') as file:
         lines=csv.reader(file)
         for line in lines:
             l.append(line)#28001*784
    l.remove(l[0])
    data=array(l)
    return nomalizing(toInt(data))  #  data 28000*784
    #return testData
    
def saveResult(result,csvName):
    with open(csvName,'wb') as myFile:    
        myWriter=csv.writer(myFile)
        id = 1
        c1 = "\'ImageId\'"
        c2 = "\'Label\'"
        myWriter.writerow([c1, c2])

        for i in result:
            c = "\'" + str(int(i)) + "\'"

            tmp=[]
            tmp.append(id)
            tmp.append(c)
            id = id + 1
            myWriter.writerow(tmp)

def loadTestResult():  
    l=[]  
    with open('knn_benchmark.csv') as file:  
         lines=csv.reader(file)  
         for line in lines:  
             l.append(line)  
     #28001*2  
    l.remove(l[0])  
    label=array(l) 
    return toInt(label[:,1])  

from sklearn import tree
def treeClassify(trainData,trainLabel,testData): 
	clf = tree.DecisionTreeClassifier()
	clf.fit(trainData, ravel(trainLabel))
	testLabel = clf.predict(testData)
	saveResult(testLabel, 'DecisionTreeClassifier.csv')
	return testLabel

def digitRecognition():
    trainData,trainLabel=loadTrainData()
    testData=loadTestData()
    result=treeClassify(trainData,trainLabel,testData)
    
    # print "ok"
    # result = mat(result)
    # m,n=shape(result)
    # # saveResult(result, 'result.csv')
    # resultList = []
    # resultList.append(["ImageId","Label"])
    # for i in range(n):
    #     resultList.append([i + 1, chr(int(result[0][i]))])

    # saveResult(resultList, 'result.csv')


# def handwritingClassTest():  
#     trainData,trainLabel=loadTrainData()  
#     testData=loadTestData()  
#     testLabel=loadTestResult()  
#     m,n=shape(testData)  
#     errorCount=0  
#     resultList=[]  
#     for i in range(m):  
#          classifierResult = treeClassify(testData[i], trainData, trainLabel, 5)  
#          resultList.append(classifierResult)  
#          print "the classifier came back with: %d, the real answer is: %d" % (classifierResult, testLabel[0,i])  
#          if (classifierResult != testLabel[0,i]): errorCount += 1.0  
#     print "\nthe total number of errors is: %d" % errorCount  
#     print "\nthe total error rate is: %f" % (errorCount/float(m))  
#     saveResult(resultList)  
digitRecognition()
# handwritingClassTest()