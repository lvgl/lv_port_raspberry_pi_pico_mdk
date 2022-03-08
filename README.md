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





## How to Use

### 1. Get the project template

I assume that you have the MDK installed on your PC. You can obtained [a free community license here](https://www.keil.com/pr/article/1299.htm). Please clone the project template with following command line:

```
mkdir pico-mdk
cd pico-mdk

git clone https://github.com/lvgl/lv_port_raspberry_pi_pico_mdk.git .

git submodule update --remote --init
```



### 2. Install cmsis-pack(s)

#### 2.1 LVGL cmsis-pack

For ease of use, we deploy the LVGL to the project template using the the LVGL cmsis-pack. If you haven't installed it, you can always find the latest version from [here](https://github.com/lvgl/lvgl/tree/master/env_support/cmsis-pack). Once you download it, please double click to install. Just following the step by step guidance, piece of cake. 



#### 2.2 perf_counter cmsis-pack

This project template use a module called `perf_counter` to facilitate the LVGL porting and usage. It is also deployed with a cmsis-pack for the ease of use. If you haven't install it, you can find it from the `cmsis-pack` folder. 



#### 2.3 Updating installed cmsis-pack in the future

The aforementioned cmsis-packs are updated regularly, for example, the LVGL cmsis-pack is updated in monthly manner. Once installed, you don't have to check the LVGL repo and download the latest cmsis-pack manually. Instead, you can open the `pack-installer` from MDK, select menu `Packs->Check for Updates` and see whether there are any updates on those cmsis-packs. 



###### The LVGL cmsis-pack in Pack-installer

![image-20220308125918481](./documents/Pictures/LVGL)



###### The perf_counter cmsis-pack in Pack installer

![image-20220308125743517](./documents/Pictures/perf_counter)



### 3. About the project templates

This LVGL porting project is derived from a open-source project call [Pico-Template](https://github.com/GorgonMeducer/Pico_Template). For any questions about the project template, such as:

- How to Debug
- How to set stack size and heap size
- How to choose different project configurations for different scenarios.
- How to use Printf
- How to retarget stdout and stdin 
- etc.

Please refer to the original [Pico-Template](https://github.com/GorgonMeducer/Pico_Template) for help. Or you can find a [readme](./project/mdk/readme.md) in the `project/mdk` folder. 



### 4. About the LVGL 

#### 4.1 LVGL components management

Since the LVGL is deployed using the cmsis-pack, it is managed in the **RTE (Run-Time-Environment)** window, as shown below. You can open this window from the menu: `Project->Manage->Run-Time-Environment`.



###### LVGL in RTE window

![image-20220308131303691](./documents/Pictures/RTE_LVGL.png) 



