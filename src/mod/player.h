/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#ifndef MOD_PLAYER_H
#define MOD_PLAYER_H

#include <game/server/alloc.h>
#include <generated/protocol.h>

class CGameContext;
class IGameController;
class IServer;
class CModCharacter;


class CModPlayer
{
	MACRO_ALLOC_POOL_ID()

public:
	CModPlayer(int ClientID);
	~CModPlayer();
	void Tick();
	int GetCID() { return m_ClientID; }

	CGameContext *GameServer();
	IGameController *GameController();
	IServer *Server();

	CModCharacter *GetCharacter() { return m_pCharacter; }
	void DeleteCharacter();

	// Hooks
	void OnSpawn();
	void OnDeath();
	void OnSnap(int SnappingClient, CNetObj_PlayerInfo *pPlayerInfo);
	void OnSnap(int SnappingClient, CNetObj_SpectatorInfo *pSpectatorInfo);

private:
	CModCharacter *m_pCharacter;
	int m_ClientID;
};

#endif
