#pragma once

#ifndef __SELECTENEMYHERO_SCENE_H__
#define __SELECTENEMYHERO_SCENE_H__

#include <iostream>
#include "cocos2d.h"

class SelectEnemyHero :public cocos2d::Scene
{
public:


	static cocos2d::Scene* createScene();

	virtual bool init();


	//�������Ӣ�����ڷֿ���menuд������������ĵ�ѡ�� ���ӵ����ĸ���ѡ�����ȷ��ʱ�Ķ���



	void menuHouyiCallBack(cocos2d::Ref *pSender);
	void menuDajiCallBack(cocos2d::Ref *pSender);
	void menuYaseCallBack(cocos2d::Ref *pSender);

	void menuBackCallBack(cocos2d::Ref *pSender);

	CREATE_FUNC(SelectEnemyHero);

private:
	std::string _heroName;

};

#endif