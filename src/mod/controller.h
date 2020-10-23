/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#ifndef MOD_CONTROLLER_H
#define MOD_CONTROLLER_H

#include "player.h"
#include "entities/character.h"
#include "defines.h"

#include <engine/shared/protocol.h>
#include <base/vmath.h>

#ifdef MOD

class CGameContext;
class IGameController;
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

	void InitPlayer(int ClientID);
	void DeletePlayer(int ClientID);

	CGameContext *GameServer() { return m_pGameServer; }
	IGameController *GameController();
	IServer *Server();

	// Network
	void SendChatTarget(int To, const char *pText);
	void SendMotd(int To, const char *pText);

	void CreateSoundGlobal(int Sound);
	void CreateSoundPlayer(int Sound, int ClientID);
	void CreateSoundPlayerAt(vec2 Pos, int Sound, int ClientID);

	// Getters
	int GetCIDByName(const char *pName);

	// Hooks
	void OnClientEnter(int ClientID);
	void OnClientDrop(int ClientID);

private:
	// Normal game objects so we can access them from the mod controller
	class CGameContext *m_pGameServer;
	class IGameController *m_pGameController;
	class IServer *m_pServer;

	// Players within the mod controller, not the normal player array!
	class CModPlayer *m_apPlayers[MAX_CLIENTS];
};

extern CModController *g_pMod;

#endif
#endif
