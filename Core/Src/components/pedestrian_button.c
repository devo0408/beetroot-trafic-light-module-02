//
// Created by Denys Vovk on 16.11.2026.
//

#include "main.h"
#include "components/pedestrian_button.h"
#include "traffic_light_config.h"

#define BUTTON_PRESSED  GPIO_PIN_RESET
#define BUTTON_RELEASED GPIO_PIN_SET

static GPIO_PinState stable_state = BUTTON_RELEASED;
static GPIO_PinState last_raw_state = BUTTON_RELEASED;

static uint32_t last_change_ms;

bool pedestrian_button_pressed(void)
{
  GPIO_PinState raw = HAL_GPIO_ReadPin(PEDESTRIANS_BUTTON_GPIO_Port, PEDESTRIANS_BUTTON_Pin);
  uint32_t now = HAL_GetTick();

  if (raw != last_raw_state)
  {
    last_raw_state = raw;
    last_change_ms = now;
    return false;
  }

  if (raw != stable_state && now - last_change_ms >= DEBOUNCE_MS)
  {
    stable_state = raw;
    return stable_state == BUTTON_PRESSED;
  }

  return false;
}
