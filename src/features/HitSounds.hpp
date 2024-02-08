#pragma once

#include "../sacommon.hpp"
#include "../config/Config.hpp"
#include "Misc.h"

namespace SussyAim
{
    namespace Features
    {
        namespace HitSounds
        {
            inline int previousTotalHits = 0;

            void run(const CEntity &aLocalPlayer) noexcept
            {
                std::string soundDir = SussyAim::Cfg::dirSounds + "Hit.wav";
                std::wstring sound = Misc::STR2LPCWSTR(soundDir);

                uintptr_t pBulletServices;
                int totalHits;
                ProcessMgr.ReadMemory(aLocalPlayer.Pawn.Address + Offset::Pawn.BulletServices, pBulletServices);
                ProcessMgr.ReadMemory(pBulletServices + Offset::Pawn.TotalHit, totalHits);

                if (totalHits != previousTotalHits)
                {
                    if (!(totalHits == 0 && previousTotalHits != 0))
                    {
                        PlaySoundW(sound.c_str(), NULL, SND_FILENAME | SND_ASYNC);
                    }
                }
                previousTotalHits = totalHits;
            }
        }
    }
}
