/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#include "modplayer.h"
#include "modcontroller.h"
#include <game/server/gamecontext.h>
#include <game/server/player.h>
#include <game/server/entities/character.h>

MACRO_ALLOC_POOL_ID_IMPL(CModPlayer, MAX_CLIENTS)


CModPlayer::CModPlayer(int ClientID, CGameContext *pGameServer)
{
	m_ClientID = ClientID;
	m_pGameServer = pGameServer;
	m_pCharacter = 0;
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
	m_pCharacter = new(m_ClientID) CModCharacter(m_pGameServer);
	m_pCharacter->OnSpawn(this);
}

void CModPlayer::OnDeath()
{
	if (m_pCharacter)
		m_pCharacter->OnDeath();
}

void CModPlayer::OnSnap(CNetObj_PlayerInfo *pPlayerInfo)
{

}

void CModPlayer::OnSnap(CNetObj_SpectatorInfo *pSpectatorInfo)
{

}
