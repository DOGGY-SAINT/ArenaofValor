#pragma once
#ifndef __SELECTMODE_SCENE_H__
#define __SELECTMODE_SCENE_H__

#include "cocos2d.h"
class chat_client;

class SelectMode :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	//netWork
	void update(float delta);
	bool clientInit();
	chat_client* _client;
	//
	int sameTime;
	int numPlayer;
	int _playerNumber;
	bool _doSearching;
	bool _isGetNum;
	bool _isReady;
	//
	//���ؼ���1V1��
	void menuBackCallBack(cocos2d::Ref *pSender);
	void menuSingleCallBack(cocos2d::Ref *pSender);
	void menuNetworkCallBack(cocos2d::Ref *pSender);
	void menuComingCallBack(cocos2d::Ref * pSender);
	// a selector callback
	//void menuCloseCallback(cocos2d::Ref* pSender);


	CREATE_FUNC(SelectMode);
};

#endif