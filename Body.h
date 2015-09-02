
#ifndef BODY_H_
#define BODY_H_
#include <string>
struct bodynode
{
	int x;
	int y;
	bodynode *next;
	std::string z;//'■'
};
class body
{
private:
	int level;//游戏速度
	int count;//蛇身长度
	int score;//分数
	int x,y;//食物位置
	bodynode *head;
	char dir;//方向
public:
	body();
	void position(int x,int y);//定位光标位置
	void AllView();
	void bodyview();
	void taildel();
	void move();
	void dmove(char dirr);
	void Game();
	bool over();
	void food();
	void beginview();
	~body();
};
#endif
