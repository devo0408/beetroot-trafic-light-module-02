//
// Created by Denys Vovk on 11.11.2026.
//
#include "components/traffic_light.h"
#include "components/phase.h"

#define PHASE_TICKS_PER_SECOND 10000u  // TIM2: 96 MHz / (9599 + 1)

#define LAMP_RED    TIM_CHANNEL_1
#define LAMP_YELLOW TIM_CHANNEL_2
#define LAMP_GREEN  TIM_CHANNEL_3

static TIM_HandleTypeDef *phase_timer;
static TIM_HandleTypeDef *lamp_timer;

static uint8_t current_phase;

static uint32_t lamp_duty(bool on, bool blinking)
{
  uint32_t period = __HAL_TIM_GET_AUTORELOAD(lamp_timer) + 1;

  if (!on)
    return 0;

  return blinking ? period / 2 : period;
}

static uint8_t next_phase(uint8_t index)
{
  return (index + 1) % PHASE_COUNT;
}

static void enter_phase(uint8_t index)
{
  const struct Phase *phase = &phases[index];
  current_phase = index;

  __HAL_TIM_SET_COUNTER(lamp_timer, 0);
  __HAL_TIM_SET_COMPARE(lamp_timer, LAMP_RED, lamp_duty(phase->red, phase->is_blinking));
  __HAL_TIM_SET_COMPARE(lamp_timer, LAMP_YELLOW, lamp_duty(phase->yellow, phase->is_blinking));
  __HAL_TIM_SET_COMPARE(lamp_timer, LAMP_GREEN, lamp_duty(phase->green, phase->is_blinking));
  
  bool pedestrians_go = phase->red && !phase->yellow;
  HAL_GPIO_WritePin(PEDESTRIANS_GREEN_GPIO_Port, PEDESTRIANS_GREEN_Pin, pedestrians_go);
  HAL_GPIO_WritePin(PEDESTRIANS_RED_GPIO_Port, PEDESTRIANS_RED_Pin, !pedestrians_go);

  // Phase duration: the phase timer reloads (and interrupts) when it ends
  __HAL_TIM_SET_AUTORELOAD(phase_timer, phase->seconds * PHASE_TICKS_PER_SECOND - 1);
  __HAL_TIM_SET_COUNTER(phase_timer, 0);
}

void traffic_light_init(TIM_HandleTypeDef *phase_tim, TIM_HandleTypeDef *lamp_tim)
{
  phase_timer = phase_tim;
  lamp_timer = lamp_tim;

  HAL_TIM_PWM_Start(lamp_timer, LAMP_RED);
  HAL_TIM_PWM_Start(lamp_timer, LAMP_YELLOW);
  HAL_TIM_PWM_Start(lamp_timer, LAMP_GREEN);

  enter_phase(0);

  __HAL_TIM_CLEAR_FLAG(phase_timer, TIM_FLAG_UPDATE);

  HAL_TIM_Base_Start_IT(phase_timer);
}

void traffic_light_on_phase_end(void)
{
  enter_phase(next_phase(current_phase));
}
