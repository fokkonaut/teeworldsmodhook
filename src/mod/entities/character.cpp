/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#include "character.h"
#include "../controller.h"
#include <game/server/gamecontext.h>
#include <game/server/player.h>
#include <game/server/entities/character.h>

MACRO_ALLOC_POOL_ID_IMPL(CModCharacter, MAX_CLIENTS)

CGameContext *CModCharacter::GameServer() { return MOD->GameServer(); }
IGameController *CModCharacter::GameController() { return MOD->GameController(); }
IServer *CModCharacter::Server() { return MOD->Server(); }


CModCharacter::CModCharacter()
{

}

CModCharacter::~CModCharacter()
{
	// Nothing to clean...
}

void CModCharacter::OnSpawn(CModPlayer *pPlayer)
{
	m_pPlayer = pPlayer;
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
