#include "StartGameScene.h"
#include "SelectModeScene.h"

USING_NS_CC;

Scene* StartGame::createScene()
{
	return StartGame::create();
}

//Promble loading
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartGameScene.cpp\n");
}

bool StartGame::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();//�õ���Ļ��С
	Vec2 origin = Director::getInstance()->getVisibleOrigin();//��ÿ�������ĳ��������꣬�ڴ������λ��ʱ��ȷ���ڵ��ڲ�ͬ�ֱ����µ�λ��һ�¡�

	//Start Bottom
	MenuItemImage *startMenu = MenuItemImage::create(
		"StartGame/Start.png",
		"StartGame/Start1.png",
		CC_CALLBACK_1(StartGame::menuStartCallBack, this)
	);

	if (startMenu == nullptr ||
		startMenu->getContentSize().width <= 0 ||
		startMenu->getContentSize().height <= 0)
	{
		problemLoading("'startMenu.png'");
	}
	else
	{
		float x = visibleSize.width / 2;
		float y = visibleSize.height - 561.5;
		startMenu->setPosition(Vec2(x, y));
	}

	Menu *mu = Menu::create(startMenu, NULL);
	mu->setPosition(Vec2::ZERO);
	this->addChild(mu, 1);

	//background
	auto background = Sprite::create("StartGame/background.png");
	if (background == nullptr)
	{
		problemLoading("'background.png'");
	}
	else
	{
		background->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		this->addChild(background, 0);
	}

	return true;
}

void StartGame::menuStartCallBack(cocos2d::Ref * pSender)
{
	auto nextScene = SelectMode::create();
	Director::getInstance()->replaceScene(
		TransitionSlideInT::create(1.0f / 60, nextScene));
	MenuItem *item = (MenuItem*)pSender;
	log("Touch Helo Menu Item %p", item);
}

