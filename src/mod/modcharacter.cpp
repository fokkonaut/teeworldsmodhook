/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#include "modcharacter.h"
#include "modcontroller.h"
#include <game/server/gamecontext.h>
#include <game/server/player.h>
#include <game/server/entities/character.h>

MACRO_ALLOC_POOL_ID_IMPL(CModCharacter, MAX_CLIENTS)


CModCharacter::CModCharacter(CGameContext *pGameServer)
{
	m_pGameServer = pGameServer;
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

void CModCharacter::OnSnap(CNetObj_Character *pCharacter)
{

}
