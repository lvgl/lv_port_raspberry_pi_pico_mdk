# lv_port_raspberry_pi_pico_mdk

An MDK template for Raspberry Pi Pico + LVGL:

- **"Comfortable Zone" for MCU developers**
  - **[MDK Community License](https://www.keil.com/pr/article/1299.htm)**: Arm has released a community license for open source community. It is free for non-commercial uses. **No limitations on code size or debug**.  
  - **The Latest Arm Compiler 6**: Using the state of art compiler, i.e. the Arm Compiler 6 for Raspberry Pi Pico instead of using the "just-so-so" arm-gcc. 
  - **Debug in MDK without Extra-Pico**: [Using CMSIS-DAP](https://github.com/majbthrd/pico-debug) (Validated in MDK and **highly recommended**)

- **Support the latest pico-sdk (v1.3.0)**
- **Support the latest LVGL**: Using CMSIS-Pack for deployment.
- **Various project configurations:**
  - [**AC6-flash**] Running code in Flash (XIP)
  - [**AC6-RunInSRAM**] Running code in SRAM (code is still stored in FLASH)
  - [**AC6-DebugInSRAM**] "no_flash" mode in the original pico-sdk. It is suitable for MDK debug.
  - [**AC6-DebugInSRAM-printf**] same as [**AC6-DebugInSRAM**] but retargeting printf to 'Debug (printf) Viewer' inside MDK.

