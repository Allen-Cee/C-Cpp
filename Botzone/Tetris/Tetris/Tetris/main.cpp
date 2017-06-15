//
//  main.cpp
//  Tetris
//
//  Created by Aoi on 4/30/17.
//  Copyright © 2017 Aoi. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <set>
#include <algorithm>
#include <random>
#include <memory.h>
#include <string.h>
using namespace std;

#define MAPWIDTH 10
#define MAPHEIGHT 20
#define MINSCORE -100000000

// 我所在队伍的颜色（0为红，1为蓝，仅表示队伍，不分先后）
int currBotColor;
int enemyColor;

// 先y后x，记录地图状态，0为空，1为以前放置，2为刚刚放置，负数为越界
// （2用于在清行后将最后一步撤销再送给对方）
int gridInfo[2][MAPHEIGHT + 2][MAPWIDTH + 2] = { 0 };

// 代表分别向对方转移的行
int trans[2][4][MAPWIDTH + 2] = { 0 };

// 转移行数
int transCount[2] = { 0 };

// 运行eliminate后的当前高度
int maxHeight[2] = { 0 };

// 总消去行数的分数之和
int elimTotal[2] = { 0 };

// 一次性消去行数对应分数
const int elimBonus[] = { 0, 1, 3, 5, 7 };

// 给对应玩家的各类块的数目总计
int typeCountForColor[2][7] = { 0 };

const int blockShape[7][4][8] = {
    { { 0,0,1,0,-1,0,-1,-1 },{ 0,0,0,1,0,-1,1,-1 },{ 0,0,-1,0,1,0,1,1 },{ 0,0,0,-1,0,1,-1,1 } },
    { { 0,0,-1,0,1,0,1,-1 },{ 0,0,0,-1,0,1,1,1 },{ 0,0,1,0,-1,0,-1,1 },{ 0,0,0,1,0,-1,-1,-1 } },
    { { 0,0,1,0,0,-1,-1,-1 },{ 0,0,0,1,1,0,1,-1 },{ 0,0,-1,0,0,1,1,1 },{ 0,0,0,-1,-1,0,-1,1 } },
    { { 0,0,-1,0,0,-1,1,-1 },{ 0,0,0,-1,1,0,1,1 },{ 0,0,1,0,0,1,-1,1 },{ 0,0,0,1,-1,0,-1,-1 } },
    { { 0,0,-1,0,0,1,1,0 },{ 0,0,0,-1,-1,0,0,1 },{ 0,0,1,0,0,-1,-1,0 },{ 0,0,0,1,1,0,0,-1 } },
    { { 0,0,0,-1,0,1,0,2 },{ 0,0,1,0,-1,0,-2,0 },{ 0,0,0,1,0,-1,0,-2 },{ 0,0,-1,0,1,0,2,0 } },
    { { 0,0,0,1,-1,0,-1,1 },{ 0,0,-1,0,0,-1,-1,-1 },{ 0,0,0,-1,1,-0,1,-1 },{ 0,0,1,0,0,1,1,1 } }
};// 7种形状(长L| 短L| 反z| 正z| T| 直一| 田格)，4种朝向(上左下右)，8:每相邻的两个分别为x，y

class Tetris
{
public:
    const int blockType;   // 标记方块类型的序号 0~6
    int blockX;            // 旋转中心的x轴坐标
    int blockY;            // 旋转中心的y轴坐标
    int orientation;       // 标记方块的朝向 0~3
    const int(*shape)[8]; // 当前类型方块的形状定义
    
    int color;
    
    Tetris(int t, int color) : blockType(t), shape(blockShape[t]), color(color)
    { }
    
    inline Tetris &set(int x = -1, int y = -1, int o = -1)
    {
        blockX = x == -1 ? blockX : x;
        blockY = y == -1 ? blockY : y;
        orientation = o == -1 ? orientation : o;
        return *this;
    }
    
    // 判断当前位置是否合法
    inline bool isValid(int x = -1, int y = -1, int o = -1)
    {
        x = x == -1 ? blockX : x;
        y = y == -1 ? blockY : y;
        o = o == -1 ? orientation : o;
        if (o < 0 || o > 3)
            return false;
        
        int i, tmpX, tmpY;
        for (i = 0; i < 4; i++)
        {
            tmpX = x + shape[o][2 * i];
            tmpY = y + shape[o][2 * i + 1];
            if (tmpX < 1 || tmpX > MAPWIDTH ||
                tmpY < 1 || tmpY > MAPHEIGHT ||
                gridInfo[color][tmpY][tmpX] != 0)
                return false;
        }
        return true;
    }
    
    // 判断是否落地
    inline bool onGround()
    {
        if (isValid() && !isValid(-1, blockY - 1))
            return true;
        return false;
    }
    
    // 将方块放置在场地上
    inline bool place()
    {
        if (!onGround())
            return false;
        
        int i, tmpX, tmpY;
        for (i = 0; i < 4; i++)
        {
            tmpX = blockX + shape[orientation][2 * i];
            tmpY = blockY + shape[orientation][2 * i + 1];
            gridInfo[color][tmpY][tmpX] = 2;
        }
        return true;
    }
    
    // 检查能否逆时针旋转自己到o
    inline bool rotation(int o)
    {
        if (o < 0 || o > 3)
            return false;
        
        if (orientation == o)
            return true;
        
        int fromO = orientation;
        while (true)
        {
            if (!isValid(-1, -1, fromO))
                return false;
            
            if (fromO == o)
                break;
            
            fromO = (fromO + 1) % 4;
        }
        return true;
    }
};

double score[]={
    -8.000158825082766,
    6.0181268101392694,
    -3.2178882868487753,
    -9.348695305445199,
    -7.899265427351652,
    -3.3855972247263626
};


inline double countPDScore(double landingHeight,double rowsEliminated,double rowTransitions,double columnTransitions,double numberOfHoles,double wellSums){

    double scoreResult=landingHeight*score[0]+rowsEliminated*score[1]+rowTransitions*score[2]+columnTransitions*score[3]+numberOfHoles*score[4]+wellSums*score[5];
    
    return scoreResult;
};

// 围一圈护城河
void init()
{
    int i;
    for (i = 0; i < MAPHEIGHT + 2; i++)
    {
        gridInfo[1][i][0] = gridInfo[1][i][MAPWIDTH + 1] = -2;
        gridInfo[0][i][0] = gridInfo[0][i][MAPWIDTH + 1] = -2;
    }
    for (i = 0; i < MAPWIDTH + 2; i++)
    {
        gridInfo[1][0][i] = gridInfo[1][MAPHEIGHT + 1][i] = -2;
        gridInfo[0][0][i] = gridInfo[0][MAPHEIGHT + 1][i] = -2;
    }
}

namespace Util
{
    
    inline bool checkDirectMoveTo(int color, int blockType, int x,int y,int o, int desX){
        Tetris _block(blockType, currBotColor);
        if(!_block.set(x,y,o).isValid()) return false;
        
        auto &def = blockShape[blockType][o];
        int oriX=x;
        if(oriX==desX) return true;
        else if(oriX<desX){
            for (; x <= desX; x++)
                for (int i = 0; i < 4; i++)
                {
                    int _x = def[i * 2] + x, _y = def[i * 2 + 1] + y;
                    //if (_x > desX)
                    //    continue;
                    if (_y < 1 || _x < 1 || _y > MAPHEIGHT || gridInfo[color][_y][_x])
                        return false;
                }
            return true;
        }
        else{
            x=oriX;
            for (; x >= desX; x--)
                for (int i = 0; i < 4; i++)
                {
                    int _x = def[i * 2] + x, _y = def[i * 2 + 1] + y;
                    //if (_x < 1)
                    //    continue;
                    if (_y < 1 || _x < 1 || _y > MAPHEIGHT || gridInfo[color][_y][_x])
                        return false;
                }
            return true;
        }
        
    }
    
    // 检查能否从场地顶端直接落到当前位置 仅用于判断能否继续游戏
    inline bool checkDirectDropTo(int color, int blockType, int x, int y, int o)
    {
        Tetris _block(blockType, currBotColor);
        if(!_block.set(x,y,o).isValid()) return false;
        
        auto &def = blockShape[blockType][o];
        for (; y <= MAPHEIGHT; y++)
            for (int i = 0; i < 4; i++)
            {
                int _x = def[i * 2] + x, _y = def[i * 2 + 1] + y;
                if (_y > MAPHEIGHT)
                    continue;
                if (_y < 1 || _x < 1 || _x > MAPWIDTH || gridInfo[color][_y][_x])
                    return false;
            }
        return true;
    }
    
    // 消去行
    void eliminate(int color)
    {
        int &count = transCount[color] = 0;
        int i, j, emptyFlag, fullFlag;
        maxHeight[color] = MAPHEIGHT;
        for (i = 1; i <= MAPHEIGHT; i++)
        {
            emptyFlag = 1;
            fullFlag = 1;
            for (j = 1; j <= MAPWIDTH; j++)
            {
                if (gridInfo[color][i][j] == 0)
                    fullFlag = 0;
                else
                    emptyFlag = 0;
            }
            if (fullFlag)
            {
                for (j = 1; j <= MAPWIDTH; j++)
                {
                    // 注意这里只转移以前的块，不包括最后一次落下的块（“撤销最后一步”）
                    trans[color][count][j] = gridInfo[color][i][j] == 1 ? 1 : 0;
                    gridInfo[color][i][j] = 0;
                }
                count++;
            }
            else if (emptyFlag)
            {
                maxHeight[color] = i - 1;
                break;
            }
            else
                for (j = 1; j <= MAPWIDTH; j++)
                {
                    gridInfo[color][i - count][j] =
                    gridInfo[color][i][j] > 0 ? 1 : gridInfo[color][i][j];
                    if (count)
                        gridInfo[color][i][j] = 0;
                }
        }
        maxHeight[color] -= count;
        elimTotal[color] += elimBonus[count];
    }
    
    //模拟消去行
    void transferImitate1(int color,int transferTmp[4][12],int count);
    int eliminateImitate(int color)
    {
        int count = 0;
        int transferTmp[4][12]={0};
        int i, j, emptyFlag, fullFlag;
        for (i = 1; i <= MAPHEIGHT; i++)
        {
            emptyFlag = 1;
            fullFlag = 1;
            for (j = 1; j <= MAPWIDTH; j++)
            {
                if (gridInfo[color][i][j] == 0)
                    fullFlag = 0;
                else
                    emptyFlag = 0;
            }
            if (fullFlag)
            {
                for (j = 1; j <= MAPWIDTH; j++){
                    transferTmp[count][j]=2;
                    gridInfo[color][i][j] = 0;
                }
                count++;
            }
            else
                for (j = 1; j <= MAPWIDTH; j++)
                {
                    gridInfo[color][i - count][j] =
                    gridInfo[color][i][j] > 0 ? 1 : gridInfo[color][i][j];
                    if (count)
                        gridInfo[color][i][j] = 0;
                }
        }
        
        transferImitate1(color,transferTmp,count);
        
        return count;
    }
    
    
    // 转移双方消去的行，返回-1表示继续，否则返回输者
    int transfer()
    {
        int color1 = 0, color2 = 1;
        if (transCount[color1] == 0 && transCount[color2] == 0)
            return -1;
        if (transCount[color1] == 0 || transCount[color2] == 0)
        {
            if (transCount[color1] == 0 && transCount[color2] > 0)
                swap(color1, color2);
            int h2;
            maxHeight[color2] = h2 = maxHeight[color2] + transCount[color1];
            if (h2 > MAPHEIGHT)
                return color2;
            int i, j;
            
            for (i = h2; i > transCount[color1]; i--)
                for (j = 1; j <= MAPWIDTH; j++)
                    gridInfo[color2][i][j] = gridInfo[color2][i - transCount[color1]][j];
            
            for (i = transCount[color1]; i > 0; i--)
                for (j = 1; j <= MAPWIDTH; j++)
                    gridInfo[color2][i][j] = trans[color1][i - 1][j];
            return -1;
        }
        else
        {
            int h1, h2;
            maxHeight[color1] = h1 = maxHeight[color1] + transCount[color2];//从color1处移动count1去color2
            maxHeight[color2] = h2 = maxHeight[color2] + transCount[color1];
            
            if (h1 > MAPHEIGHT) return color1;
            if (h2 > MAPHEIGHT) return color2;
            
            int i, j;
            for (i = h2; i > transCount[color1]; i--)
                for (j = 1; j <= MAPWIDTH; j++)
                    gridInfo[color2][i][j] = gridInfo[color2][i - transCount[color1]][j];
            
            for (i = transCount[color1]; i > 0; i--)
                for (j = 1; j <= MAPWIDTH; j++)
                    gridInfo[color2][i][j] = trans[color1][i - 1][j];
            
            for (i = h1; i > transCount[color2]; i--)
                for (j = 1; j <= MAPWIDTH; j++)
                    gridInfo[color1][i][j] = gridInfo[color1][i - transCount[color2]][j];
            
            for (i = transCount[color2]; i > 0; i--)
                for (j = 1; j <= MAPWIDTH; j++)
                    gridInfo[color1][i][j] = trans[color2][i - 1][j];
            
            return -1;
        }
    }
    
    //模拟转移消去行 算法1
    void transferImitate1(int color,int transferTmp[4][12],int count){
        int i,j;
        for (i = maxHeight[color]; i > count; i--)
            for (j = 1; j <= MAPWIDTH; j++)
                gridInfo[color][i][j] = gridInfo[color][i - count][j];
        
        for (i = count; i > 0; i--)
            for (j = 1; j <= MAPWIDTH; j++)
                gridInfo[color][i][j] = transferTmp[i - 1][j];
    }
    
    // 颜色方还能否继续游戏
    inline bool canPut(int color, int blockType)
    {
        Tetris t(blockType, color);
        for (int y = MAPHEIGHT; y >= 1; y--)
            for (int x = 1; x <= MAPWIDTH; x++)
                for (int o = 0; o < 4; o++)
                {
                    t.set(x, y, o);
                    if (t.isValid() && checkDirectDropTo(color, blockType, x, y, o))
                        return true;
                }
        return false;
    }
    
    // 打印场地用于调试
    inline void printField()
    {
#ifndef _BOTZONE_ONLINE
        static const char *i2s[] = {
            "~~",
            "~~",
            "  ",
            "[]",
            "##"
        };
        cout << "~~：墙，[]：块，##：新块" << endl;
        for (int y = MAPHEIGHT + 1; y >= 0; y--)
        {
            for (int x = 0; x <= MAPWIDTH + 1; x++)
                cout << i2s[gridInfo[0][y][x] + 2];
            for (int x = 0; x <= MAPWIDTH + 1; x++)
                cout << i2s[gridInfo[1][y][x] + 2];
            cout << endl;
        }
#endif
    }
}


int main()
{
    // 加速输入
    istream::sync_with_stdio(false);
    srand(time(NULL));
    init();
    
    int turnID, blockType;
    int nextTypeForColor[2];
    cin >> turnID;
    
    // 先读入第一回合，得到自己的颜色
    // 双方的第一块肯定是一样的
    cin >> blockType >> currBotColor;
    enemyColor = 1 - currBotColor;
    nextTypeForColor[0] = blockType;
    nextTypeForColor[1] = blockType;
    typeCountForColor[0][blockType]++;
    typeCountForColor[1][blockType]++;
    
    // 然后分析以前每回合的输入输出，并恢复状态
    // 循环中，color 表示当前这一行是 color 的行为
    // 平台保证所有输入都是合法输入
    for (int i = 1; i < turnID; i++)
    {
        int currTypeForColor[2] = { nextTypeForColor[0], nextTypeForColor[1] };
        int x, y, o;
        // 根据这些输入输出逐渐恢复状态到当前回合
        
        // 先读自己的输出，也就是自己的行为
        // 自己的输出是自己的最后一步
        // 然后模拟最后一步放置块
        cin >> blockType >> x >> y >> o;
        
        // 我当时把上一块落到了 x y o！
        Tetris myBlock(currTypeForColor[currBotColor], currBotColor);
        myBlock.set(x, y, o).place();
        
        // 我给对方什么块来着？
        typeCountForColor[enemyColor][blockType]++;
        nextTypeForColor[enemyColor] = blockType;
        
        // 然后读自己的输入，也就是对方的行为
        // 裁判给自己的输入是对方的最后一步
        cin >> blockType >> x >> y >> o;
        
        // 对方当时把上一块落到了 x y o！
        Tetris enemyBlock(currTypeForColor[enemyColor], enemyColor);
        enemyBlock.set(x, y, o).place();
        
        // 对方给我什么块来着？
        typeCountForColor[currBotColor][blockType]++;
        nextTypeForColor[currBotColor] = blockType;
        
        // 检查消去
        Util::eliminate(0);
        Util::eliminate(1);
        
        // 进行转移
        Util::transfer();
    }
    
    
    int blockForEnemy, finalX=-1, finalY=-1, finalO=0;
    
    // 做出决策（你只需修改以下部分）
    
    // 遇事不决先输出（平台上编译不会输出）
    Util::printField();
    
    // 贪心决策
    // 由左至右以4种姿态遍历10-个位置 得到最小评估函数对应的坐标和姿态
    // 可优化 同一方块重复姿态
    
    double maxScore=MINSCORE;
    for (int x = 1; x <= MAPWIDTH; x++)
        for (int o = 0; o < 4; o++)
            for (int y = 1; y <= MAPHEIGHT; y++)
            {
                bool checkRoot=0;
                Tetris block(nextTypeForColor[currBotColor], currBotColor);
                if(block.set(x,y,o).onGround()){
                    //直落或向右平移后直落
                    for(int hx=x ; hx<=MAPWIDTH ; hx++){
                        if ( Util::checkDirectMoveTo(currBotColor, block.blockType, x, y, o, hx) && Util::checkDirectDropTo(currBotColor, block.blockType, hx, y, o)){
                            checkRoot=1;
                            break;
                        }
                    }
                    //向左平移后直落
                    if(!checkRoot){
                        for(int hx=x-1 ; hx>=1 ; hx--){
                            if (Util::checkDirectMoveTo(currBotColor, block.blockType, x, y, o, hx) && Util::checkDirectDropTo(currBotColor, block.blockType, hx, y, o)){
                                checkRoot=1;
                                break;
                            }
                        }
                    }
                    //直落后旋转
                    if(!checkRoot){
                        for(int _o=o+1,num=0;num<3;_o++,num++){
                            if(!block.rotation(_o%4)) break;
                            if( Util::checkDirectDropTo(currBotColor,block.blockType,x,y,_o%4) ){
                                checkRoot=1;
                                break;
                            }
                        }
                    }
                }
                if (checkRoot)
                {
                    //备份gridInfo
                    int gridInfoBackup[MAPHEIGHT+2][MAPWIDTH+2];
                    //for(int by=0;by<=MAPHEIGHT+1;y++) for(int bx=0;bx<=MAPWIDTH+1;bx++) gridInfoBackup[by][bx]=gridInfo[currBotColor][by][bx];
                    memcpy(gridInfoBackup,gridInfo[currBotColor],sizeof(gridInfo[currBotColor]));
                    
                    //Landing Height
                    // 7种形状( L| J | S | Z | T | — | 田 ) 4种朝向(上左下右)
                    double lh=0;
                    if(block.blockType==6){
                        if(o==0||o==3) lh=y;
                        else lh=y-1;
                    }
                    else if(block.blockType==4||block.blockType==5){
                        if(o==0) lh=y;
                        else if(o==2) lh=y-1;
                        else lh=y-0.5;
                    }
                    else{
                        if(o==0) lh=y-1;
                        else if(o==2) lh=y;
                        else lh=y-0.5;
                    }
                    
                    //执行放置和消除
                    if(!block.place()) continue;
                    //Rows Eliminated
                    int re=Util::eliminateImitate(currBotColor);
                    //针对 消除后若下方不存在对方JR则模拟考虑己方消除行放置 再进行评估
                    //两种算法 一是按当前消除行同步转移 二是按所有可能的行随机概率进行转移
                    //转移在eliinateImitate结束后跳转进行
                    
                    
                    //Rows Transitions
                    int rt=0;
                    for(int curY=1;curY<=MAPHEIGHT;++curY){
                        for(int curX=0;curX<=MAPWIDTH;++curX){
                            if(((gridInfo[currBotColor][curY][curX]!=0)&&(gridInfo[currBotColor][curY][curX+1]==0))||((gridInfo[currBotColor][curY][curX]==0)&&(gridInfo[currBotColor][curY][curX+1]!=0))) ++rt;
                        }
                    }
                    
                    //Column Transitions
                    //对最顶行作出调整
                    int ct=0;
                    for(int curX=1;curX<=MAPWIDTH;++curX){
                        for(int curY=0;curY<=MAPHEIGHT-1;++curY){
                            if(((gridInfo[currBotColor][curY][curX]!=0)&&(gridInfo[currBotColor][curY+1][curX]==0))||((gridInfo[currBotColor][curY][curX]==0)&&(gridInfo[currBotColor][curY+1][curX]!=0))) ++ct;
                        }
                        if(gridInfo[currBotColor][MAPHEIGHT][curX]!=0) ++ct;
                    }
                    
                    //Number of Holes
                    int nh=0;
                    for(int curX=1;curX<=MAPWIDTH;++curX){
                        bool b=0;
                        for(int curY=MAPHEIGHT;curY>=1;--curY){
                            if(b==0&&gridInfo[currBotColor][curY][curX]!=0) b=1;
                            if(b&&(gridInfo[currBotColor][curY][curX]==0)) ++nh;
                        }
                    }
                    
                    //Well Sums
                    int ws=0;
                    for(int curX=1;curX<=MAPWIDTH;++curX){
                        for(int curY=1;curY<=MAPHEIGHT;++curY){
                            if((gridInfo[currBotColor][curY][curX]==0)&&(gridInfo[currBotColor][curY][curX+1])&&(gridInfo[currBotColor][curY][curX-1])&&curY<=MAPHEIGHT) ++ws;
                        }
                    }
                    
                    //根据不同情况执行不同评估函数
                    double curScore=countPDScore(lh,re,rt,ct,nh,ws);
                    
                    //还原gridInfo
                    //for(int by=0;by<=MAPHEIGHT+1;y++) for(int bx=0;bx<=MAPWIDTH+1;bx++) gridInfoBackup[by][bx]=gridInfo[currBotColor][by][bx];
                    memcpy(gridInfo[currBotColor],gridInfoBackup,sizeof(gridInfoBackup));
                    
                    if(curScore>maxScore){
                        maxScore = curScore;
                        finalX = x;
                        finalY = y;
                        finalO = o;
                    }
                }
            }
    
    // 再看看给对方什么好
    
    int maxCount = 0, minCount = 1000000;
    for (int i = 0; i < 7; i++)
    {
        if (typeCountForColor[enemyColor][i] > maxCount)
            maxCount = typeCountForColor[enemyColor][i];
        if (typeCountForColor[enemyColor][i] < minCount)
            minCount = typeCountForColor[enemyColor][i];
    }
    if (maxCount - minCount == 2)
    {
        // 危险，找一个不是最大的块给对方吧
        deque<int> blockSafe;
        for (blockForEnemy = 0; blockForEnemy < 7; blockForEnemy++)
            if (typeCountForColor[enemyColor][blockForEnemy] != maxCount)
                blockSafe.push_back(blockForEnemy);
        if(find(blockSafe.begin(),blockSafe.end(),2)!=blockSafe.end()) blockForEnemy=2;
        else if(find(blockSafe.begin(),blockSafe.end(),3)!=blockSafe.end()) blockForEnemy=3;
        else{
            random_shuffle(blockSafe.begin(),blockSafe.end());
            blockForEnemy = * blockSafe.begin();
        }
    }
    else
    {
        random_device rd;
        blockForEnemy = rd() % 7;
    }
    
    // 决策结束，输出结果（你只需修改以上部分）
    
    cout << blockForEnemy << " " << finalX << " " << finalY << " " << finalO;
    
    return 0;
}
