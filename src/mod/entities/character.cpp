/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#include "character.h"
#include "../controller.h"
#include <game/server/gamecontext.h>
#include <game/server/player.h>
#include <game/server/entities/character.h>

#ifdef MOD

MACRO_ALLOC_POOL_ID_IMPL(CModCharacter, MAX_CLIENTS)

CGameContext *CModCharacter::GameServer() { return MOD->GameServer(); }
IGameController *CModCharacter::GameController() { return MOD->GameController(); }
IServer *CModCharacter::Server() { return MOD->Server(); }


CModCharacter::CModCharacter()
{
	m_pPlayer = 0;
	m_pGameChr = 0;
}

CModCharacter::~CModCharacter()
{
	// Nothing to clean...
}

void CModCharacter::OnSpawn(CModPlayer *pPlayer)
{
	m_pPlayer = pPlayer;
	m_pGameChr = GameServer()->GetPlayerChar(m_pPlayer->GetCID());
}

void CModCharacter::OnDeath()
{

}

void CModCharacter::Tick()
{
	
}

void CModCharacter::OnSnap(int SnappingClient, CNetObj_Character *pCharacter)
{

}

#endif
