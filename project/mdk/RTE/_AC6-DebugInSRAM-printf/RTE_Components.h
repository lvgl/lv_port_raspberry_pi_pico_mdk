
/*
 * Auto generated Run-Time-Environment Configuration File
 *      *** Do not modify ! ***
 *
 * Project: 'template' 
 * Target:  'AC6-DebugInSRAM-printf' 
 */

#ifndef RTE_COMPONENTS_H
#define RTE_COMPONENTS_H


/*
 * Define the Device Header File: 
 */
#define CMSIS_device_header "ARMCM0plus_MPU.h"

/* GorgonMeducer.Performance Counter::Utilities:perf_counter:Core:Library:1.9.2 */
#define __PERF_COUNTER__
/* Keil.ARM Compiler::Compiler:Event Recorder:DAP:1.4.0 */
#define RTE_Compiler_EventRecorder
          #define RTE_Compiler_EventRecorder_DAP
/* Keil.ARM Compiler::Compiler:I/O:STDIN:User:1.2.0 */
#define RTE_Compiler_IO_STDIN           /* Compiler I/O: STDIN */
          #define RTE_Compiler_IO_STDIN_User      /* Compiler I/O: STDIN User */
/* Keil.ARM Compiler::Compiler:I/O:STDOUT:EVR:1.2.0 */
#define RTE_Compiler_IO_STDOUT          /* Compiler I/O: STDOUT */
          #define RTE_Compiler_IO_STDOUT_EVR      /* Compiler I/O: STDOUT EVR */
/* LVGL.LVGL::LVGL:lvgl:Benchmark:8.3.0-dev */
/*! \brief enable demo:bencharmk */
#define LV_USE_DEMO_BENCHMARK         1
/* LVGL.LVGL::LVGL:lvgl:Essential:8.3.0-dev */
/*! \brief Enable LVGL */
#define RTE_GRAPHICS_LVGL
/* LVGL.LVGL::LVGL:lvgl:Extra Themes:8.3.0-dev */
/*! \brief use extra themes, widgets and layouts */
#define RTE_GRAPHICS_LVGL_USE_EXTRA_THEMES


#endif /* RTE_COMPONENTS_H */
