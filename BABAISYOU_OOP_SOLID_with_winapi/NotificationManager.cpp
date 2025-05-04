#include "NotificationManager.h"
#include "RuleManager.h"
void NotificationManager::RegisterDirtyPosition(const Position& pos)
{
	_dirtyPositions.insert(pos);

}

void NotificationManager::ProcessDirtyFlags(RuleManager& manager)
{
	for (const auto& pos : _dirtyPositions)
	{
		manager.UpdateRulesAt(pos);
	}
	RegisterClear();
}

bool NotificationManager::IsEmpty() const
{
	if (_dirtyPositions.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void NotificationManager::RegisterClear()
{
	_dirtyPositions.clear();
}
