/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#ifndef MOD_CHARACTER_H
#define MOD_CHARACTER_H

#include <game/server/alloc.h>
#include <generated/protocol.h>
#include "../defines.h"

#ifdef MOD

class CGameContext;
class IGameController;
class IServer;
class CCharacter;
class CModPlayer;


class CModCharacter
{
	MACRO_ALLOC_POOL_ID()

public:
	CModCharacter();
	~CModCharacter();
	void Tick();
	int GetCID();

	CGameContext *GameServer();
	IGameController *GameController();
	IServer *Server();

	// Hooks
	void OnSpawn(CModPlayer *pPlayer);
	void OnDeath();
	void OnSnap(int SnappingClient, CNetObj_Character *pCharacter);

private:
	// Player controlling this character within the mod controller
	CModPlayer *m_pPlayer;

	// Character in the teeworlds game source
	CCharacter *m_pGameChr;
};

#endif
#endif
