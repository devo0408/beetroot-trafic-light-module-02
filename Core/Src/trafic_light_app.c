//
// Created by Denys Vovk on 13.11.2026.
//

#include "traffic_light_app.h"
#include "components/pedestrian_button.h"
#include "components/phase_switch.h"
#include "components/traffic_light.h"

void trafic_light_app_start(TIM_HandleTypeDef *phase_tim, TIM_HandleTypeDef *lamp_tim)
{
    traffic_light_init(phase_tim, lamp_tim);

    phase_switch_init(phase_tim);
}

void trafic_light_app_update(void)
{
    if (pedestrian_button_pressed())
    {
        traffic_light_request_pedestrian();
    }
}
