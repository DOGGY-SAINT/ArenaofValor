#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <string>
#include <boost/asio.hpp>
#include<cocos2d.h>
using boost::asio::ip::tcp;

class Equipment;

class Command
{
public:
	Command(size_t numRows = 12);
	Command(std::string str, size_t numRos = 12);
	std::string CreateStrings();
	//
	size_t category;
	size_t player;
	//
	//std::string heroName;
	//���ж�Ӧ��ս�����̵Ĳ�����Ϣ
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
	std::string heroName;
	//���ڴ�����ַ�������
	size_t numRows;
	std::vector <std::string> package;
private:
	//��package���ַ���ת��������
	void createCommand();

};

#endif // !_MESSAGE_H_
