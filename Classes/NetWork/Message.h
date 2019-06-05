#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <string>
#include <boost/asio.hpp>
#include<cocos2d.h>
using boost::asio::ip::tcp;

class Equipment;

class Message
{
public:
	Message(boost::asio::ip::tcp::iostream& io, size_t numRows = 8);
	Message(size_t numRows = 8);
	~Message();
	void CreateStrings();
	//���ж�Ӧ�Ĳ�����Ϣ
	float standingAngle;
	bool isHeroMove;
	bool isHeroStopMove;
	bool isSkillLevelUp;
	size_t skillLevelUp;
	bool isGetEquip;
	Equipment* getEquip;
	bool isSellEquip;
	Equipment* sellEquip;
	bool isCastSkill;
	size_t castSkill;
	bool isSkillParamter;
	cocos2d::Point skillParamter;
	bool isAttack;
	//���ڴ�����ַ�������
	size_t numRows;
	std::vector <std::string> package;
private:
	//��package���ַ���ת��������
	void createCommand();

};

#endif // !_MESSAGE_H_

