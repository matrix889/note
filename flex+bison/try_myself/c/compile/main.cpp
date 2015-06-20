#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int nameSize = 150;
int ROWS;
int n;
fstream input, output;

struct node{
    char stategy[nameSize];
    int score;
    node();
    node(char *tmp, int score){
        strcpy(stategy, tmp);
        this->score = score;
    }

    bool operator<(const node&b){
        return this->score < b.score;
    }
};

vector<node> q;

void runStategy(char* fileName){
    char *cmd = new char[nameSize], *path = "./../work/work < ", *pasteTree = " > paste.txt";
    memset(cmd, 0, sizeof(char) * nameSize);
    input.open(fileName, ios::in);

    strcat(cmd, path);
    strcat(cmd, fileName);
    strcat(cmd, pasteTree);
    system(cmd);
    delete []cmd;
    input.close();
}

char* getStategy(char stategyName[]){
    char *sN = new char[nameSize];
    memset(sN, 0, sizeof(char) * nameSize);

    strcat(sN, "../stategy/");
    strcat(sN, stategyName);
    return sN;
}

char* makeDir(char stategyName[]){
    char *dirName = new char[nameSize];
    char *cmd = new char[nameSize];
    memset(cmd, 0, sizeof(char) * nameSize);
    memset(dirName, 0, sizeof(char) * nameSize);

    sscanf(stategyName, "%[^.]", dirName);
    strcat(cmd, "mkdir ../stategy/");
    strcat(cmd, dirName);
    strcat(cmd, " 2>/dev/null");

    system(cmd);
    //delete []dirName;
    delete []cmd;
    return dirName;
    //printf("%s", cmd);
}

void rmDir(char stategyName[]){
    char *dirName = new char[nameSize];
    char *cmd = new char[nameSize];
    memset(dirName, 0, sizeof(char) * nameSize);
    memset(cmd, 0, sizeof(char) * nameSize);

    sscanf(stategyName, "%[^.]", dirName);
    strcat(cmd, "rm -rf ../stategy/");
    strcat(cmd, dirName);

    system(cmd);
    //delete []dirName;
    delete []cmd;
    delete []dirName;
}

//ls ../stategy/*.w | cut -d '/' -f 3 > ../stategy_name.txt
void solve(){
    //保存下所有策略到state_name.txt
    system("ls ../stategy/*.w | cut -d '/' -f 3 > ../stategy_name.txt");
    //FILE *fp;
    //fp = fopen("../stategy_name.txt");
    char *fileName = new char[nameSize];
    memset(fileName, 0, sizeof(char) * nameSize);
    input.open("../stategy_name.txt", ios::in);

    cout << "策略名：" << endl;
    while (input >> fileName){
        if (input.eof()) break;
        makeDir(fileName);
        //rmDir(fileName);
    }
    //cout << endl << endl;
    input.close();
}

void copyFile(char *stategy1, char *stategy2){
    char *cmd = new char[nameSize];
    memset(cmd, 0, sizeof(char) * nameSize);
    strcat(cmd, "cp ../stategy/");
    strcat(cmd, stategy1);
    strcat(cmd, " ../stategy1.w");
    system(cmd);

    memset(cmd, 0, sizeof(char) * nameSize);
    strcat(cmd, "cp ../stategy/");
    strcat(cmd, stategy2);
    strcat(cmd, " ../stategy2.w");
    system(cmd);
    delete []cmd;
}

void addCMD(char *stategy, int gameRows, int numofOne, int pre, int prePre){
    char *cmd = new char[nameSize];
    sprintf(cmd, "T(%d,%d,%d,%d)\n", gameRows, numofOne, pre, prePre);
    output.open(stategy, ios::out|ios::app);
    output << cmd;
    output.close();
}

int getState(){
    char c;
    int state;
    input.open("result.txt", ios::in);
    input >> c >> state;
    input.close();
    return state;
}

int fight(char *stategy1, char *stategy2, int rows){
    int score1 = 0, score2 = 0, pre = 1, prePre = 1;
    //runStategy("stategy1.w");
    //addCMD((char*)"../stategy1.w", 1, 0, 1, 1);
    //runStategy("../stategy1.w");
    //rows = 1;
    int ones1 = 0, ones2 = 0;
    for (int i = 1; i <= rows; ++i){
        copyFile(stategy1, stategy2);
        int part1, part2;
        /*if (i > 1){
            prePre = pre;
            pre = getState();
            if (pre == 1) ones2 = ones2 + 1;
        }*/
        //cout << pre << "what the fuck" << endl;
        addCMD((char*)"../stategy1.w", i, ones1, pre, prePre);
        runStategy("../stategy1.w");
        prePre = pre;
        pre = part1 = getState();
        if (part1 == 1) ++ones1;

        addCMD((char*)"../stategy2.w", i, ones2, pre, prePre);
        runStategy("../stategy2.w");
        prePre = pre;
        pre = part2 = getState();
        if (part2 == 1) ++ones2;

        if (part1 == 0){
            switch (part2){
            case 0:
                score1 += 1;
                score2 += 1;
                break;
            case 1:
                score1 += 5;
                score2 += 0;
            }
        }
        else{
            switch (part2){
            case 0:
                score1 += 0;
                score2 += 5;
                break;
            case 1:
                score1 += 3;
                score2 += 3;
            }
        }
    }

    //cout << score1 << " " << score2 << endl;
    return score1;
}

char* getStategyDir(char *fileName){
    char *cmd = new char[nameSize], *tmp = new char[nameSize];
    memset(cmd, 0, sizeof(char) * nameSize);
    strcat(cmd, "../stategy/");
    sscanf(fileName, "%[^.]", tmp);
    strcat(cmd, tmp);
    strcat(cmd, "/");

    delete []tmp;
    return cmd;
}


void getPasteTree(char *fileName){
    char *cmd = new char[nameSize], *path = "./../work/work < ";
    char *stategyDir, *stategyPath = new char[nameSize];
    char *pasteTree = new char[nameSize];

    memset(cmd, 0, sizeof(char) * nameSize);
    memset(stategyPath, 0, sizeof(char) * nameSize);
    memset(pasteTree, 0, sizeof(char) * nameSize);
    stategyDir = getStategyDir(fileName);
    strcat(stategyPath, "../stategy/");
    strcat(stategyPath, fileName);
    strcat(cmd, path);
    strcat(cmd, stategyPath);
    strcat(cmd, " > ");
    //input.open(fileName, ios::in);

    //strcat(pasteTree, getStategyDir(fileName));
    strcat(pasteTree, stategyDir);
    strcat(pasteTree, "paste.txt");

    strcat(cmd, pasteTree);
    system(cmd);
    delete []cmd;
    input.close();
}

char s[nameSize];
void cmpStategies(){
    system("ls ../stategy/*.w | cut -d '/' -f 3 > ../stategy_name.txt");
    q.clear();
    input.open("../stategy_name.txt", ios::in);

    while (input >> s){
        q.push_back(node(s, 0));
    }
    for (int i = 0; i < q.size(); ++i){
        cout << q[i].stategy << endl;
        getPasteTree(q[i].stategy);
    }
    cout << endl;

    for (int i = 0; i < q.size(); ++i){
        for (int j = 0; j < q.size(); ++j){
            //cout << q[i].stategy << " " << q[j].stategy << endl;
            if (i == j) continue;
            q[i].score += fight(q[i].stategy, q[j].stategy, ROWS);
        }
    }
    sort(q.begin(), q.end());
    cout << "排名     " << "得分" << endl;
    for (int i = 0; i < q.size(); ++i)
        cout << q[i].stategy << "     " << q[i].score << endl;
    cout << endl;

    output.open("../sort.txt", ios::out);
    for (int i = 0; i < q.size(); ++i)
        output << q[i].stategy << " " << q[i].score << endl;
}

void showPasteTree(char *name){
    char *cmd = new char[nameSize];
    memset(cmd, 0, sizeof(char) * nameSize);
    strcat(cmd, "gedit ");
    strcat(cmd, getStategyDir(name));
    strcat(cmd, "paste.txt");
    system(cmd);
    delete []cmd;
}

int main(){
	//cin >> n;
	cout << "当前目录为：" << endl;
    system("echo $PWD");
    cout << endl;

    ROWS = 50;
	//runStategy(" < ../stategy/T1.w", 0);
	//runStategy(getStategy((char*)"T1.w"), 0);
	//makeDir((char*)"T1.w");
	//fight("T1.w", "T2.w", 50);
    //cout << "Hello world!" << endl;
    int CMD, ok = 0;
    do{
        cout << "请输入指令,0退出，1代表进行对战，2代表输入新策略,3查看策略对应的语法树" << endl;
        cin >> CMD;
        //cout << endl;
        if (CMD == 1){
            cout << "请输对战轮数：";
            cin >> ROWS;
            cout << endl;
            solve();
            cmpStategies();
            ok = 1;
        }
        else if (CMD == 2){
            system("gedit");
            cout << "(1)请输入策略，并以后缀名为.w的文件保存在stategy文件夹中！！！" << endl;
            cout << "(2)接口函数名为：function T(gameRows, Ones, pre, prePre)" << endl;
            cout << "(3)其中，gameRows代表当前进行到游戏的第几轮，Ones表示已经选择了多少个1，pre表示上一轮对手的选择，prePre代表上自己的选择。" << endl;
            ok = 0;
        }
        else if (CMD == 3){
            if (!ok) cout << "请先输入指令2以生成语法树!" << endl;
            else{
                cout << "请输入要查看的策略名:" << endl;
                char *name = new char[nameSize];
                cin >> name;
                showPasteTree(name);
                delete[] name;
            }
        }
    }while (CMD != 0);
    return 0;
}
