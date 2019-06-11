#include "mapScene.h"

USING_NS_CC;

Scene* MapScene::createScene()
{
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = MapScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

bool MapScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	map = TMXTiledMap::create("map/2.tmx");
	map->setAnchorPoint(ccp(0.5, 0.5));
	map->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	//map->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	addChild(map);

	// ��ȡ objLayer �����
	TMXObjectGroup *objGroup = map->objectGroupNamed("hero");
	// ��ȡ hero ����
	auto vm = objGroup->objectNamed("haha");
	float x = vm.at("x").asFloat();
	float y = vm.at("y").asFloat();

	String name = vm.at("name").asString();
	log(" name %s ", name);



	// �� hero ��λ�ô���Ӿ���
	sprite = Sprite::create("map/houyi.png");
	sprite->setPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);
	// ��Ϊ��ͼ��ê�������½ǣ��������þ����ê��ҲΪ���½ǣ�����λ�ò��ܶ�Ӧ��
	sprite->setAnchorPoint(Vec2::ZERO);
	addChild(sprite);

	setTouchEnabled(true);
	setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	return true;
}

//����������ת��Ϊ��ͼ����
CCPoint MapScene::positionToTileCoord(cocos2d::CCPoint cocosCoord)
{
	int x = cocosCoord.x / map->getTileSize().width;
	int y = (((map->getMapSize().height - 1)*map->getTileSize().height) - cocosCoord.y) / map->getTileSize().height;
	return ccp(x, y);
}

MapScene::CollisionType MapScene::checkCollision(CCPoint heroPotion)
{
	cocos2d::CCPoint tileCoord = positionToTileCoord(heroPotion);

	//����Ƿ񳬳���ͼ�߽�
	if (tileCoord.x<0 || tileCoord.x>map->getMapSize().width - 1 ||
		tileCoord.y<0 || tileCoord.y>map->getMapSize().height - 1)
		return Wall;

	//�ж�Ŀ�������Ƿ�Ϊǽ��
	int tileGid = map->layerNamed("wall")->tileGIDAt(tileCoord);
	if (tileGid) {
		return Wall;
	}
	return Moveble;
}



bool MapScene::onTouchBegan(cocos2d::Touch * touch, cocos2d::Event * event)
{
	Vec2 pos = touch->getLocation();

	Vec2 spritePos = sprite->getPosition();
	Vec2 diff = pos - spritePos;//������;���λ��֮��

	if (abs(diff.x) > abs(diff.y)) {
		if (diff.x > 0)//�����ұ�
		{
			spritePos.x += map->getTileSize().width;
			sprite->runAction(FlipX::create(false));
		}
		else
		{
			spritePos.x -= map->getTileSize().width;
			sprite->runAction(FlipX::create(true));
		}
	}
	else
	{
		if (diff.y > 0)
		{
			spritePos.y += map->getTileSize().height;
			sprite->runAction(FlipY::create(false));
		}
		else
		{
			spritePos.y -= map->getTileSize().height;
			sprite->runAction(FlipY::create(true));
		}
	}
	sprite->setPosition(spritePos);

	cocos2d::CCPoint targetPosition = ccpAdd(sprite->getPosition(), spritePos);
	if (checkCollision(targetPosition) == 1)
	{
		return 0;
	}

	//ActionInstant *func = CallFunc::create(this, callfunc_selector(MapScene::judgeCollide));
	//sprite->runAction(Sequence::create(MoveTo::create(1, pos), func, nullptr));
	return true;
}
