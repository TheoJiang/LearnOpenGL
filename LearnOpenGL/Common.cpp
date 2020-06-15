#include "Common.h"

Common::Common()
{
	instance = nullptr;
}


Common::~Common()
{
	delete instance;
	instance = nullptr;
}

void Common::SetKey(int key)
{
	instance->GetInstance()->trigeredKey = key;
}

int Common::GetKey()
{
	return instance->GetInstance()->trigeredKey;
}

Common* Common::instance;
Common * Common::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new Common();
	}
	return instance;
}