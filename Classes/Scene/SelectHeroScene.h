#pragma once

#ifndef __SELECTHERO_SCENE_H__
#define __SELECTHERO_SCENE_H__

#include <iostream>
#include <stack>
#include <string>
#include "cocos2d.h"
#include "ui/CocosGUI.h"


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
	std::stack<std::string> selectedHero;//ѡ���Ӣ��

};

#endif