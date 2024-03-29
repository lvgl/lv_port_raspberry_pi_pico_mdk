/****************************************************************************
*  Copyright 2021 Gorgon Meducer (Email:embedded_zhuoran@hotmail.com)       *
*                                                                           *
*  Licensed under the Apache License, Version 2.0 (the "License");          *
*  you may not use this file except in compliance with the License.         *
*  You may obtain a copy of the License at                                  *
*                                                                           *
*     http://www.apache.org/licenses/LICENSE-2.0                            *
*                                                                           *
*  Unless required by applicable law or agreed to in writing, software      *
*  distributed under the License is distributed on an "AS IS" BASIS,        *
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
*  See the License for the specific language governing permissions and      *
*  limitations under the License.                                           *
*                                                                           *
****************************************************************************/
/*============================ INCLUDES ======================================*/
#include "pico/stdlib.h"
#include "perf_counter.h"


#include "DEV_Config.h"
#include "LCD_1In3.h"
#include "GLCD_Config.h"
#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"
#include "demos/lv_demos.h"


#include <stdio.h>

#include "RTE_Components.h"
#if defined(RTE_Compiler_EventRecorder) && defined(USE_EVR_FOR_STDOUR)
#   include <EventRecorder.h>
#endif

#if defined(RTE_Script_PikaScript)
#   include "pikascript.h"
#endif


/*============================ MACROS ========================================*/
#define TOP         (0x1FFF)

/*============================ MACROFIED FUNCTIONS ===========================*/
#define ABS(__N)    ((__N) < 0 ? -(__N) : (__N))
#define _BV(__N)    ((uint32_t)1<<(__N))



/*============================ TYPES =========================================*/
/*============================ GLOBAL VARIABLES ==============================*/
/*============================ LOCAL VARIABLES ===============================*/
/*============================ PROTOTYPES ====================================*/
/*============================ IMPLEMENTATION ================================*/

void SysTick_Handler(void)
{

}

/*! \brief set the 16-level led gradation
 *! \param hwLevel gradation
 *! \return none
 */
static void set_led_gradation(uint16_t hwLevel)
{
    static uint16_t s_hwCounter = 0;
    
    if (hwLevel >= s_hwCounter) {
        gpio_put(PICO_DEFAULT_LED_PIN, 1);
    } else {
        gpio_put(PICO_DEFAULT_LED_PIN, 0);
    }
    
    s_hwCounter++;
    s_hwCounter &= TOP;
}

static void breath_led(void)
{
    static uint16_t s_hwCounter = 0;
    static int16_t s_nGray = (TOP >> 1);
    
    s_hwCounter++;
    if (!(s_hwCounter & (_BV(10)-1))) {
        s_nGray++; 
        if (s_nGray == TOP) {
            s_nGray = 0;
        }
    }
    
    set_led_gradation(ABS(s_nGray - (TOP >> 1)));
}

static void system_init(void)
{
    extern void SystemCoreClockUpdate();

    SystemCoreClockUpdate();
    /*! \note if you do want to use SysTick in your application, please use 
     *!       init_cycle_counter(true); 
     *!       instead of 
     *!       init_cycle_counter(false); 
     */
    init_cycle_counter(false);

#if defined(RTE_Compiler_EventRecorder) && defined(USE_EVR_FOR_STDOUR)
    EventRecorderInitialize(0, 1);
#endif

    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

    DEV_Delay_ms(100);

    if(DEV_Module_Init()!=0){
        //assert(0);
    }
   
    DEV_SET_PWM(50);
    /* LCD Init */
    
    LCD_1IN3_Init(HORIZONTAL);
    LCD_1IN3_Clear(GLCD_COLOR_BLUE);
    
    for (int n = 0; n < KEY_NUM; n++) {
        dev_key_init(n);
    }
}

#if LV_USE_DEMO_BENCHMARK && LVGL_VERSION_MAJOR == 8
static void on_benchmark_finished(void)
{
    disp_enable_update();
}
#endif


int main(void)
{
    system_init();
    
    printf("LVGL+Arm-2D for Pico\r\n");
    
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();

#if defined(RTE_Script_PikaScript)
    pikaScriptInit();
#endif

/* We have no sufficient SRAM to run those demos in all-in-ram mode*/
#if !defined(PICO_NO_FLASH)
#   if LV_USE_DEMO_BENCHMARK

#       if  LVGL_VERSION_MAJOR == 8
    //disp_disable_update();
    //lv_demo_benchmark_set_finished_cb(on_benchmark_finished);
    //lv_demo_benchmark_set_max_speed(true);
    lv_demo_benchmark();
    //lv_demo_benchmark_run_scene(31);
#       elif    LVGL_VERSION_MAJOR == 9
    lv_demo_benchmark(LV_DEMO_BENCHMARK_MODE_RENDER_ONLY);
    
    //lv_demo_benchmark_run_scene(LV_DEMO_BENCHMARK_MODE_RENDER_AND_DRIVER, 26*2-1);      // run scene no 31
#       endif
    
#   elif LV_USE_DEMO_WIDGETS
    lv_demo_widgets();
#   endif
#endif
    
    while(1) {
        lv_timer_handler();
    }
    
}