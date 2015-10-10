#include "SetScene.h"

bool SetScene::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!Scene::init());

		rootNode = CSLoader::createNode("SetScene.csb");
		addChild(rootNode);

		auto f = UserDefault::getInstance();

		int sa = f->getIntegerForKey(SELF_ATK_DATA, 0);
		int sd = f->getIntegerForKey(SELF_DEF_DATA, 0);
		int sh = f->getIntegerForKey(SELF_HEALTH_DATA, 1);

		int ea = f->getIntegerForKey(ENEMY_ATK_DATA, 0);
		int ed = f->getIntegerForKey(ENEMY_DEF_DATA, 0);
		int eh = f->getIntegerForKey(ENEMY_HEALTH_DATA, 1);

		int rs = f->getIntegerForKey(RANDOM_SEED, 0);
		int dps = f->getIntegerForKey(DAMAGE_PER_SECOND, 0);


		TextField* sat = (TextField*)(rootNode->getChildByName("self_atk"));
		sat->setString(stdItoS(sa));

		TextField* sdt = (TextField*)(rootNode->getChildByName("self_def"));
		sdt->setString(stdItoS(sd));

		TextField* sht = (TextField*)(rootNode->getChildByName("self_health"));
		sht->setString(stdItoS(sh));

		TextField* eat = (TextField*)(rootNode->getChildByName("enemy_atk"));
		eat->setString(stdItoS(ea));

		TextField* edt = (TextField*)(rootNode->getChildByName("enemy_def"));
		edt->setString(stdItoS(ed));

		TextField* eht = (TextField*)(rootNode->getChildByName("enemy_health"));
		eht->setString(stdItoS(eh));

		TextField* dpst = (TextField*)(rootNode->getChildByName("dps"));
		dpst->setString(stdItoS(dps));

		TextField* rst = (TextField*)(rootNode->getChildByName("random_seed"));
		rst->setString(stdItoS(rs));



		Button* ok = (Button*)(rootNode->getChildByName("OK"));
		ok->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				TextField* sat = (TextField*)(rootNode->getChildByName("self_atk"));
				TextField* sdt = (TextField*)(rootNode->getChildByName("self_def"));
				TextField* sht = (TextField*)(rootNode->getChildByName("self_health"));
				TextField* eat = (TextField*)(rootNode->getChildByName("enemy_atk"));
				TextField* edt = (TextField*)(rootNode->getChildByName("enemy_def"));
				TextField* eht = (TextField*)(rootNode->getChildByName("enemy_health"));
				TextField* dpst = (TextField*)(rootNode->getChildByName("dps"));
				TextField* rst = (TextField*)(rootNode->getChildByName("random_seed"));

				string a = sat->getString();
				int sa = stdStoI(sat->getString());
				if (sa == ERROR_STRING) return;
				int sd = stdStoI(sdt->getString());
				if (sd == ERROR_STRING) return;
				int sh = stdStoI(sht->getString());
				if (sh == ERROR_STRING) return;

				int ea = stdStoI(eat->getString());
				if (ea == ERROR_STRING) return;
				int ed = stdStoI(edt->getString());
				if (ed == ERROR_STRING) return;
				int eh = stdStoI(eht->getString());
				if (eh == ERROR_STRING) return;

				int rs = stdStoI(rst->getString());
				if (rs == ERROR_STRING) return;
				int dps = stdStoI(dpst->getString());
				if (dps == ERROR_STRING) return;

				auto f = UserDefault::getInstance();

				f->setIntegerForKey(SELF_ATK_DATA, sa);
				f->setIntegerForKey(SELF_DEF_DATA, sd);
				f->setIntegerForKey(SELF_HEALTH_DATA, sh);

				f->setIntegerForKey(ENEMY_ATK_DATA, ea);
				f->setIntegerForKey(ENEMY_DEF_DATA, ed);
				f->setIntegerForKey(ENEMY_HEALTH_DATA, eh);

				f->setIntegerForKey(RANDOM_SEED, rs);
				f->setIntegerForKey(DAMAGE_PER_SECOND, dps);

				f->flush();

				Director::getInstance()->popScene();
			}
		});

		Button* cancel = (Button*)(rootNode->getChildByName("Cancel"));
		cancel->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
		{
			if (type == Widget::TouchEventType::ENDED)
			{
				Director::getInstance()->popScene();
			}
		});

		bRet = true;
	} while (0);
	return bRet;
}