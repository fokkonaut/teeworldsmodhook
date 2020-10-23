/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#include "player.h"
#include "controller.h"
#include <game/server/gamecontext.h>
#include <game/server/player.h>
#include <game/server/entities/character.h>

#ifdef MOD

MACRO_ALLOC_POOL_ID_IMPL(CModPlayer, MAX_CLIENTS)

CGameContext *CModPlayer::GameServer() { return MOD->GameServer(); }
IGameController *CModPlayer::GameController() { return MOD->GameController(); }
IServer *CModPlayer::Server() { return MOD->Server(); }


CModPlayer::CModPlayer(int ClientID)
{
	m_ClientID = ClientID;
	m_pCharacter = 0;
}

CModPlayer::~CModPlayer()
{
	DeleteCharacter();
}

void CModPlayer::DeleteCharacter()
{
	delete m_pCharacter;
	m_pCharacter = 0;
}

void CModPlayer::Tick()
{

}

void CModPlayer::OnSpawn()
{
	m_pCharacter = new(m_ClientID) CModCharacter();
	m_pCharacter->OnSpawn(this);
}

void CModPlayer::OnDeath()
{
	if (m_pCharacter)
		m_pCharacter->OnDeath();
}

void CModPlayer::OnSnap(int SnappingClient, CNetObj_PlayerInfo *pPlayerInfo)
{

}

void CModPlayer::OnSnap(int SnappingClient, CNetObj_SpectatorInfo *pSpectatorInfo)
{

}

#endif
