/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#ifndef MOD_PLAYER_H
#define MOD_PLAYER_H

#include <game/server/alloc.h>
#include <generated/protocol.h>

class CGameContext;
class CModCharacter;


class CModPlayer
{
	MACRO_ALLOC_POOL_ID()

public:
	CModPlayer(int ClientID, CGameContext *pGameServer);
	void Tick();
	int GetCID() { return m_ClientID; }

	CGameContext *GameServer() { return m_pGameServer; }
	CModCharacter *GetCharacter() { return m_pCharacter; }
	void DeleteCharacter();

	// Hooks
	void OnSpawn();
	void OnDeath();
	void OnSnap(CNetObj_PlayerInfo *pPlayerInfo);
	void OnSnap(CNetObj_SpectatorInfo *pSpectatorInfo);

private:
	CGameContext *m_pGameServer;
	CModCharacter *m_pCharacter;
	int m_ClientID;
};

#endif
