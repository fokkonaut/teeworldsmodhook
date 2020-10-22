/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#include "modcontroller.h"

#include <game/server/gamecontext.h>
#include <game/server/entities/character.h>
#include <game/server/player.h>


CModController *g_pMod;

CModController::CModController(CGameContext *pGameServer)
{
	m_pGameServer = pGameServer;
	m_pServer = pGameServer->Server();

	for (int i = 0; i < MAX_CLIENTS; i++)
		m_apPlayers[i] = 0;
}

CModController::~CModController()
{
	// Nothing to clean...
}

class CModPlayer *CModController::Player(CPlayer *pPlayer)
{
	return m_apPlayers[pPlayer->GetCID()];
}

class CModCharacter *CModController::Character(int ClientID)
{
	if (ClientID < 0 || ClientID >= MAX_CLIENTS || !m_apPlayers[ClientID])
		return 0;
	return m_apPlayers[ClientID]->GetCharacter();
}

class CModCharacter *CModController::Character(CCharacter *pCharacter)
{
	return m_apPlayers[pCharacter->GetPlayer()->GetCID()]->GetCharacter();
}

void CModController::Tick()
{

}

void CModController::OnClientEnter(int ClientID)
{
	m_apPlayers[ClientID] = new(ClientID) CModPlayer(ClientID, GameServer());
}

void CModController::OnClientDrop(int ClientID)
{
	delete m_apPlayers[ClientID];
	m_apPlayers[ClientID] = 0;
}
