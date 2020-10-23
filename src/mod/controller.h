/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#ifndef MOD_CONTROLLER_H
#define MOD_CONTROLLER_H

#include "player.h"
#include "entities/character.h"
#include "defines.h"

#include <engine/shared/protocol.h>

class CGameContext;
class IServer;
class CPlayer;
class CCharacter;


class CModController
{
public:
	CModController(CGameContext *pGameServer);
	~CModController();
	void Tick();

	class CModPlayer *Player(int ClientID) { return m_apPlayers[ClientID]; }
	class CModPlayer *Player(CPlayer *pPlayer);
	class CModCharacter *Character(int ClientID);
	class CModCharacter *Character(CCharacter *pCharacter);

	CGameContext *GameServer() { return m_pGameServer; }
	IServer *Server() { return m_pServer; }

	// Hooks
	void OnClientEnter(int ClientID);
	void OnClientDrop(int ClientID);

private:
	class CGameContext *m_pGameServer;
	class IServer *m_pServer;

	class CModPlayer *m_apPlayers[MAX_CLIENTS];
};

extern CModController *g_pMod;

#endif
