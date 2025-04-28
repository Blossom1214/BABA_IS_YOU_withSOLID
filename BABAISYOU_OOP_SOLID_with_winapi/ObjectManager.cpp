#include "ObjectManager.h"
#include "Tile.h"
#include "TileObjectBase.h"
void ObjectManager::AddObjectAndText()
{
	_ObjectTile->AddObject(_Object);
	
	//텍스트와 텍스트 오브젝트와 오브젝트의 경우에는 스택처럼 쌓는구조라고하고
	//텍스트와 오브젝트 이렇게 있으면 항상 back에는 오브젝트가 우선순위로 올수있게 만들어야함
	//우선순위큐?라고 보기도애매함... 그건아님...
	
}


