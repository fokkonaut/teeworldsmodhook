/* (c) fokkonaut. See licence.txt in the root of the distribution for more information. */
#include "controller.h"

#include <game/server/gamecontext.h>
#include <game/server/entities/character.h>
#include <game/server/player.h>
#include <engine/shared/config.h>

#ifdef MOD

IGameController *CModController::GameController() { return GameServer()->m_pController; }
IServer *CModController::Server() { return GameServer()->Server(); }

CModController *g_pMod;


CModController::CModController(CGameContext *pGameServer)
{
	m_pGameServer = pGameServer;
	m_pServer = pGameServer->Server();
	m_pGameController = pGameServer->m_pController;

	for (int i = 0; i < MAX_CLIENTS; i++)
		m_apPlayers[i] = 0;

	// Always force gametype to "mod" when MOD is defined
	str_copy(GameServer()->Config()->m_SvGametype, "mod", sizeof(GameServer()->Config()->m_SvGametype));
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

void CModController::InitPlayer(int ClientID)
{
	m_apPlayers[ClientID] = new(ClientID) CModPlayer(ClientID);
}

void CModController::DeletePlayer(int ClientID)
{
	delete m_apPlayers[ClientID];
	m_apPlayers[ClientID] = 0;
}

void CModController::Tick()
{

}

void CModController::SendChatTarget(int To, const char *pText)
{
	CNetMsg_Sv_Chat Msg;
	Msg.m_Mode = CHAT_ALL;
	Msg.m_ClientID = -1;
	Msg.m_pMessage = pText;
	Msg.m_TargetID = -1;
	Server()->SendPackMsg(&Msg, MSGFLAG_VITAL, To);
}

void CModController::SendMotd(int To, const char *pText)
{
	CNetMsg_Sv_Motd Msg;
	Msg.m_pMessage = pText;
	Server()->SendPackMsg(&Msg, MSGFLAG_VITAL, To);
}

int CModController::GetCIDByName(const char *pName)
{
	for (int i = 0; i < MAX_CLIENTS; i++)
		if (m_apPlayers[i] && !str_comp(pName, Server()->ClientName(i)))
			return i;
	return -1;
}

void CModController::CreateSoundGlobal(int Sound)
{
	for (int i = 0; i < MAX_CLIENTS; i++)
		if (m_apPlayers[i])
			CreateSoundPlayer(Sound, i);
}

void CModController::CreateSoundPlayer(int Sound, int ClientID)
{
	GameServer()->CreateSound(GameServer()->m_apPlayers[ClientID]->m_ViewPos, Sound, CmaskOne(ClientID));
}

void CModController::CreateSoundPlayerAt(vec2 Pos, int Sound, int ClientID)
{
	GameServer()->CreateSound(Pos, Sound, CmaskOne(ClientID));
}

void CModController::OnClientEnter(int ClientID)
{
	
}

void CModController::OnClientDrop(int ClientID)
{

}

#endif
