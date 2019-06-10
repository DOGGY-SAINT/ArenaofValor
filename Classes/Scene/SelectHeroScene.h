#pragma once


#include <iostream>
#include "cocos2d.h"
#include "ui/CocosGUI.h"

#ifndef __SELECTHERO_SCENE_H__
#define __SELECTHERO_SCENE_H__

class SelectHero :public cocos2d::Scene
{
public:


	static cocos2d::Scene* createScene();

	virtual bool init();


	//�������Ӣ�����ڷֿ���menuд������������ĵ�ѡ�� ���ӵ����ĸ���ѡ�����ȷ��ʱ�Ķ���



	void menuHouyiCallBack(cocos2d::Ref *pSender);
	void menuDajiCallBack(cocos2d::Ref *pSender);
	void menuYaseCallBack(cocos2d::Ref *pSender);

	void menuBackCallBack(cocos2d::Ref *pSender);

	CREATE_FUNC(SelectHero);

private:
	std::string _heroName;

};

#endif