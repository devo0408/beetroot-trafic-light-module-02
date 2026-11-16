//
// Created by Denys Vovk on 11.11.2026.
//

#ifndef BEETROOT_TRAFIC_LIGHT_MODULE_02_TRAFFIC_LIGHT_H
#define BEETROOT_TRAFIC_LIGHT_MODULE_02_TRAFFIC_LIGHT_H

#include "main.h"

void traffic_light_init(TIM_HandleTypeDef *phase_timer, TIM_HandleTypeDef *lamp_timer);

void traffic_light_on_phase_end(void);

#endif //BEETROOT_TRAFIC_LIGHT_MODULE_02_TRAFFIC_LIGHT_H
