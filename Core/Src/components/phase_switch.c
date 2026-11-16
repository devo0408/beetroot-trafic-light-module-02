//
// Created by Denys Vovk on 16.11.2026.
//

#include "components/phase_switch.h"
#include "components/traffic_light.h"


static TIM_HandleTypeDef *phase_timer;

void phase_switch_init(TIM_HandleTypeDef *phase_tim)
{
    phase_timer = phase_tim;
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim == phase_timer)
    {
        traffic_light_on_phase_end();
    }
}
