#ifndef PLAYER_H
#define PLAYER_H



#include "Entity.h"

class CPlayer : public CEntity
{
public:
	CPlayer();
	virtual ~CPlayer();
	
private:

	void InitVariable();
	void InitComponent();
public:

};


#endif // !PLAYER_H