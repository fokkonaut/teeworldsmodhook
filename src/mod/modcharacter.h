/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#ifndef MOD_CHARACTER_H
#define MOD_CHARACTER_H

#include <game/server/alloc.h>
#include <generated/protocol.h>

class CGameContext;
class CModPlayer;


class CModCharacter
{
	MACRO_ALLOC_POOL_ID()

public:
	CModCharacter(CGameContext *pGameServer);
	void Tick();

	CGameContext *GameServer() { return m_pGameServer; }

	// Hooks
	void OnSpawn(CModPlayer *pPlayer);
	void OnDeath();
	void OnSnap(CNetObj_Character *pCharacter);

private:
	CGameContext *m_pGameServer;
	CModPlayer *m_pPlayer;
};

#endif
