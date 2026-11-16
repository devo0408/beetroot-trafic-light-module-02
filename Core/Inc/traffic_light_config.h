//
// Created by Denys Vovk on 11.11.2026.
//

#ifndef BEETROOT_TRAFIC_LIGHT_MODULE_02_TRAFFIC_LIGHT_CONFIG_H
#define BEETROOT_TRAFIC_LIGHT_MODULE_02_TRAFFIC_LIGHT_CONFIG_H

// Each phase durations, in seconds
#define GREEN_SECONDS           30
#define GREEN_BLINKING_SECONDS   3
#define YELLOW_SECONDS           2
#define RED_SECONDS             30
#define RED_YELLOW_SECONDS       1

// Vehicles keep green at least this long after a pedestrian press, in seconds
#define GREEN_AFTER_PRESS_SECONDS 10

// Pedestrian button debounce
#define DEBOUNCE_MS             30u

#endif //BEETROOT_TRAFIC_LIGHT_MODULE_02_TRAFFIC_LIGHT_CONFIG_H
