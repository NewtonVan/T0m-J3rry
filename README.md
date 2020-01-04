# T0m-J3rry
Funny Gam3

# 添加功能如下
***

* 一只能咬我的狗（T&J里好像叫鲁宾还是啥子的）
* R键rush技能，世界上速度最快的程序员猫（速度1024）
* 可以化身射手Tom，发射小猫球
* 小萝莉猫，纯受，躲不了，色Tom逮着就是一顿...魔法加成，速度更快了or射手资源更足了or再获得一条命（别问为什么开始没有九条命）
* 御姐猫，具有欲擒故纵被动技能，其他和萝莉猫相比，体验（加成）double
* 设定了游戏记录设定，History文件夹下，record.txt记录了每局时间以及分数，rank.txt记录历史前十分数与时间~~，不过有个毛病，时间目前还是UNIX时间戳。。。算法太复杂了。。~~
* 优化了游戏UI，增加了游戏历史最高，以及生命等数据显示
* 设计了暗门，版权所有，白嫖大实验必凉兄die，你是看不到的，但是老师是能看到的哈哈哈哈哈哈哈哈哈

# 类
***

原有：
* T0m
* J3rry
* Canary(AvoidSprite)
添加
* Robin(EnemySprite)
* Girl(PrizeSprite)
* ButiGirl(PrizeSprite1)
* Weapon Cat(Ball)
* History(HistoryBase)

# Ea5t3rEgg（彩蛋）
***
加速状态，有概率获得双倍奖励，当然也有概率三倍伤害。。。

# 编译文件方法
***

在命令行下打开，且配置好Mingw
```shell
gcc -c *.c 
g++ -c *.cpp 
g++ *.o -lgdi32 -lole32 -loleaut32 -luuid -lwinmm -lmsimg32 -o sprite.exe
```
