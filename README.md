# PokemonGame
A Qt C++ based tower defense game

Changelog:
1.1:改变怪物移动方式，改变为平行的移动更符合实际观感。
基本功能：
1.	地图：怪物伴随着背景音乐沿着规定路线前进
2.	生命：怪兽走到尽头还未被击杀生命会-1。
3.	积分：初始100积分，用于购买炮塔；打死怪兽会获得积分奖励。
4.	怪兽：沿着既定路线从起点到终点；目前实现1种。
5.	炮塔：用鼠标点击右上角炮塔图片以购买，然后用鼠标移动控制其位置来安放到自定义的位置。目前实现一种炮塔。
6.	攻击机制：进入攻击范围后炮塔会自动发射攻击，沿某一路径前进
7.	击杀机制：设定有一定概率击杀怪物，而非血量的设置。。
8.	购买机制：使用分值购买，购买扣除一定数额，通过击杀获得奖励。
